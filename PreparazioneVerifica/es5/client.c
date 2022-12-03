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
    char str2[DIM];
    char comune[DIM]; 
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
    connect(socketfd, (struct sockaddr*) &servizio, sizeof(servizio));

    printf("Inserisci la stringa: \n");
    scanf("%s", str);
    write(socketfd, str, sizeof(str));

    printf("Inserisci la stringa: \n");
    scanf("%s", str2);
    write(socketfd, str2, sizeof(str2));

    read(socketfd, comune, sizeof(comune));

    printf("%s\n", comune);

    close(socketfd);
    return 0;
}