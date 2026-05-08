#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char* argv[]){
    char fisier_intrare[PATH_MAX];
    char fisier_iesire[PATH_MAX];
    char c1, c2;

    if (argc == 1){
        printf("Numele fisierului de intrare: ");
        scanf("%s", fisier_intrare);

        printf("Numele fisierului de iesire: ");
        scanf("%s", fisier_iesire);

        printf("Caracterul de inlocuit: ");
        scanf(" %c", &c1);

        printf("Caracterul cu care se inlocuieste: ");
        scanf(" %c", &c2);
    } else {
        strcpy(fisier_intrare, argv[1]);
        strcpy(fisier_iesire, argv[2]);
        c1 = *argv[3];
        c2 = *argv[4];
    }

    if (strcmp(fisier_intrare, fisier_iesire) == 0){
        fprintf(stderr, "Eroare: Fisierele coincid\n");  
        exit(4);
    }

    int fd_in;
    fd_in = open(fisier_intrare, O_RDONLY);
    if (fd_in == -1){
        perror("Eroare la deschidere");
        exit(1);
    }

    int fd_out;
    fd_out = open(fisier_iesire, O_WRONLY | O_CREAT | O_TRUNC, 0600);

    unsigned char ch;
    int cod_r, cod_w;
    do{
        cod_r = read(fd_in, &ch, 1);

        if (cod_r == -1){
            perror("Eroare la citire");
            exit(2);
        }
        if (cod_r == 0) break;

        if (ch == c1) cod_w = write(fd_out, &c2, 1);
        else cod_w = write(fd_out, &ch, 1);

        if (cod_w == -1){
            perror("Eroare la scriere");
            exit(3);
        }

    } while(1);

    close(fd_in);
    close(fd_out);

    return 0;
}

