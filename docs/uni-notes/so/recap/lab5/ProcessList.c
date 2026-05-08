#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

// ./a 15
// 15 processes - P1 -> P2 -> .. -> Pn

int main(int argc, char* argv[]){
    int N;
    pid_t pid;

    if (argc == 1){
        if (scanf("%d", &N) != 1 || N < 1){
            fprintf(stderr, "Eroare: N nu e pozitiv intreg");
            exit(1);
        }
    } else {
        if (sscanf(argv[1], "%d", &N) != 1 || N < 1){
            fprintf(stderr, "Eroare: N specificat nu e pozitiv intreg");
            exit(2);
        }
    }

    printf("Sunt procesul initial cu PID %d, parintele meu are procesul PPID %d.\n", getpid(), getppid());

    for (int i = 0; i < N - 1; i++){
        pid = fork();

        if (pid == -1){
            perror("Eroare la fork");
            exit(3);
        }

        if (pid > 0){
            printf("Sunt procesul parinte cu PID %d, am creat procesul %d.\n", getpid(), pid);
            break;
        }

        printf("Sunt procesul fiul al lui %d, cu PID %d.\n", getppid(), getpid());
    }

    wait(NULL);
    return 0;
}