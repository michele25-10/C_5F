#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define DIM 50

int CalcoloPeso(char parola[]){
    int value_char, peso = 0;
    for(int i = 0; i < strlen(parola); i++){
        value_char = (int)parola[i];
        peso += value_char;
    }

    return peso;
}

void InMaiuscolo(char parola[]){
    for(int i = 0; i<strlen(parola); i++){
        parola[i] = toupper(parola[i]);
    }
    printf("In maiuscolo: %s\n", parola);
}

void InMinuscolo(char parola[]){
    for(int i = 0; i<strlen(parola); i++){
        parola[i] = tolower(parola[i]);
    }
    printf("In minuscolo: %s\n", parola);
}

void LettaDaDestra(char parola[]){
    char temp[1];
    int lunghezza = strlen(parola);
    for(int i = 0; i<lunghezza; i++){
        *temp = parola[i];
        parola[i] = parola[lunghezza-1];
        parola[lunghezza-1] = *temp;

        lunghezza -= 1 ;
    }

    printf("La parola scritta al contrario è: %s\n", parola);
}

int Vocali(char parola[]){
    char vocali[5] = "aeiou";
    int lunghezza = strlen(parola);
    int conteggio = 0;
    for(int i = 0; i<lunghezza; i++){
        for(int j = 0; j<5; j++){
            if(parola[i] == vocali[j]){
                j = 4;
                conteggio += 1;
            }
        }
    }
    return conteggio;
}

int Consonanti(char parola[]){
    char vocali[5] = "aeiou";
    int lunghezza = strlen(parola);
    int conteggio = 0;
    for(int i = 0; i<lunghezza; i++){
        if(parola[i] != vocali[0]&& parola[i] != vocali[1] && parola[i] != vocali[2] && parola[i] != vocali[3] &&parola[i] != vocali[4]){
            conteggio += 1;
        }
    }
    return conteggio;
}

void CaratteriSpeciali(char parola[]){
    char speciali[22] = "*?![]-#£$&/()=+-.;_<>";
    char parolaSenza[DIM];
    int n = 0;
    int controllo = 0;
    for(int i = 0; i<strlen(parola); i++){
        controllo = 0;
        for(int j = 0; j<strlen(speciali); j++){
            if(parola[i] == speciali[j]){
                j=21;
                controllo = 1;
            }
            if(controllo == 0 && j == 21){
                parolaSenza[n] = parola[i];
                n++;
            }
        }
    }
    printf("La parola senza caratteri speciali è: %s\n", parolaSenza);
}

void OrdineAlfabetico(char parola[]){
    char ordine[26] = "abcdefghjklmnopqrstuvwxyz";
    int lunghezza = strlen(parola);
    
    int indice1 = 0; 
    int indice2 = 0;
    char temp[1];
    for(int i = 0; i<lunghezza; i++){
        for(int j = i+1; j<lunghezza; j++){
            for(int k=0; k<strlen(ordine); k++){
                if(parola[i] == ordine[k]){
                    indice1 = k; 
                }
                if(parola[j] == ordine[k]){
                    indice2 = k;
                }
            }
            if(indice1 > indice2){
                *temp = parola[i];
                parola[i] = parola[j];
                parola[j] = *temp;
            }
        }
    }

    printf("Parola ordinata è: %s\n", parola);
}

int main(){
    char parola[DIM];
    printf("Inserisci la parola\n");
    scanf("%s", parola);
    printf("Il peso è %d\n", CalcoloPeso(parola));

    InMaiuscolo(parola);

    InMinuscolo(parola);

    LettaDaDestra(parola);

    printf("Il numero di vocali è: %d\n", Vocali(parola));
    printf("Il numero di consonanti è: %d\n", Consonanti(parola));

    CaratteriSpeciali(parola);
    
    OrdineAlfabetico(parola);
    return 0;
}
