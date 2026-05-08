#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define ASCII_SET_SIZE 256

int main(int argc, char* argv[]){
    char nume_fisier[PATH_MAX];

    if (argc == 1){
        printf("Dati numele fisierului de prelucrat: ");
        scanf("%s", nume_fisier);
    } else {
        strcpy(nume_fisier, argv[1]);
    }

    unsigned int vector_ap[ASCII_SET_SIZE];
    for (int i = 0; i < ASCII_SET_SIZE; i++){
        vector_ap[i] = 0;
    }

    int fd;
    fd = open(nume_fisier, O_RDONLY); 
    if (fd == -1){
        perror("Eroare la deschiderea fisierului de intrare");
        exit(2);
    }

    unsigned char ch;
    int cod_r;

    do{
        cod_r = read(fd, &ch, 1);

        if (cod_r == -1){
            perror("Eroare la citirea fisierului");
            exit(3);
        }
        if (cod_r == 0){
            break;
        }

        vector_ap[ch]++;
    } while(1);

    if (close(fd) == -1){
        perror("Eroare la inchidere fisier");
        exit(4);
    }

    for (int i = 0; i < ASCII_SET_SIZE; i++){
        if (vector_ap[i] != 0){
            printf("Caracterul %c cu codul ASCII %d apare de %d ori.\n", i, i, vector_ap[i]);
        }
    }

    return 0;
}

// gcc -o AsciiStatistics AsciiStatistics.c
// ./AsciiStatistics