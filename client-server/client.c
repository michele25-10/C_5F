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

#define DIM 512
#define SERVERPORT 1313

int main(int argc,char** argv)
{   
    //creazione di un elemento di tipo sockaddr
    struct sockaddr_in servizio;
    int socketfd; //identificatore della socket
    char str1[DIM];

    //Inizializzazione dell'elemento di tipo sockaddr pag 162
    servizio.sin_family=AF_INET;    //passo protocollo di comunicazione
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); //Indirizzo dell'host in questo caso locale ()
    servizio.sin_port=htons(SERVERPORT);    //Porta del server

    //creazione e definizione del socket di tipo stream tcp pag 163
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    //connessione al server
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    
    printf("Inserisci la stringa\n");
    scanf("%s",str1);
    write(socketfd,str1,sizeof(str1));
    
    close(socketfd);

    return 0;
}
