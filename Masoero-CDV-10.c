/*
author: Masoero Marco 3AROB
date:
es.
testo: Data la matrice A NRxNC creare la sua trasposta B NCxNR
1 2 3 diventa    1 4
4 5 6                  2 5
                          3 6
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo

#define DIM 2
#define NC 3

void caricaMatrice(int mat[DIM][NC], int numeroRighe, int righe, int colonne) {
    FILE *fp;
    fp = fopen("scambiaMat.txt", "r");

    if (fp == NULL) {
        printf("File non esistente\n");
    } else {
        righe = 0;
        while(righe < DIM && fscanf(fp, "%d", &mat[righe][0]) != EOF) {
            for (colonne = 1; colonne < NC; colonne++) {
                fscanf(fp, "%d", &mat[righe][colonne]);
            }
            righe++;
        }

        fclose(fp);
        numeroRighe = righe;

        for (righe = 0; righe < numeroRighe; righe++) {
            for (colonne = 0; colonne < NC; colonne++) {
                printf("%2d ", mat[righe][colonne]);
            }
            printf("\n");
        }
    }
}

void scambiaMatrice(int matA[DIM][NC], int matB[NC][DIM]){
    for(int k = 0; k < DIM; k++){
        for(int i = 0; i < NC; i++){
                matB[i][k] = matA[k][i];
        }
    }
}

void stampaMatrice(int matB[NC][DIM]){
    for(int i = 0; i < NC; i++){
        for(int k = 0; k < DIM; k++){
                printf("%2d", matB[i][k]);
        }
        printf("\n");
    }
}

int main(){
    int numeroRighe, righe, colonne;
    int matriceA[DIM][NC];
    int matriceB[NC][DIM];

    caricaMatrice(matriceA, numeroRighe, righe, colonne);
    scambiaMatrice(matriceA, matriceB);
    printf("\n");
    stampaMatrice(matriceB);

    return 0;
}
