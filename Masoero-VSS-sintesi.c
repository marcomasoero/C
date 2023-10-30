/*
author: Masoero Marco 4AROB
date: 17/10/2023
es. sintesi
testo:
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct{
    char* cognome;
    char* nome;
    int anno;
    int mese;
    int giorno;
    int data;
}Persona;

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

void stampaValori(Persona array[], int contatore){
    printf("\n");
    for(int k = 0; k < contatore; k++){
        printf("%s %s %d/%d/%d %d\n", (array + k)->cognome, (array + k)->nome, (array + k)->anno, (array + k)->mese, (array + k)->giorno, (array + k)->data);
    }
    printf("\n");
}

void scambio(Persona *s1, Persona *s2){
    Persona s3;
    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

void bubbleSort1(Persona vett[], int n){
    for (int sup = n - 1; sup > 0; sup--){
        for (int *k = vett; k < vett + sup ; k++){
            if ((vett + *k)->data > (vett + *k + 1)->data){
                scambio(k, k + 1);
            }
        }
    }
}

int main(){
    char filename[] = "./persone.csv";
    char riga[DIM_RIGA];
    FILE* fp;
    char* campo;
    Persona *array;

    int righe = contaRighe(filename, riga);
    array = (Persona*)malloc(righe*sizeof(Persona));
    int contatore = 0;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste", filename);
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");
        (array + contatore)->cognome = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->nome = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->anno = atoi(campo);
        campo = strtok(NULL,",");
        (array + contatore)->mese = atoi(campo);
        campo = strtok(NULL,",");
        (array + contatore)->giorno = atoi(campo);
        contatore++;
    }

    for(int k = 0; k < contatore; k++){
        (array + k)->data = (array + k)->anno * 1000 + (array + k)->mese * 100 + (array + k)->giorno;
    }

    stampaValori(array, contatore);
    bubbleSort1(array, contatore);
    stampaValori(array, contatore);
    

    fclose(fp);

    return 0;
}