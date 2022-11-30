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

int TrovaLettera(char parola[], char lettera[], int indice){
    int j = 0; 
    for(int i = 0; i<indice; i++){
        if(parola[i] == *lettera){
            j++;
        }
    }
    return j;
}

int main(){
    char str[DIM];
    int result;
    char carattere[1]; 

    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));

    listen(socketfd, 10);

    while(1){
        printf("\n\n SERVER in ascolto...\n");
        fflush(stdout);

        soa=accept(socketfd, (struct sockaddr*)&addr_remoto, &fromlen);

        read(soa, str, sizeof(str));
        printf("\nstringa ricevuta %s\n", str);
        read(soa, carattere, sizeof(carattere));
        int indice = strlen(str);
        int lunghezza = strlen(str); 
        result = TrovaLettera(str, carattere, lunghezza);

        printf("%d\n", result);
        write(soa, &result, sizeof(result)); 

        close(soa);
    }

    return 0;
}