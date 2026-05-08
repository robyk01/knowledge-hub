/* cliTCPIt.c - Exemplu de client TCP
   Trimite un numar la server; primeste de la server numarul incrementat.
   Autor: Lenuta Alboaie  <adria@info.uaic.ro> (c)
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <arpa/inet.h> 

/* codul de eroare returnat de anumite apeluri */
extern int errno;
/* portul de conectare la server*/
int port;
int main (int argc, char *argv[])
{
  int sd;			// descriptorul de socket
  struct sockaddr_in server;	// structura folosita pentru conectare
  		// mesajul trimis
  int nr=0;
  char buf[10];
  char* filename;
  char* msg;
  char* local_path;
  int file_size;
  /* exista toate argumentele in linia de comanda? */
  if (argc != 5)
    {
      printf ("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
      return -1;
    }
  /* stabilim portul */
  port = atoi (argv[2]);
  filename = malloc(strlen(argv[3]) + 1); 
  strcpy(filename, argv[3]);
  local_path = argv[4];
  /* cream socketul */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      return errno;
    }
  /* umplem structura folosita pentru realizarea conexiunii cu serverul */
  /* familia socket-ului */
  server.sin_family = AF_INET;
  /* adresa IP a serverului */
  server.sin_addr.s_addr = inet_addr(argv[1]);
  /* portul de conectare */
  server.sin_port = htons (port);
  /* ne conectam la server */
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
      perror ("[client]Eroare la connect().\n");
      return errno;
    }

  /* trimiterea mesajului la server */
  int filename_len = strlen(filename);
  write(sd, &filename_len, sizeof(int));
  write(sd, filename, filename_len);

  /* citire file size*/
  if (read (sd, &file_size, sizeof(int)) < 0)
    {
      perror ("[client]Eroare la read() de la server.\n");
      return errno;
    }

  msg = malloc(file_size + 1);

  /* citirea raspunsului dat de server
     (apel blocant pina cind serverul raspunde) */
  if (read (sd, msg, file_size) < 0)
    {
      perror ("[client]Eroare la read() de la server.\n");
      return errno;
    }
  msg[file_size] = '\0';

  int fd_server = open(local_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd_server < 0) {
    perror("[client]Eroare la open() pentru fisier local.\n");
    close(sd);
    return errno;
  }
  write(fd_server, msg, file_size);
  /* afisam mesajul primit */
  printf ("[client]Mesajul primit este: %s\n", msg);
  /* inchidem conexiunea, am terminat */
  close (sd);

  free(filename);
  free(msg);
  close(fd_server);
}
