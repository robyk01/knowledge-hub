/* servTCPConcTh2.c - Exemplu de server TCP concurent care deserveste clientii
   prin crearea unui thread pentru fiecare client.
   Asteapta un numar de la clienti si intoarce clientilor numarul incrementat.
	Intoarce corect identificatorul din program al thread-ului.
   Autor: Lenuta Alboaie  <adria@info.uaic.ro> (c)
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
/* portul folosit */
#define PORT 2908
/* codul de eroare returnat de anumite apeluri */
extern int errno;
typedef struct thData{
	int idThread; //id-ul thread-ului tinut in evidenta de acest program
	int cl; //descriptorul intors de accept
}thData;
static void *treat(void *); /* functia executata de fiecare thread ce realizeaza comunicarea cu clientii */
void raspunde(struct thData*);
int main ()
{
  struct sockaddr_in server;	// structura folosita de server
  struct sockaddr_in from;	
  int nr;		//mesajul primit de trimis la client
  int sd;		//descriptorul de socket
  int pid;
  pthread_t th[100];    //Identificatorii thread-urilor care se vor crea
	int i=0;
  /* crearea unui socket */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("[server]Eroare la socket().\n");
      return errno;
    }
  /* utilizarea optiunii SO_REUSEADDR */
  int on=1;
  setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
  /* pregatirea structurilor de date */
  bzero (&server, sizeof (server));
  bzero (&from, sizeof (from));
  /* umplem structura folosita de server */
  /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;	
  /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
  /* utilizam un port utilizator */
    server.sin_port = htons (PORT);
  /* atasam socketul */
  if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
      perror ("[server]Eroare la bind().\n");
      return errno;
    }
  /* punem serverul sa asculte daca vin clienti sa se conecteze */
  if (listen (sd, 2) == -1)
    {
      perror ("[server]Eroare la listen().\n");
      return errno;
    }
  /* servim in mod concurent clientii...folosind thread-uri */
  while (1)
    {
      int client;
      thData * td; //parametru functia executata de thread
      int length = sizeof (from);
      printf ("[server]Asteptam la portul %d...\n",PORT);
      fflush (stdout);
      // client= malloc(sizeof(int));
      /* acceptam un client (stare blocanta pina la realizarea conexiunii) */
      if ( (client = accept (sd, (struct sockaddr *) &from, &length)) < 0)
	{
	  perror ("[server]Eroare la accept().\n");
	  continue;
	}
        /* s-a realizat conexiunea, se astepta mesajul */
	// int idThread; //id-ul threadului
	// int cl; //descriptorul intors de accept
	td=(struct thData*)malloc(sizeof(struct thData));	
	td->idThread=i++;
	td->cl=client;
	pthread_create(&th[i], NULL, &treat, td);	
	}//while
};				
static void *treat(void * arg)
{		
		struct thData tdL;
		tdL= *((struct thData*)arg);
        free(arg);	
		printf ("[thread]- %d - Asteptam mesajul...\n", tdL.idThread);
		fflush (stdout);		
		pthread_detach(pthread_self());		
		raspunde(&tdL);
		/* am terminat cu acest client, inchidem conexiunea */
		close (tdL.cl);
		return(NULL);	
};

void raspunde(struct thData* tdL)
{
    int nr, i=0;
    char* filename = NULL;
    char* msg = NULL;

    int filename_len = 0;
    if (read(tdL->cl, &filename_len, sizeof(int)) != sizeof(int)) {
        perror("[Thread]Eroare la read() filename_len.\n");
        return;
    }

    if (filename_len <= 0 || filename_len > 4096) {
        fprintf(stderr, "[Thread %d] filename_len invalid: %d\n",
                tdL->idThread, filename_len);
        return;
    }

    filename = malloc(filename_len + 1);
    if (read (tdL->cl, filename, filename_len) <= 0)
    {
        printf("[Thread %d]\n",tdL->idThread);
        perror ("Eroare la read() de la client.\n");
        free(filename);
        return;
    }
    filename[filename_len] = '\0';

    printf ("[Thread %d]Mesajul a fost receptionat...%s\n",tdL->idThread, filename);

    /*pregatim mesajul de raspuns */
    int fd = open(filename, O_RDONLY);
    if (fd < 0) { 
        perror("[Thread]Eroare la open() fisier.\n");
        free(filename);
        return;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) < 0) {
        perror("[Thread]Eroare la fstat().\n");
        close(fd);
        free(filename);
        return;
    }

    int file_size = (int)file_stat.st_size;
    if (file_size < 0) {
        close(fd);
        free(filename);
        return;
    }

    if (write(tdL->cl, &file_size, sizeof(int)) != sizeof(int)) {
        perror("[Thread]Eroare la write() file_size.\n");
        close(fd);
        free(filename);
        return;
    }

    msg = malloc(file_size + 1);
    if (!msg) {
        close(fd);
        free(filename);
        return;
    }

    if (read(fd, msg, file_size) != file_size) {
        perror("[Thread]Eroare la read() fisier.\n");
        close(fd);
        free(filename);
        free(msg);
        return;
    }

    msg[file_size] = '\0';

    printf("[Thread %d]Trimitem mesajul inapoi...%s\n",tdL->idThread, msg);

    /* returnam mesajul clientului */
    if (write (tdL->cl, msg, file_size) <= 0)
    {
        printf("[Thread %d] ",tdL->idThread);
        perror ("[Thread]Eroare la write() catre client.\n");
    }
    else
        printf ("[Thread %d]Mesajul a fost trasmis cu succes.\n",tdL->idThread);	

    free(filename); 
    free(msg);   
    close(fd);
}
