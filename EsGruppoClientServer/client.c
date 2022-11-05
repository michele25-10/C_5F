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
#include <arpa/inet.h>

#define DIM 512
#define SERVERPORT 63400

int main(){
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = inet_addr("192.168.2.83");
    servizio.sin_port = htons(SERVERPORT);

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
    connect(socketfd, (struct sockaddr*) &servizio, sizeof(servizio));
    int quantita = 0;
    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d", &quantita);
    int numeri[quantita];
    int i = 0;
    while(i<quantita){
        printf("Inserisci il numero:\n");
        scanf("%d", &numeri[i]);
        i++;
    }
    int cerca = 0; 
    printf("Che numero vuoi cercare per sapere quante volte compare?");
    scanf("%d", &cerca);

    int numeriOrdinati[quantita];
    
    write(socketfd, &quantita, sizeof(quantita));
    write(socketfd, numeri, sizeof(numeri));
    write(socketfd, &cerca, sizeof(cerca));
    
    read(socketfd, numeriOrdinati, sizeof(numeriOrdinati));
    i=0;
    while(i<quantita){
        printf("Numeri ordinati: %d\n", numeriOrdinati[i]);
        i++;
    }
    int ripetizioni = 0;
    read(socketfd, &ripetizioni, sizeof(ripetizioni));
    printf("Il numero %d viene ripetuto %d volte\n", cerca, ripetizioni);

    close(socketfd);

    return 0;

}