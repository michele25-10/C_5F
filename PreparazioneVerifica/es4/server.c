#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> //definiscono la struttura degli indirizzi e funzione del tipo ntohl
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

int Ordina(char str[], int indice, char alfabetico[])
{
    int k = 0;
    char temp[1]; 
    for (int i = 0; i < indice; i++)
    {
        for (int j = i; j < indice; j++)
        {
            if (str[i] > str[j])
            {
                temp[0] = str[i]; 
                str[i] = str[j]; 
                str[j] = temp[0]; 
            }
        }
    }

    for(int i = 0; i<indice; i++){
        if (str[i] > 47 && str[i] < 58 || str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123)
        {
            alfabetico[k] = str[i]; 
            k++; 
        }
    }
}

int main()
{
    char str[DIM];
    char alfabetico[DIM];
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen = sizeof(servizio);
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    listen(socketfd, 10);

    while (1)
    {
        printf("\n\n SERVER in ascolto...\n");
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);

        read(soa, str, sizeof(str));
        printf("\n La stringa è: %s", str);
        int indice = strlen(str);

        Ordina(str, indice, alfabetico);

        write(soa, alfabetico, sizeof(alfabetico));

        close(soa);
    }

    return 0;
}