#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  
#include <limits.h>  

#define ASCII_SET_SIZE 255

int main (int argc, char* argv[])
{  
    char nume_fisier[PATH_MAX];

    if(argc == 1)
    {
        // fprintf(stderr,"Argumente insuficiente! Specificati numele fisierului de prelucrat!");  exit(1);

        printf("Dati numele fisierului de prelucrat:");
        scanf("%s", nume_fisier);
    }
    else
    {
        strcpy(nume_fisier, argv[1]);
    }

    unsigned int vector_ap[ASCII_SET_SIZE], i;

    for(i = 0; i < ASCII_SET_SIZE; i++)
        vector_ap[i] = 0;


    int fd;

    fd = open(nume_fisier, O_RDONLY);
    if(fd == -1)
    {
        perror("Eroare la deschiderea fisierului de intrare");
        exit(2);
    }

    unsigned char ch;  
    int cod_r;

    do{
        cod_r = read(fd, &ch, 1);

        if(cod_r == -1)
        {
            perror("Eroare la citire");
            exit(3);
        }
        if(cod_r == 0)  
            break;

        vector_ap[ch]++;
    }
    while(1);

    if(close(fd) == -1)
    {
        perror("Eroare la inchidere");
        exit(4);
    }

    for(i = 0; i < ASCII_SET_SIZE; i++)
        if(vector_ap[i] != 0)
            printf("Caracterul %c cu codul ASCII %d apare de %d ori in fisier.\n", i, i, vector_ap[i]);

    return 0;
}
