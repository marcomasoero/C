/*
author: Masoero Marco 4AROB
date: 30/10/2023
es. libreria
testo:
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct{
    char* titolo;
    char* autore;
    int anno;
}Libreria;

int contaRighe(char filename[], char riga[]){
    FILE *fp;
    int k = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
    }else{
        while(fgets(riga, DIM_RIGA, fp)){
            k++;
        }
    }

    fclose(fp);

    return k;
}

void stampaValori(Libreria array[], int contatore){
    printf("\n");
    for(int k = 0; k < contatore; k++){
        printf("%s %s %d\n", (array + k)->titolo, (array + k)->autore, (array + k)->anno);
    }
    printf("\n");
}

void scambio(Libreria *s1, Libreria *s2){
    Libreria s3;
    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

void bubbleSort1(Libreria vett[], int n){
    for (int sup = n - 1; sup > 0; sup--){
        for (Libreria *k = vett; k < vett + sup ; k++){
            if (k->anno > (k + 1)->anno){
                scambio(k, (k + 1));
            }
        }
    }
}

int main(){
    char filename[] = "./libreria.csv";
    char riga[DIM_RIGA];
    FILE* fp;
    char* campo;
    Libreria *array;

    int righe = contaRighe(filename, riga);
    array = (Libreria*)malloc(righe*sizeof(Libreria));
    int contatore = 0;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste", filename);
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");
        (array + contatore)->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->autore = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->anno = atoi(campo);
        contatore++;
    }

    stampaValori(array, contatore);
    bubbleSort1(array, contatore);
    stampaValori(array, contatore);
    

    fclose(fp);

    return 0;
}