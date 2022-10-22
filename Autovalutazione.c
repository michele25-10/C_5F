//FILA A Michele Gabrieli

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define DIM 50

void PopolaArray(int numeri[]){
    for(int i = 0; i<DIM; i++){
        numeri[i] = rand()%100;
    }
}

void Frequenza(int numeri[]){
    int contatore = 0; 
    for(int i = 0; i<DIM; i++){
        for(int j = 0; j<DIM; j++){
            if(numeri[i] == numeri[j]){
                contatore++;
            }
        }
        printf("Il numero %d compare all'interno dell'array numeri %d° volte\n", numeri[i], contatore);
        contatore = 0; 
    }
}

int NoDoppioni(int numeri[]){
    int k = 0; //volte che elimini un numero
    for(int i = 0; i<DIM - k; i++){
        for(int j = i+1 ; j<DIM -k ; j++){
            if(numeri[i] == numeri[j]){
                for(int o = j; o < DIM - k - 1;o++){
                    numeri[o] = numeri[o+1];
                }
                k++;
                i--;
            }
        }
    }
    printf("Numeri singoli\n");
    for(int i = 0; i< DIM - k; i++){
        printf("%d\n", numeri[i]);
    }
    return DIM-k;   //ritorno la grandezza dell'array
}

void PariDispari(int numeri[], int grandezza, int numeriPari[], int dispari[]){
    printf("grandezza: %d\n", grandezza); 
    int j, k = 0; 

    int temp = 0;
    for(int i = 0; i<grandezza; i++){
        for(int l = i; l<grandezza; l++){
            if(numeri[i] > numeri[l]){
                temp = numeri[i];
                numeri[i] = numeri[l];
                numeri[l] = temp; 
            }
        }
    }
    
   for(int i = 0; i<grandezza; i++){
        if(numeri[i] % 2 == 0){
            numeriPari[j] = numeri[i];
            j++;
        }else{ 
            dispari[k] = numeri[i];
            k++;
        }
    }

    for(int i = 0; i<k; i++){
        for(int n = i+1; n<k; n++){
            if(dispari[i] < dispari[n]){
                temp = dispari[i];
                dispari[i] = dispari[n];
                dispari[n] = temp; 
            }
        }
    }
    
    printf("pari\n"); 
    for(int i = 0; i<j; i++){
        printf("%d\n", numeriPari[i]);
    }
    printf("dispari\n"); 
    for(int i = 0; i<k; i++){
        printf("%d\n", dispari[i]);
    }

}

int main(){
    int numeri[DIM];
    int grandezza = DIM; 

    PopolaArray(numeri);
    Frequenza(numeri);
    grandezza = NoDoppioni(numeri);
    int dispari[grandezza];
    int pari[grandezza];
    PariDispari(numeri, grandezza, pari, dispari);
    

    return 0; 
}
