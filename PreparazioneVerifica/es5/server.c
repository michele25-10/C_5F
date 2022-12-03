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

int Trova(char str[], int indice, char str2[], int indice2, char comune[])
{
    int k = 0;
    char temp[1]; 
    for (int i = 0; i < indice; i++)
    {
        for (int j = 0; j < indice2; j++)
        {
                if (str[i] == str2[j])
                {
                comune[k] = str[i]; 
                k++; 
                }
        }
    }
}

int main()
{
    char str[DIM];
    char str2[DIM];
    char comune[DIM];
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

        read(soa, str2, sizeof(str2));
        printf("\n La stringa è: %s", str2);
        int indice2 = strlen(str2);

        Trova(str, indice, str2, indice2, comune);

        write(soa, comune, sizeof(comune));

        close(soa);
    }

    return 0;
}