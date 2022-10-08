#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int Controllo(int numero, int array[], int indice){
    for(int i = 0; i<indice; i++){
        if(numero == array[i]){
            return -1;
        }
    }
    return 0;
}

void Stampa(int array[], int indice){
    for(int i = 0; i<indice; i++){
        printf("%d\n", array[i]);
    }
}

void OrdinoArray(int array[]){
    int temp = 0;
    for(int i = 0; i<100-1; i++){
        for (int j = i+1; j <100; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int ConteggioPari(int array[]){
    int conteggio=0;
    for (int i = 0; i<100-1; i++){
        if(array[i] % 2 == 0){
            conteggio += 1;
        }
    }

    return conteggio;
}

int ConteggioDispari(int array[]){
    int conteggio=0;
    for (int i = 0; i<100-1; i++){
        if(array[i] % 2 != 0){
            conteggio += 1;
        }
    }

    return conteggio;
}

void Assegnazioni(int array[], int arraypari[], int arraydispari[]){
    int conteggiopari=0;
    int conteggiodispari=0;
    for (int i = 0; i<100; i++){
        if(array[i]%2==0 && conteggiopari < 20){
            arraypari[conteggiopari] =  array[i];
            array[i] = 0;
            conteggiopari += 1;
        }
        if(array[i]%2==1 && conteggiodispari < 20){
            arraydispari[conteggiodispari] =  array[i];
            array[i] = 0;
            conteggiodispari += 1;
        }
    }

    OrdinoArray(array);

    for (int i = 0; i<100; i++){
        if(i < sizeof(array)/int){
            array[i] = arraypari[i];
        }
    }
}

int main(){
    srand(time(NULL));
    int array[100];
    int numero = 0;
    for(int i = 0; i<100; i++){
        do{
            numero = rand() % 233;
        }while(Controllo(numero, array, i) != 0);
        array[i] = numero;
    }

    Stampa(array, 100);

    OrdinoArray(array);
    printf("ORDINATI\n");
    Stampa(array, 100);
    
    if(ConteggioPari(array)<20 && ConteggioDispari(array)<20){
        int arraypari[ConteggioPari(array)];
        int arraydispari[ConteggioDispari(array)];
        Assegnazioni(array, arraypari, arraydispari);
    }

    if(ConteggioPari(array)<20 && ConteggioDispari(array)>20){
        int arraypari[ConteggioPari(array)];
        int arraydispari[20];
        Assegnazioni(array, arraypari, arraydispari);
    }
        
    if(ConteggioPari(array)>20 && ConteggioDispari(array)<20){
        int arraypari[20];
        int arraydispari[ConteggioDispari(array)];    
        Assegnazioni(array, arraypari, arraydispari);
    }
    
    if(ConteggioPari(array)>20 && ConteggioDispari(array)>20){
        int arraypari[20];
        int arraydispari[20];
        Assegnazioni(array, arraypari, arraydispari);
    }

    
    return 0;
}