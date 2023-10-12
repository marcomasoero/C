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

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct{
    int numero;
    char* titolo;   //char[10]
    char* genere;
    int anno;
    char* disponibilita;
}Film;



int main(){
    char filename[] = "./listafilm.csv";
    char riga[DIM_RIGA];
    FILE* fp;
    char* campo;
    Film array_film[NUM_RIGHE];
    int counter = 0, annoDaStampare;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste", filename);
        exit(1);
    }
    
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga,",");
        array_film[counter].numero = atoi(campo);   //atoi converte una stringa in intero;
        campo = strtok(NULL, ",");
        array_film[counter].titolo = strdup(campo);
        campo = strtok(NULL, ",");
        array_film[counter].genere = strdup(campo);
        campo = strtok(NULL, ",");
        array_film[counter].anno = atoi(campo);
        campo = strtok(NULL, ",");
        array_film[counter].disponibilita = strdup(campo);
        counter++;
    }
    for(int k = 0; k < counter; k++){
        printf("%d %s %s %d %s\n", array_film[k].numero, array_film[k].titolo, array_film[k].genere, array_film[k].anno, array_film[k].disponibilita);
    }

    return 0;
}