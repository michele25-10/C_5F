#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define DIM 100

void AutoIncrementante(int array[]){
    for (int i = 0; i<DIM; i++){
        array[i] = rand()%100000;
    }
}
void Stampa (int array[], int lunghezza){
    for(int i = 0; i<lunghezza; i++){
        printf("%d\n", array[i]);
    }
}

void Inserisci(int array[], int j){
    j = j + 1;
    int numero = 0; 
    printf("Inserisci il numero da aggiungere all'array\n");
    scanf("%d", &numero);

    array = realloc(array,j * sizeof(int) );
    array[j-1] = numero;
    Stampa(array, j);
}

int main(){
    int array[DIM];
    int menu;
    int j = DIM;
    AutoIncrementante(array);
    printf("Digita un numero per gestire il menù:\n");
    printf("1. Inserisci numero\n");
    printf("2. Cerca un numero\n");
    printf("3. Elimina numero\n");
    printf("4. Ordina\n");
    scanf("%d", &menu);
    switch(menu){
        case 1:
            Inserisci(array, j);
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;
    }

    return 0;
}