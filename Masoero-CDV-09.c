/*
author: Masoero Marco 3AROB
date:
es. 9
testo: I dati sulle votazioni di 10 studenti in prove sono organizzati in una matrice.
Il numero di riga indica il numero dello studente.
Il numero di colonna indica il numero della prova.
Calcolare:
        1 = la media dei voti di ciascun studente
        2 = la media di ciascuna prova
        3 = la media generale della classe in tutte le prove
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo

#define DIM 10
#define NC 4

int menu() {
    int scelta;

    printf("\n\n0 esci");
    printf("\n1 Carica la matrice");
    printf("\n2 La media dei voti di ciascun studente");
    printf("\n3 La media di ciascuna prova");
    printf("\n4 La media generale della classe in tutte le prove");
    printf("\nScelta: ");
    scanf("%d", &scelta);

    return scelta;
}

void caricaMatrice(int mat[DIM][NC], int numeroRighe, int righe, int colonne) {
    FILE *fp;
    fp = fopen("studenti.txt", "r");

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

void mediaStudente(int mat[DIM][NC]) {
    int m = 0;
    for(int k = 0; k < DIM; k++) {
        float somma = 0;
        for(int i = 1; i < NC; i++) {
            somma += mat[k][i];
        }
        float media = 0;
        m++;
        media = somma / (NC - 1);
        printf("\nStudente %d' - Media %.2f", m, media);
    }
}

void mediaProva(int mat[DIM][NC]) {
    int m = 0;
    for(int i = 1; i < NC; i++) {
        float somma = 0;
        for(int k = 0; k < DIM; k++) {
            somma += mat[k][i];
        }
        float media = 0;
        m++;
        media = somma / DIM;
        printf("\nProva %d' - Somma %.2f - Media %.2f", m, somma, media);
    }
}

void mediaGenerale(int mat[DIM][NC]) {
    float somma = 0;
    int m = 0;
    for(int k = 0; k < DIM; k++) {
        for(int i = 1; i < NC; i++) {
            somma += mat[k][i];
            m++;
        }
    }
    float media = 0;
    media = somma / m;
    printf("\nSomma %.2f - Media %.2f", somma, media);
}

int main() {
    int scelta;
    int numeroRighe, righe, colonne;
    int matrice[DIM][NC];
    int verifica = 0;

    do {
        scelta = menu();

        switch(scelta) {
        case 0:
            break;

        case 1:
            caricaMatrice(matrice, numeroRighe, righe, colonne);
            verifica++;
            break;

        case 2:
            if(verifica == 0) {
                scelta = 1;
            } else {
                mediaStudente(matrice);
            }
            break;

        case 3:
            if(verifica == 0) {
                scelta = 1;
            } else {
                mediaProva(matrice);
            }
            break;

        case 4:
            if(verifica == 0) {
                scelta = 1;
            } else {
                mediaGenerale(matrice);
            }
            break;
        }
    } while(scelta != 0);

    return 0;
}
