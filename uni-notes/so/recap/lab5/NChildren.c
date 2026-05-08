#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    int N = 0, i;
    pid_t pid;

    if (argc < 2){
        printf("Introduceti nr de fii: ");
        while (scanf("%d", &N) != 1 || N < 1){
            fprintf(stderr, "\nEroare: nu ati introdus un numar intreg pozitiv. Incercati din nou..");
            while (getchar() != '\n');
        }
    } else {
        if (sscanf(argv[1], "%d", &N) != 1 || N < 1){
            fprintf(stderr, "\nEroare: nu ati specificat un numar intreg pozitiv");
            exit(1);
        }
    }

    printf("Sunt procesul initial cu PID %d, iar parintele meu este procesul %d.\n", getpid(), getppid());

    for (int i = 1; i <= N; i++){
        if ((pid = fork()) == -1){
            perror("Eroare la fork");
            exit(2);
        }

        if (pid == 0){
            printf("Sunt procesul fiu %d, avand PID-ul %d, iar parintele meu este procesul cu PID-ul %d.\n", i, getpid(), getppid());
            return i;
        }
    }

    for (int i = 1; i <= N; i++){
        wait(NULL);
    }

    return 0;
}