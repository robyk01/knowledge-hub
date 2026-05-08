#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid2, pid3;
    int status;

    pid_t fii_p1[4];

    // nivel 1
    for (int i = 1; i <= 4; i++){
        if (-1 == (pid2 = fork())){
            perror("eroare la fork p2");
            exit(1);
        }

        if (0 == pid2){

            // nivel 2
            pid_t fii_p2[3];
            for (int j = 1; j <= 3; j++){
                if (-1 == (pid3 = fork())){
                    perror("eroare la fork p3");
                    exit(2);
                }

                if (0 == pid3){

                    // nivel 3
                    int k = (i - 1) * 3 + j;
                    printf("(3,%d) PID:%d, PPID:%d, Fii:-\n", k, getpid(), getppid());
                    exit(k);
                } else {
                    fii_p2[j - 1] = pid3;
                }
            }

            printf("(2,%d) PID:%d, PPID:%d, Fii: ", i, getpid(), getppid());
            for (int j = 0; j < 3; j++) {
                waitpid(fii_p2[j], &status, 0);
                printf("[%d, cod:%d] ", fii_p2[j], WEXITSTATUS(status));
            }
            printf("\n");
            exit(i);
        } else {
            fii_p1[i - 1] = pid2;
        }
    }

    printf("(1,1) PID:%d, PPID:%d, Fii: ", getpid(), getppid());
    for (int i = 0; i < 4; i++) {
        waitpid(fii_p1[i], &status, 0);
        printf("[%d, cod:%d] ", fii_p1[i], WEXITSTATUS(status));
    }
    printf("\n");
}