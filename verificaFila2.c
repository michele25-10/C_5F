//FILA 2 Michele Gabrieli 5F

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIM 50

void Frequenza(char stringa[], int indice){
    int frequenza = 0; 
    char carattere; 
    for(int i = 0; i<indice; i++){
        for(int j = 0; j<indice; j++){
            if(stringa[i] == stringa[j]){ //se la stringa è uguale al carattere in esame j incremento la frequenza
                frequenza += 1; 
            }
        }
        carattere = stringa[i];
        printf("La lettera '%s' compare: %d volte\n", &carattere, frequenza);   
        frequenza = 0;  //stampo e riporto a zero la frequenza
    }
}

void OrdineStabilitoConsegna(char stringa[], int indice){   
    char caratteriSpeciali[DIM]; //contiene numeri e caratteri speciali
    char lettere[DIM]; //contiene solo lettere
    int j, k = 0; 

    for(int i = 0; i<indice; i++){
        if(stringa[i]>96 && stringa[i]<123 || stringa[i]>64 && stringa[i]<91){  //se ha questi valori ascii lo immetto nell'array lettere
            lettere[j] =  stringa[i];
            j++;
        }
        if(stringa[i] <58 && stringa[i] > 32){  //se assume questi valore il carattere in esame lo metto nei caratteri speciali
            caratteriSpeciali[k] = stringa[i];
            k++;
        }
    }
    printf("L'ordine alfabetico dettato dalla consegna è: %s%s\n", lettere, caratteriSpeciali); //stampo

}

void Alfabetico(char stringa[], int indice){
    char temp[1];

    for(int i = 0; i<indice; i++){
        for(int j = i; j<indice; j++){
            if(stringa[i] > stringa[j]){    //se la prima è maggiore della seconda la sposto indietro
                *temp=stringa[i];   //switch variabili
                stringa[i] = stringa[j];
                stringa[j] = *temp; 
            }
        }
    }
}

void PariDispari(char stringa[], int indice){
    char pari[DIM];
    char dispari[DIM]; 
    char temp[1]; 
    int peso = 0;
    int j, k = 0;   //variabili incrementabili per gli array pari e dispari

    Alfabetico(stringa, indice);    //Riordinoo in ordine alfabetico

    for(int i = 0; i<indice; i++){
        if(stringa[i]>96 && stringa[i]<123 || stringa[i]>64 && stringa[i]<91){  //Se la stringa ha come valori quelli degli ascii inseriti entra nel ciclo if
            peso = stringa[i];
            if(peso%2==0){  //se l'ascii è pari lo inserisce nell'array dei pari
                pari[j] = stringa[i];
                j++;
            }else{  //se è dispari lo inserisce nell'array dei dispari
                dispari[k] = stringa[i];    
                k++;
            }
        }
    }

    for(int i = 0; i<indice; i++){  //riordino l'array dei dispari in ordine decrescente invece quello dei pari non ha bisogno dal momento che era già stato ordinato in modo crescente
        for(int j = i; j<indice; j++){
            if(dispari[i] < dispari[j]){
                *temp=dispari[i];
                dispari[i] = dispari[j];
                dispari[j] = *temp; 
            }
        }
    }

    printf("Le lettere PARI sono: %s\n", pari);
    printf("Le lettere DISPARI sono: %s\n", dispari); 
}

int main(){
    char stringa[DIM];
    int indice = 0;
    printf("Inserisci la stringa: \n");
    scanf("%s", stringa);
    indice = strlen(stringa);   //assegno ad indice il numero di indici dell'array occupato
    Frequenza(stringa, indice); //Richiamo le funzioni
    PariDispari(stringa, indice); 
    OrdineStabilitoConsegna(stringa, indice);

    return 0;
}