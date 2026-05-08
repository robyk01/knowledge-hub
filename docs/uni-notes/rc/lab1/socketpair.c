// Create a program where the parent sends a string to the child. The child concatenates another string to the received string and returns the result to the parent process. Use the socketpair() primitive for communication.

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSG1 "Comunicam prin socketi!"
#define MSG2 "Atentie!Socketpair() o generalizarea a pipe-urilor"

int main(){
    int sockp[2], child;
    char msg[1024];

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0){
        perror("Err.. socketpair");
        exit(1);
    }

    if ((child = fork()) == -1){
        perror("Err.. fork");
    } else if (child){
        // parent
        close(sockp[0]);

        if (read(sockp[1], msg, 1024) < 0){
            perror("Err.. read");
        }

        printf("[parinte] %s\n", msg);

        if (write(sockp[1], MSG2, sizeof(MSG2)) < 0){
            perror("Err,, write");
        }
        close(sockp[1]);
    } else {
        // child
        close(sockp[1]);

        if (read(sockp[0], msg, 1024) < 0){
            perror("Err.. read");
        }
        
        printf("[copil] %s\n", msg);

        if (write(sockp[0], MSG2, sizeof(MSG2)) < 0){
            perror("Err,, write");
        }
        
        close(sockp[0]);
    }
}