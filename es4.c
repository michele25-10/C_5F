#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define DIM 20

int SoloLettere(char firstString[]){
    char lettere[26]="abcdefghijklmnopqrstuvwxyz";
    int i;
    int j;
    int nLettere = 0;
    for(i=0; i<strlen(firstString); i++){
        for(j=0; j<26; j++){
            if(firstString[i]==lettere[j]){
                nLettere = nLettere + 1;
            }
        }
    }
    if(nLettere == strlen(firstString)){
        return 0;
    }else{
        return 1;
    }
}

int Vocali(char firstString[]){
    char vocali[5]="aeiou";
    int nVocali = 0; 
    int i;
    int j;
    for(i=0; i<strlen(firstString); i++){
        for(j=0; j<5; j++){
            if(tolower(firstString[i]) == vocali[j]){
                nVocali = nVocali + 1;   
                j=4;    
            }
        }
    }
    return nVocali; 
}

int Consonanti(char firstString[]){
    char consonanti[21]="bcdfghjklmnpqrstvwxyz";
    int nCons = 0; 
    int i;
    int j;
    for(i=0; i<strlen(firstString); i++){
        for(j=0; j<21; j++){
            if(tolower(firstString[i]) == consonanti[j]){
                nCons = nCons + 1;
                j=20;
            }
        }
    }
    return nCons; 
}

int Trova(char firstString[]){
    char lettera[1];
    printf("Inserisci una lettera: \n");
    scanf("%s", lettera); 
    int i;
    int tot = 0;
    for(i=0; i<strlen(firstString); i++){
        if(firstString[i] == lettera[0]){
            tot = tot + 1;
        }
    }
    return tot;
}

void PariDispari(char firstString[]){
    char pari[10] =""; 
    char dispari[10]="";
    for (int i = 0; i < strlen(firstString); i++)
    {
        if(i%2==0){
             strncat(pari, &firstString[i], 1);
        }else{
             strncat(dispari, &firstString[i], 1);
        }
    }
    printf("Pari: %s\n", pari);
    printf("Dispari: %s\n", dispari);
}

void Doppie(char firstString[]){
    int i;
    for (i = 0; i < strlen(firstString)-1; i++)
    {
        if(firstString[i]==firstString[i+1]){
            printf("Contiene doppie\n"); 
            break;
        }
    }
    
}

int PiuLunga(char firstString[], char secondString[]){
    if (strlen(firstString) > strlen(secondString))
    {
        return 1;
    }
    else if (strlen(firstString) < strlen(secondString))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


void LettereComune(char firstString[], char secondString[])
{
    printf("Lettere contenute in entrambe le stringhe:\n");
    for (int i = 0; i < strlen(firstString); i++)
    {
        for (int j = 0; j < strlen(secondString); j++)
        {
            if (firstString[i] == secondString[j])
            {
                printf("%c\n", firstString[i]);
            }
        }
    }
}

int main(){
    char firstString[DIM];
    char secondString[DIM];
    printf("Scrivi la prima parola: \n");
    scanf("%s", firstString);
    if((SoloLettere(firstString)) == 0){
        printf("Contiene solo lettere\n");
    }else{
        printf("Non contiene solo lettere\n");
    }
    printf("Il numero di vocali sono: %d\n", Vocali(firstString));
    printf("Il numero di consonanti sono: %d\n", Consonanti(firstString));
    printf("La lettera da te digitata è stata trovata nella prima stringa %d° volte\n", Trova(firstString));
    PariDispari(firstString);
    Doppie(firstString);

    printf("Inserisci la seconda stringa:\n");
    scanf("%s", secondString);

    if((PiuLunga(firstString, secondString)) == 1){
        printf("E' più lunga la prima stringa\n");
    }else if((PiuLunga(firstString, secondString)) == 2){
        printf("E' più lunga la seconda stringa\n");
    }else{
        printf("Le stringhe sono della stessa lunghezza\n");
    }

    LettereComune(firstString, secondString);

    if(Vocali(firstString) > Vocali(secondString)){
        printf("Ci sono più vocali nella prima stringa\n");
    }else if(Vocali(firstString) == Vocali(secondString)){
        printf("Ci sono le stesse quantità di vocali\n");
    }else{
        printf("Ci sono più vocali nella seconda stringa\n");
    }
    
    if(Consonanti(firstString) > Consonanti(secondString)){
        printf("Ci sono più consonanti nella prima stringa\n");
    }else if(Consonanti(firstString) == Consonanti(secondString)){
        printf("Ci sono le stesse quantità di vocali\n");
    }else{
        printf("Ci sono più consonanti nella seconda stringa\n");
    }
    
    return 0;
}