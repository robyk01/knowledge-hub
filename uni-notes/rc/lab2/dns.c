#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 2728
extern int errno;

typedef struct {
    const char *domain;
    const char *ip;
} dns;

dns dns_map[] = {
    {"google.com", "142.250.185.46"},
    {"amazon.com", "54.239.28.85"},
    {"localhost", "127.0.0.1"}
};

int dns_map_size = sizeof(dns_map) / sizeof(dns_map[0]);

const char * dns_domain(const char *domain){
    for (int i = 0; i < dns_map_size; i++){
        if (strcmp(domain, dns_map[i].domain) == 0){
            return dns_map[i].ip;
        }
    }
    return "NXDOMAIN";
}

int main(){
    struct sockaddr_in server;
    struct sockaddr_in client;
    char msg[100];
    char msgrasp[100]=" ";
    int sd;

    

    if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
      perror ("[server]Eroare la socket().\n");
      return errno;
    }

    bzero (&server, sizeof (server));
    bzero (&client, sizeof (client));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1){
      perror ("[server]Eroare la bind().\n");
      return errno;
    }

    while (1){
        int msglen;
        int length = sizeof (client);

        printf ("[server]Astept la portul %d...\n",PORT);
        fflush (stdout);

        bzero(msg, 100);

        if ((msglen = recvfrom(sd, msg, 100, 0, (struct sockaddr *) &client, &length)) <= 0){
	        perror ("[server]Eroare la recvfrom() de la client.\n");
	        return errno;
	    }

        msg[msglen] = '\0';
        const char *ip = dns_domain(msg);
        if (ip != NULL) {
            snprintf(msgrasp, sizeof(msgrasp), "%s -> %s", msg, ip);
        } else {
            snprintf(msgrasp, sizeof(msgrasp), "%s -> NOT_FOUND", msg);
        }
        fflush(stdout);
        printf ("[server]Mesajul a fost receptionat...%s\n", msg);
        
        if (sendto(sd, msgrasp, 100, 0, (struct sockaddr*) &client, length) <= 0)
        {
        perror ("[server]Eroare la sendto() catre client.\n");
        continue;
        }
        else
        printf ("[server]Mesajul a fost trasmis cu succes.\n");

        }		

}