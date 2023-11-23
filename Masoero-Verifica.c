/*
author: Masoero Marco 4AROB
date: 03/11/2023
es. verifica
testo:
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo 
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000
#define QUOTA 2200

typedef struct{
    char* data;
    char* nome;
    int quota;
}Classe;

typedef struct{
    char* cognome;
    int quota;
}Alunno;

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

int stampaValoreTotaleIncassi(Classe array[], int contatore, int somma){
    for(int k = 0; k < contatore; k++){
        somma += array[k].quota;
    }
    return somma;
}

void cercaNome(Classe array[], Alunno alunno[], int contatore, char cognome[], int sm){
    sm = 0;
    for(Classe *k = array; k < array + contatore; k++){
        if(strcmp(cognome, (k->nome)) == 0){
            if((k->quota) == 100){
                printf("\nLa quota è stata pagata.");
                alunno->cognome = cognome;
                alunno->quota = k->quota;
            }else{
                sm = 100 - (k->quota);
                printf("\nAlla quota mancano %d euro: ", sm);
                alunno->cognome = cognome;
                alunno->quota = sm;
            }
        }else{
            printf("\nNon ho trovato il cognome desiderato.");
        }
    }
}

void stampaArray(Classe array[], int contatore){
    for(Classe *k = array; k < array + contatore; k++){
        if((k->quota) == 100){
            printf("%s %d\n", k->nome, k->quota);
        }else{
            printf("%s %d\n", k->nome, k->quota);
            printf("    DA CONTROLLARE!");
        }
    }
}

int main(){
    char filename[] = "./4AROB_GITA.csv";
    char riga[DIM_RIGA];
    FILE* fp;
    char* campo;
    Classe *array;
    Alunno *alunno;
    int somma, sommaMancante;
    
    int righe = contaRighe(filename, riga);
    array = (Classe*)malloc(righe*sizeof(Classe));
    int contatore = 0;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste", filename);
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");
        (array + contatore)->data = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->nome = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->quota = atoi(campo);
        contatore++;
    }
 
    somma = stampaValoreTotaleIncassi(array, contatore, somma);

    if(QUOTA == 2200){
        printf("\nQuota pagata: %d", somma);
    }else{
        printf("\nQuota pagata: %d", somma);
        sommaMancante = QUOTA - somma;
        printf("\nQuota da pagare: %d", sommaMancante);
    }

    char cognome[] = "Masoero";
    cercaNome(array, alunno, contatore, cognome, sommaMancante);

    stampaArray(array, contatore);

    fclose(fp);

    return 0;
}