#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

#define DIM 512
#define SERVERPORT 63400

void generaLunghezza(int numeri[], int numero)
{
    srand(time(NULL));
    for (int i = 0; i < numero; i++)
    {
        numeri[i] = rand() % 100;
    }
}

void bubblesort(int numeri[], int numero)
{
    int temp;
    for (int i = 0; i < numero - 1; i++)
    {
        for (int k = 0; k < numero - 1 - i; k++)
        {
            if (numeri[k] > numeri[k + 1])
            {
                temp = numeri[k];
                numeri[k] = numeri[k + 1];
                numeri[k + 1] = temp;
            }
        }
    }
}

int ripetizioni(int numeri[], int numerocercare, int numero)
{
    int count = 0;

    for (int i = 0; i < numero; i++)
    {
        if (numeri[i] == numerocercare)
        {
            count++;
        }
    }
    return count;
}

void stampanumeri(int numeri[], int numero)
{
    for (int i = 0; i < numero; i++)
    {
        printf("%d-", numeri[i]);
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client
    int socketfd, soa, fromlen = sizeof(servizio), val;
    // definizione dei dati del socket
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = INADDR_ANY;
    servizio.sin_port = htons(SERVERPORT);
    // impostazione del transport endpoint del server
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    // leghiamo l'indirizzo al transport endpoint
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client
    listen(socketfd, 5); // può attendere fino a 5 client
    // ciclo infinito
    while (1)
    {
        printf("\nServer in ascolto...");

        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        // legge dal client
        int quantita = 0, numerocercare = 0, numeroripetuto = 0, controllo = 0;
        read(soa, &quantita, sizeof(quantita));
        printf("Quantita ricevuta: %d\n", quantita);
        int array[quantita];
        read(soa, array, sizeof(array));
        read(soa, &numerocercare, sizeof(numerocercare));
        printf("Numero da cercare ricevuto: %d\n", numerocercare);

        bubblesort(array, quantita);
        stampanumeri(array, quantita);
        numeroripetuto = ripetizioni(array, numerocercare, quantita);
        printf("ripetuto: %d volte\n", numeroripetuto);

        controllo = write(soa, array, sizeof(array));
        if (controllo != -1)
            printf("Inviato array\n");
        controllo = write(soa, &numeroripetuto, sizeof(numeroripetuto));
        if (controllo != -1)
            printf("Inviato numero");
        close(soa);
    }

    return 0;
}
