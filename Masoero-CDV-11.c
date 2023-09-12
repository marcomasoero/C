/*
author: Masoero Marco 3AROB
date:
es. 11
testo: Verificare se una matrice quadrata è unaria (tutti 0 tranne la diagonale principale di 1)
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <stdbool.h>

#define DIM 100

int chiediDimensione(int dimMax){
    int x;
    do{
        printf("Inserisci la dimensione della matrice minore di [0..%d]", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

void caricaMatrice(int mat[DIM][DIM], int righe, int colonne, int dim) {
    FILE *fp;
    fp = fopen("unaria.txt", "r");

    if (fp == NULL) {
        printf("File non esistente\n");
    } else {
        righe = 0;
        while(righe < dim && fscanf(fp, "%d", &mat[righe][0]) != EOF) {
            for (colonne = 1; colonne < dim; colonne++) {
                fscanf(fp, "%d", &mat[righe][colonne]);
            }
            righe++;
        }

        fclose(fp);
        dim = righe;

        for (righe = 0; righe < dim; righe++) {
            for (colonne = 0; colonne < dim; colonne++) {
                printf("%2d ", mat[righe][colonne]);
            }
            printf("\n");
        }
    }
}

int verificaUnaria(int mat[DIM][DIM], int dim){
    bool unaria = true;
    int k = 0;
    int i = 0;
    do{
        if(mat[k][i] == 1){
            k++;
            i++;
        }else{
            unaria = false;
        }
    }while(unaria == true && k < dim);

    return unaria;
}

int main() {
    int righe, colonne, dimensione;
    int matrice[DIM][DIM];
    bool unaria;

    dimensione = chiediDimensione(DIM);
    caricaMatrice(matrice, righe, colonne, dimensione);

    unaria = verificaUnaria(matrice, dimensione);
    if(unaria == true){
        printf("La matrice e unaria.");
    }else{
        printf("La matrice NON e unaria.");
    }

    return 0;
}
