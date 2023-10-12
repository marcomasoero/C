/*
author: Masoero Marco 4AROB
date: 19/09/2023
es.
testo:
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <string.h>
#include <math.h>

#define DIMENSIONERIGA 200
#define NUMERORIGHE 20000

typedef struct{
    int numero;
    char *titolo; //char[10]
    char *genere;
    int anno;
    char *disponibilita;
}Film;

int main(){
    char nomeFile[] = "listafilm.csv";
    char riga[DIMENSIONERIGA];
    FILE *fp;
    char *campo;
    Film array[NUMERORIGHE];
    int contatore = 0;
    int annoRicerca;

    if(fp == NULL){
        printf("Il file non esiste.");
        exit(1);
    }

    while(fgets(riga, DIMENSIONERIGA, fp)){
        printf("%s\n", riga);
        campo = strtok(riga, ",");
        (array + contatore)->numero = atoi(campo);
        //per andare avanti sulla riga strtok necessità di NULL e non più di riga
        campo = strtok(NULL, ",");
        (array + contatore)->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->genere = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->anno = atoi(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->disponibilita = strdup(campo);
        contatore++;
    }
    printf("Debug");
    for(int k = 0; k < contatore; k++){
        printf("%d %s %s %d %s\n", (array + k)->numero, (array + k)->titolo, (array + k)->genere, (array + k)->anno, (array + k)->disponibilita);
    }
    printf("Inserisci l'anno del quale si desiderano visualizzare i film: ");
    scanf("%d", &annoRicerca);
    for(int k = 0; k < contatore; k++){
        if(annoRicerca == (array + k)->anno){
            printf("%s\n", (array + k)->titolo);
        }
    }
}
