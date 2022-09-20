#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int Controllo(char stringhe[][10], char parola[]){
    int i;

    for(i=0; i<500000; i++){
        if((strcmp(stringhe[i], parola)) == 0){
            return -1;
        }
        else{
            return 0;
        }
    }
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Errore\n");
        exit(0);
    }
    int dim = 500000;
    char stringhe[dim][10];
    char vettCar[36]="abcdefghijklmnopqrstuvwxyz0123456789";
    FILE *fd;
    int righe = 0;
    int i;
    int j;
    char parola[10];
    if((fd = fopen(argv[1], "w")) == NULL){
        printf("Errore apertura file");
    }

    do
    {   
        for(i = 0; i<10; i++){
            j = rand() % 36;
            parola[i] = vettCar[j];
        }

        
        
        if((Controllo(stringhe, parola))==0){
            strcpy(stringhe[righe], parola);
            fprintf(fd, "%s\n",stringhe[righe]);
            righe ++;
        }
    } while (righe < dim);
    
    fclose(fd);
    
    return 0;
}