#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

// ./MyHead -n 15 file.txt

int main(int argc, char* argv[]){
    if (argc == 1){
        printf("Parametrii nespecificati");
        exit(1);
    }

    int n = 10, c = 10, mode = 1;

    char nume_fisier[PATH_MAX];

    if (argv[1][0] == '-'){
        if (strcmp(argv[1], "-n") == 0){
            n = atoi(argv[2]);
            mode = 1;
        } else {
            c = atoi(argv[2]);
            mode = 0;
        }
        strcpy(nume_fisier, argv[3]);
    } else {
        mode = 1;
        strcpy(nume_fisier, argv[1]);
    }

    int fd;
    fd = open(nume_fisier, O_RDONLY);
    if (fd == -1){
        perror("Eroare la deschidere");
        exit(3);
    }

    char line[256];
    char bytes[256];
    unsigned char ch;
    int i = 0;
    int cod_r;

    while ((cod_r = read(fd, &ch, 1)) > 0){
        if (mode == 1){
            if (ch == '\n'){
                line[i] = '\0';
                printf("%s\n", line);
                n--;
                if (n == 0) break;
                i = 0;
            } else {
                if (i <= 255){
                    line[i++] = ch;
                }
            }
        } else {
            if (i <= 255){
                bytes[i++] = ch;
                c--;
                if (c == 0) break;
            }
        }
    }

    if (mode == 0){
        bytes[i] = '\0';
        printf("%s", bytes);
    }

    close(fd);

    return 0;

}