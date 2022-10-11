#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Minuscolo(char parola[]){
    for(int i = 0; i<strlen(parola); i++){
        parola[i] = tolower(parola[i]);
    }
    printf("La parola in minuscolo è: %s\n",parola);
}

int ASCII(char parola[]){
    int peso = 0;
    for(int i = 0; i< strlen(parola); i++){
        peso += parola[i];
    }
    return peso;
}

void EliminaSpazi(char parola[], char newParola[]){
    int conteggio = 0;
    for(int i = 0; i<strlen(parola); i++){
        if(parola[i] != ' '){
            newParola[i] = parola[i];
            conteggio++;
        }
    }
}

int Palindroma(char parola[], int indice){
    for(int i = 0; i<indice; i++){
        if(parola[i] != parola[indice-i]){
            return -1;
        }
    }
    return 0;
}

int ContaDoppie(char parola[]){
    int conteggio = 0;
    for(int i = 1; i < strlen(parola); i++){
        if(parola[i-1] == parola[i]){
            conteggio += 2;
        }
    }
    return conteggio;
}

void OrdineAlfabetico(char parola[]){
    //97 - 122
    int peso1 = 0;
    int peso2 = 0;
    int lunghezza = 0;
    char temp[1];
    lunghezza = strlen(parola);
    for(int i = 0; i<lunghezza; i++){
        for(int j = i; j<lunghezza; j++){
            if((peso1 = parola[i]) > (peso2 = parola[j])){
                *temp = parola[j];
                parola[j] = parola[i];
                parola[i] = *temp;
            }
            peso1, peso2 = 0;
        }
    }
    printf("In ordine alfabetico: %s\n", parola);
}

int TrovaLettera(char parola[], char lettera[], int indice){
    for(int i = 0; i<indice; i++){
        if(parola[i] == *lettera){
            return 1;
        }
    }
    return 0;
}

void Invertita(char parola[], int indice){
    char temp[1];
    for(int i = 0; i<indice; i++){
        *temp = parola[i];
        parola[i] = parola[indice-i];
        parola[indice-i] = *temp;
    }
    printf("La parola invertita è: %s\n", parola);
}   

void Random(char parola[], int indice){
    char lettere[26]="abcdefghijklmnopqrstuvwxyz";
    char newParola[indice];
    int numrand = 0;
    for(int i = 0; i<indice; i++){
        numrand = rand() % 26;
        newParola[i] = lettere[numrand];
    }
    printf("Parola random: %s\n", newParola);
}

void PariDispari(char parola[], int indice){
    char pari[indice];
    char dispari[indice];
    int j = 0;
    int k = 0; 
    for(int i = 0; i<indice; i++){
        if(i%2==0){
            pari[j] = parola[i];
            j++;
        }else{
            dispari[k] = parola[i];
            k++;
        }
    }
    printf("Lettere pari: %s\n", pari);
    printf("Lettere dispari: %s\n", dispari);
}

void LettereInComune(char prima[], int indice1, char seconda[], int indice2){
    char lettereComune[25];
    int k = 0;
    int controllo = 0; 
    for(int i = 0; i<indice1; i++){
        for(int j=0; j<indice2; j++){
            if(prima[i] == seconda[j]){
                for(int n = 0; n<25; n++){
                    if(prima[i] == lettereComune[n]){
                        controllo = 1; 
                    }
                    if(controllo != 1 && n==24){
                        lettereComune[k] = prima[i];
                        k++;
                        controllo = 0; 
                    }
                }

            }
        }
    }

    printf("Le lettere in comune sono le seguenti: %s\n", lettereComune);
}

int main(){
    char parola[50];
    char newParola[50];
    printf("Inserisci la parola: \n");
    scanf("%s", parola);

    int indice = strlen(parola);
    printf("%d\n", indice);

    Minuscolo(parola);

    printf("Il peso della parola è: %d\n", ASCII(parola));

    //EliminaSpazi(parola, newParola);

    if(Palindroma(parola, indice-1) == 0){
        printf("La parola è palindroma\n");
    }else{
        printf("La parola NON è palindroma\n");
    }

    printf("Le doppie sono: %d\n",ContaDoppie(parola));

    Invertita(parola, indice-1);

    OrdineAlfabetico(parola);
    
    char lettera[1];
    printf("Lettera da trovare: \n");
    scanf("%s", lettera);

    if(TrovaLettera(parola, lettera, indice-1)==1){
        printf("La lettera è stata trovata\n");
    }else{
        printf("La lettera non è stata trovata\n");
    }

    Random(parola, indice);

    PariDispari(parola, indice-1);

    char parola2[20];
    printf("Inserisci una seconda parola: \n");
    scanf("%s", parola2);
    int indice2 = strlen(parola2);
    LettereInComune(parola, indice-1, parola2, indice2-1);

    return 0;
}