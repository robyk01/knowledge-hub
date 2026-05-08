#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <limits.h>

#define ASCII_SET_SIZE 256

int main(int argc, char* argv[]){
    if (argc < 5) {
        printf("Utilizare: %s fisier1 <isier2 char1 char2\n", argv[0]);
        exit(1);
    }

    char *f_in = argv[1];
    char *f_out = argv[2];
    char c_vechi = argv[3][0];
    char c_nou = argv[4][0];

    if (strcmp(f_in, f_out) == 0){
        printf("Eroare, acelasi nume de fisier");
        exit(2);
    }

    int fd_in = open(f_in, O_RDONLY);
    if (fd_in == -1){
        perror("Eroare la deschiderea fisierului");
        exit(3);
    }

    int fd_out = open(f_out, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);

    if (fd_out == -1 && errno == EEXIST){
        char raspuns;
        printf("Fisierul exista deja, suprascrieti?");
        scanf(" %c", &raspuns);

        if (raspuns == 'y'){
            fd_out = open(f_out, O_WRONLY | O_TRUNC);
        } else {
            printf("Operatie anulata");
            close(fd_in);
            exit(0);
        }
    }

    char buffer;

    while (read(fd_in, &buffer, 1) > 0){
        if (buffer == c_vechi){
            buffer = c_nou;
        }

        write(fd_out, &buffer, 1);
    }

    close(fd_in);
    close(fd_out);
    return 0;
}