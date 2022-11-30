#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>//definiscono la struttura degli indirizzi e funzione del tipo ntohl
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int main(){
    char str[DIM];
    int str_res;
    char carattere[1];

    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
    connect(socketfd, (struct sockaddr*) &servizio, sizeof(servizio));

    printf("Inserisci la stringa: \n");
    scanf("%s", str);

    printf("Inserisci un carattere: \n");
    scanf("%s", carattere);

    write(socketfd, str, sizeof(str));
    write(socketfd, carattere, sizeof(carattere));

    read(socketfd, &str_res, sizeof(str_res));

    close(socketfd);

    printf("%s è stata trovata %d° volte\n", carattere, str_res);
    return 0;
}