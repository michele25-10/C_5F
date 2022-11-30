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

int Palindroma(char stringa[], int indice){
    for(int i = 0; i<indice; i++){
        if(stringa[i] != stringa[indice-1-i]){
            return -1;
        }
    }
    return 0;
}

int main(){
    char str[DIM];
    int result;

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
        printf("\n %s", str);
        int indice = strlen(str);
        result = Palindroma(str, indice);
        printf("%d\n", result);
        if(result == -1){
            char response[50] = "La parola NON è palindroma";
            write(soa, response, sizeof(response));
        }
        if(result == 0){
            char response2[50] = "La parola è Palindroma";
            write(soa, response2, sizeof(response2));
        }
    
        close(soa);
    }

    return 0;
}