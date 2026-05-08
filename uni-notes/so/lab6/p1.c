#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Utilizare: %s fisier_in fisier_out char_vechi char_nou\n", argv[0]);
        exit(1);
    }

    char *f_in = argv[1];
    char *f_out = argv[2];
    char c_vechi = argv[3][0];
    char c_nou = argv[4][0];

    if (strcmp(f_in, f_out) == 0) {
        fprintf(stderr, "Eroare: Fisierul de intrare si cel de iesire sunt identice.\n");
        exit(2);
    }

    int fd_in = open(f_in, O_RDONLY);
    if (fd_in == -1) {
        perror("Eroare la deschiderea fisierului de intrare");
        exit(3);
    }

    struct stat st;
    if (fstat(fd_in, &st) == -1) {
        perror("Eroare la fstat");
        exit(4);
    }
    int dimensiune = st.st_size;

    int fd_out = open(f_out, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_out == -1) {
        perror("Eroare la deschiderea fisierului de iesire");
        exit(5);
    }

    if (ftruncate(fd_out, dimensiune) == -1) {
        perror("Eroare la ftruncate");
        exit(6);
    }

    char *src = mmap(NULL, dimensiune, PROT_READ, MAP_PRIVATE, fd_in, 0);
    if (src == MAP_FAILED) {
        perror("Eroare la mmap intrare");
        exit(7);
    }

    char *dest = mmap(NULL, dimensiune, PROT_READ | PROT_WRITE, MAP_SHARED, fd_out, 0);
    if (dest == MAP_FAILED) {
        perror("Eroare la mmap iesire");
        exit(8);
    }

    close(fd_in);
    close(fd_out);

    for (int i = 0; i < dimensiune; i++) {
        if (src[i] == c_vechi) {
            dest[i] = c_nou;
        } else {
            dest[i] = src[i];
        }
    }

    munmap(src, dimensiune);
    munmap(dest, dimensiune);
   

    return 0;
}