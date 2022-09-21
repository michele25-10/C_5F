#include <stdio.h>
#include <stdlib.h>

void pari(int numeri[], int quantita){
    int i;
    for(i=0; i<quantita; i++){
        if((numeri[i]%2)==0){
            printf("Il numero %d è pari\n", numeri[i]);
        }
    }
}

int main(){
    int quantita;
    int i;
    printf("Inserisci la quantità di numeri che vuoi analizzare:\n");
    scanf("%d", &quantita);
    int numeri[quantita];
    for(i=0; i<quantita; i++){
        printf("Inserisci il %d° numero:", i+1);
        scanf("%d", &numeri[i]);
    }
    pari(numeri, quantita);
    return 0;
}