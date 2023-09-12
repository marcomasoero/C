/*
author: Masoero Marco 3AROB
date:
es. 8
testo: I dati sugli incassi di 3 reparti di un magazzino nei primi 6 mesi sono organizzati in una matrice.
Il numero di riga indica il numero del reparto,
il numero di colonna indica il mese.
        1 = caricare la matrice
Calcolare:
        2 = l'incasso totale per ogni mese
        3 = l'incasso totale per ogni reparto
        4 = l'incasso totale per tutti i reparti nel periodo considerato
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo

#define DIM 3
#define NC 6

int menu() {
    int scelta;

    printf("\n\n0 esci");
    printf("\n1 Carica la matrice");
    printf("\n2 Incasso totale per ogni mese");
    printf("\n3 Incasso totale per ogni reparto");
    printf("\n4 Incasso totale per i reparti in un periodo considerato");
    printf("\nScelta: ");
    scanf("%d", &scelta);

    return scelta;
}

void caricaMatrice(int mat[DIM][NC], int numeroRighe, int righe, int colonne) {
    FILE *fp;
    fp = fopen("matrice.txt", "r");

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
                printf("%d ", mat[righe][colonne]);
            }
            printf("\n");
        }
    }
}

void calcolaMese(int mat[DIM][NC]) {
    int somma;
    int m = 0;
    for(int k = 0; k < NC; k++) {
        m++;
        somma = 0;
        for(int i = 0; i < DIM; i++) {
            somma += mat[i][k];
        }
        printf("\nSomma del %d' mese:\n %d", m, somma);
    }
    printf("\n");
}

void calcolaReparto(int mat[DIM][NC]) {
    int somma;
    int r = 0;
    for(int k = 0; k < DIM; k++) {
        r++;
        somma = 0;
        for(int i = 0; i < NC; i++) {
            somma += mat[k][i];
        }
        printf("\nSomma del %d' reparto:\n %d", r, somma);
    }
    printf("\n");
}

void calcolaPeriodo(int mat[DIM][NC], int inizio, int fine) {
    int somma;
    for(int k = 0; k < DIM; k++) {
        for(int i = inizio - 1; i < fine; i++) {
            somma += mat[k][i];
        }
    }
    printf("\nSomma dei reparti nel periodo dal %d' mese al %d' mese:\n %d", inizio, fine, somma);
    printf("\n");
}

int main() {
    int scelta;
    int numeroRighe, righe, colonne, inizio, fine;
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
                calcolaMese(matrice);
            }
            break;

        case 3:
            if(verifica == 0) {
                scelta = 1;
            } else {
                calcolaReparto(matrice);
            }
            break;

        case 4:
            if(verifica == 0) {
                scelta = 1;
            } else {
                do {
                    printf("\nInserisci il mese di inzio: ");
                    scanf("%d", &inizio);
                } while(inizio < 0 || inizio >= NC);
                do {
                    printf("\nInserisci il mese di fine: ");
                    scanf("%d", &fine);
                } while(fine < inizio || fine > NC);
                calcolaPeriodo(matrice, inizio, fine);
            }
            break;
        }
    } while(scelta != 0);

    return 0;
}
