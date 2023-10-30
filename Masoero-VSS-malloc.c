/*
author: Masoero Marco 4AROB
date: 16/10/2023
es. 4
testo: Allocazione dinamica della Memoria = Malloc
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 600

typedef struct{
    int numero;
    char* titolo;
    char* genere;
    int anno;
    char* disponibilita;
}Film;


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

void stampaTutto(Film array_film[], int counter){
    for(int k=0; k < counter; k++){
        printf("%d %s %s %d %s\n", (array_film + k)->numero, (array_film + k)->titolo, (array_film + k)->genere, (array_film + k)->anno, (array_film + k)->disponibilita);
    }
}


int main(){
    Film *array_film;
    char filename[] = "./listafilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char* campo;

    int righe = contaRighe(filename, riga);
    array_film = (Film*)malloc(righe*sizeof(Film));
    int counter = 0, anno;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Il file non esiste");
        exit(1); //esce dal programma
    }

    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");//dentro campo trovo il primo campo della rica e il campo separatore che   la virgola
        (array_film + counter)->numero = atoi(campo);//converte in itero per conventire in float si usa atof()

        campo = strtok(NULL, ",");
        (array_film + counter)->titolo = strdup(campo); //(*(array_film + counter)).titolo = strdup(campo)

        campo = strtok(NULL, ",");
        (array_film + counter)->genere = strdup(campo);

        campo = strtok(NULL, ",");
        (array_film + counter)->anno = atoi(campo);

        campo = strtok(NULL, ",");
        (array_film + counter)->disponibilita = strdup(campo);

        counter ++;
    }

    stampaTutto(array_film, counter);
    return 0;
}

    /*
    void trovaFilm(Film array_film[], int counter, int anno){
        for(int k = 0; k < counter; k++){
            if((array_film + k)->anno == anno){
                printf("%s\n", (array_film + k)->titolo);
            }
        }  
    }

    printf("Inserisci l'anno di un film: ");
    do{
        scanf("%d", &anno);
    }while(anno > 2023 || anno < 0);

    trovaFilm(array_film, counter, anno);
    */