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
#include <sys/wait.h>

#define DIM 512
#define SERVERPORT 1313

int ConteggioVoc(char str[], int dimensione){
    int k = 0; 
    for(int i = 0; i<dimensione; i++){
        if(str[i] > 96 && str[i] < 123){
            if(str[i] == 97 || str[i] == 101 ||str[i] == 105 || str[i] == 111 || str[i] == 117){
                k++;
            }
        }
    }
    return k;
}

int ConteggioCons(char str[], int dimensione){
    int k = 0; 
    int j = 0; 
    for(int i = 0; i<dimensione; i++){
        if(str[i] > 96 && str[i] < 123){
            if(str[i] == 97 || str[i] == 101 ||str[i] == 105 || str[i] == 111 || str[i] == 117){
                k++;
            }else{
                j++; 
            }
        }
    }
    return j;
}

int main(){
    char str[DIM];
    char carattere;
    int quantitaVoc = 0;
    int quantitaCons = 0;
    int dimstr = 0;
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
        printf("\n La stringa è: %s", str);
        dimstr = strlen(str);
        for(int i = 0; i<dimstr; i++){
            str[i] = tolower(str[i]);
        }
        quantitaVoc = ConteggioVoc(str, dimstr);
        printf("\nquantitaVoc: %i", quantitaVoc);
        write(soa, &quantitaVoc, sizeof(quantitaVoc));
    
        quantitaCons = ConteggioCons(str, dimstr);
        printf("\nquantitaCons: %i", quantitaCons);
        write(soa, &quantitaCons, sizeof(quantitaCons));

        close(soa);
    }

    return 0;
}