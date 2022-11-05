#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> //definisce la struttura degli indirizzi e funzioni del tipo ntohl
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>

#define DIM 512
#define SERVERPORT 63401

int main(){
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM];
    // definizione dei dati del socket 
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    // leghiamo l'indirizzo del server all'host al quale si deve inviare pag 
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);// può attendere fino a 10 client
    // ciclo infinito
    while(1)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        //legge dal client
        read(soa,str,sizeof(str));
        printf("Stringa ricevuta: %s\n",str);
        int dimensione = strlen(str);
        for(int i = 0; i<dimensione; i++){
            str[i] = tolower(str[i]);
        }
        char vocali[dimensione];
        char consonanti[dimensione];
        char numeriSpeciali[dimensione];
        int j = 0, k = 0, l = 0; 
        for(int i = 0; i<dimensione; i++){
            if(str[i] == 97 || str[i] == 101 || str[i] == 105 || str[i] == 111 || str[i] == 117){
                vocali[j] = str[i];
                j++;
            }
            if (str[i] != 97 || str[i] != 101 || str[i] != 105 || str[i] != 111 || str[i] != 117){
                if(str[i]>96 && str[i]<123){
                    consonanti[k] = str[i];
                    k++;
                }
            }
            if(str[i]<97 || str[i]>122){
                numeriSpeciali[l] = str[i];
                l++;
            }
        }

        write(soa, vocali, sizeof(vocali));
        write(soa, consonanti, sizeof(consonanti));
        write(soa, numeriSpeciali, sizeof(numeriSpeciali));

        close(soa);

     }
      
   return 0;
    
}
