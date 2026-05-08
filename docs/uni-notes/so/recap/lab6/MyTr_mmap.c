#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/mman.h>
#include <sys/stat.h>

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

    //  fisier in 
    int fd_in;
    fd_in = open(fisier_intrare, O_RDONLY);
    if (fd_in == -1){
        perror("Eroare la deschidere");
        exit(1);
    }

    // mapare fisier in
    struct stat st;
    if (fstat(fd_in, &st) == -1){
        perror("Eroare la stat");
        exit(0);
    }
    int file_size = st.st_size;

    char* mapped_in = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd_in, 0);
    if (mapped_in == MAP_FAILED){
        perror("Eroare la mmap in");
        exit(5);
    }

    // fisier out
    int fd_out;
    fd_out = open(fisier_iesire, O_WRONLY | O_CREAT | O_TRUNC, 0600);

    if (ftruncate(fd_out, file_size) == -1){
        perror("Eroare la truncare");
        exit(6);
    }

    char* mapped_out = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd_out, 0);
    if (mapped_out == MAP_FAILED){
        perror("Eroare la mmap out");
        exit(7);
    }

    unsigned char ch;
    for (int i = 0; i < file_size; i++){
        ch = mapped_in[i];

        if (ch == c1){
            mapped_out[i] = c2;
        } else mapped_out[i] = ch;

    }

    munmap(mapped_in, file_size);
    munmap(mapped_out, file_size);

    close(fd_in);
    close(fd_out);

    return 0;
}

