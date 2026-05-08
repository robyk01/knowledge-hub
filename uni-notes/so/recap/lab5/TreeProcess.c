#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

// ./a
// (1,1) PID: x, PPID: y, PID ale copiilor: a, b, c, exit code: z
// P1 - P2.1, P2.2, P2.3, P2.4
// P2.1 - P3.1, P3.2, P3.3
// ..

int main(int argc, char* argv[]){
    pid_t pid;
    pid_t children[4];
    int status;

    for (int i = 1; i <= 4; i++){
        pid = fork();

        if (pid == -1){
            perror("Eroare la fork");
            exit(1);
        }

        if (pid == 0){
            pid_t grandchildren[3];

            for (int j = 1; j <= 3; j++){
                pid_t pid2;
                pid2 = fork();

                if (pid2 == -1){
                    perror("Eroare la fork");
                    exit(2);
                }

                if (pid2 == 0){
                    printf("(3,%d) PID: %d, PPID: %d, fii: -\n", j, getpid(), getppid());
                    exit(0);
                }

                if (pid2 > 0){
                    grandchildren[j - 1] = pid2;
                }
            }

            printf("(2,%d) PID: %d, PPID: %d, fii: ", i, getpid(), getppid());
            for (int j = 0; j < 3; j++){
                waitpid(grandchildren[j], &status, 0);
                printf("(%d,%d) ", grandchildren[j], WEXITSTATUS(status));
            }
            printf("\n");
            exit(0);
        }

        if (pid > 0){
            children[i - 1] = pid;
        }
    }

    printf("(1,1) PID: %d, PPID: %d, fii: ", getpid(), getppid());
    for (int i = 0; i < 4; i++){
        waitpid(children[i], &status, 0);
        printf("(%d,%d) ", children[i], WEXITSTATUS(status));
    }
    printf("\n");

    return 0;
}