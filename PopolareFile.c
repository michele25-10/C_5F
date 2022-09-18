#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Errore\n");
        exit(0);
    }

    char vettCar[36]="abcdefghijklmnopqrstuvwxyz0123456789";
    FILE *fd;
    int righe = 0;
    int i;
    int j;
    char parola[20];
    fd = fopen(argv[1], "w");
    do
    {   
        for(i = 0; i<20; i++){
            j = rand() % 36;
            parola[i] = vettCar[j];
        }
        fprintf(fd, "%s\n",parola);
        righe ++;
    } while (righe < 100000);
    
    fclose(fd);
    
    return 0;
}