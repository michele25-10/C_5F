#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Stampa(int vett[], int dim){
    int i;
    for(i=0; i<dim;i++){
        printf("%d\n", vett[i]);
    }
}

void StampaInversa(int vett[], int dim){
    dim=dim-1;
    for(dim; dim==0; dim--){
        printf("%d\n", vett[dim]);
    }
}

int Somma(int vett[], int dim){
    int i;
    int somma = 0;
    for(i=0; i<dim;i++){
        somma = somma + vett[i];
    }
    return somma;
}

int Media(int vett[], int dim, int somma){
    int media;
    media = somma/dim;
    return media;
}

void Pari(int numeri[], int quantita){
    int i;
    for(i=0; i<quantita; i++){
        if((numeri[i]%2)==0){
            printf("Il numero %d è pari\n", numeri[i]);
        }
    }
}

void Dispari(int numeri[], int quantita){
    int i;
    for(i=0; i<quantita; i++){
        if((numeri[i]%2)==1){
            printf("Il numero %d è dispari\n", numeri[i]);
        }
    }
}

void Trova(int vett[], int dim){
    int i;
    int numero;
    int controllo = 0;
    printf("Che numero cerchi?\n");
    scanf("%d", &numero);
    for(i=0; i<dim;i++){
        if(vett[i] == numero){
            printf("Il numero è stato trovato nel vettore ed ha indice: %d\n", i);
            controllo = 1;
        }
    }
    if(controllo != 1){
        printf("NON è stato trovato il numero dato (%d)", numero);
    }
}

void Elimina(int vett[], int dim){
    int trovato = 0;
    int j = 0;
    int numero;
    printf("Che numero cerchi?\n");
    scanf("%d", &numero);
    for (int i = 0; i < dim; i++)
    {
        if (vett[i] != numero)
        {
            vett[j++] = vett[i];
        }
    }

    Stampa(vett, dim);
}

void Inverti(int vett[], int dim){
    int tmp = 0, i = 1;
    while (i < dim)
    {
        tmp = vett[i];
        vett[i] = vett[i - 1];
        vett[i - 1] = tmp;
        i += 2;
    }
    Stampa(vett, dim);
}

void Riordina(int vett[], int dim){
    int temp;
    int i;
    int j;
    for(i=0; i<dim-1;i++){
        for (j=1; j<dim-i-1; j++){
            if(vett[j]>vett[j+1]){
                temp = vett[j];
                vett[j] = vett[j + 1];
                vett[j+1] = temp;
            }
        }
    }
    Stampa(vett, dim);
}

int main(){
    int menu = 0;
    int dim = 0;
    printf("Quanti numeri vuoi inserire nel vettore\n");
    scanf("%d", &dim);
    int vett[dim];
    int i;
    for(i=0; i<dim; i++){
        printf("Inserisci il %d° numero", i+1);
        scanf("%d", &vett[i]);
    }

    do{
        printf("Inserisci quale opzione vuoi:\n");
        printf("-1 Stampa gli elementi dell'array\n");
        printf("-2 Stampa inversa degli elementi dell'array\n");
        printf("-3 Somma e media degli elementi del vettore\n");
        printf("-4 Stampa tutti i numeri pari\n");
        printf("-5 Stampa tutti i numeri dispari\n");
        printf("-6 Ricerca di un numero dell'array\n");
        printf("-7 Eliminare un elemento dell'array\n");
        printf("-8 Alternare a due a due le posizioni del vettore\n");
        printf("-9 Ordinamento del vettore\n");       
        scanf("%d", &menu);
    }while(menu == 0 || menu < 0 || menu > 10);

    switch (menu)
    {
    case 1:
        Stampa(vett, dim);
        break;
    
    case 2:
        StampaInversa(vett, dim);
        break;

    case 3:
        printf("Somma tot: %d\n", Somma(vett, dim));
        printf("Media: %d\n", Media(vett, dim, Somma(vett, dim)));
        break;

    case 4:
        Pari(vett, dim);
        break;

    case 5:
        Dispari(vett, dim);
        break;
    
    case 6:
        Trova(vett, dim);
        break;
    
    case 7:
        Elimina(vett, dim);
        break;
    
    case 8:
        Inverti(vett, dim);
        break;

    case 9:
        Riordina(vett, dim);
        break;
    }

    return 0;
}