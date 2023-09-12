/*
author: Masoero Marco 3AROB
date:
es. 4
testo:
Creare un programma a menù con le seguenti funzioni:
        0 = esci
        1 = carica il vettore con valori casuali da -20 a 20, dopo aver chiesto quanti elementi si vogliono inserire
        2 = visualizza il vettore
        3 = somma di tutti gli elementi
        4 = media degli elementi
        5 = visualizza valore minimo e massimo
        6 = gli elementi sono tutti positivi?
        7 = somma degli elementi positivi
        8 = somma degli elementi negativi
        9 = quale somma è maggiore in valore assoluto?
ATTENZIONE! Controlla che sia stato caricato il vettore prima di poter eseguire le varie opzioni
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <stdbool.h>

#define DIM 100
#define LIM_MIN -20  //limite inferiore
#define LIM_MAX 20  //limite superiore

int menu() {
    int scelta;

    printf("\n\n0 esci");
    printf("\n1 carica il vettore con valori casuali da -20 a 20, dopo aver chiesto quanti elementi si vogliono inserire");
    printf("\n2 visualizza il vettore");
    printf("\n3 somma di tutti gli elementi");
    printf("\n4 media degli elementi");
    printf("\n5 visualizza valore minimo e massimo");
    printf("\n6 gli elementi sono tutti positivi?");
    printf("\n7 somma degli elementi positivi");
    printf("\n8 somma degli elementi negativi");
    printf("\n9 quale somma e maggiore in valore assoluto?");
    printf("\nScelta: ");
    scanf("%d", &scelta);

    return scelta;
}

int chiediDimensione(int n) {
    int k;
    do {
        printf("\nInserisci la dimensione del vettore: ");
        scanf("%d", &k);
    } while(k < 0 || k > n);

    return k;
}

void caricaVettore(int v[], int n) {
    for(int k = 0; k < n; k++) {
        int r = LIM_MIN + rand() % (LIM_MAX + 1 - LIM_MIN);
        v[k] = r;
    }
}

void stampaVettore(int v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

void sommaVettore(int v[], int n, int *s) {
    for(int k = 0; k < n; k++) {
        *s += v[k];
    }
}

void ordinaVettore(int v[], int n) {
    int k, sup;
    for (sup = n - 1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (v[k] > v[k + 1])
                scambio( &v[k], &v[k + 1]);
        }
    }
}

void scambio(int *s1, int *s2) {
    int s3;

    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

void valoriVettore(int v[], int n) {
    bool positivi = true;
    int k = 0;
    while(positivi == true && k < n) {
        if(v[k] < 0) {
            positivi == false;
        }
        k++;
    }
    return positivi;
}

void sommaValori(int v[], int n, int *vP, int *vN) {
    for(int k = 0; k < n; k++) {
        if(v[k] < 0) {
            *vN = *vN + v[k];
        } else {
            *vP = *vP + v[k];
        }
    }
}

int main() {
    int scelta;
    int vett[DIM];
    int neUso;
    int somma = 0, vP = 0, vN = 0;
    float media = 0;
    bool positivi;
    int verifica = 0;

    do {
        scelta = menu();

        switch(scelta) {
        case 0:
            break;

        case 1:
            srand(time(NULL));  //imposto un tempo
            neUso = chiediDimensione(DIM);
            caricaVettore(vett, neUso);
            verifica++;
            break;

        case 2:
            if(verifica == 0) {
                scelta = 1;
            } else {
                stampaVettore(vett, neUso);
            }
            break;

        case 3:
            if(verifica == 0) {
                scelta = 1;
            } else {
                sommaVettore(vett, neUso, &somma);
                printf("\nSomma Valori Vettore:\n %d", somma);
            }
            break;

        case 4:
            if(verifica == 0) {
                scelta = 1;
            } else {
                media = somma / neUso;
                printf("\nMedia Valori Vettore:\n %.2f", media);
            }
            break;

        case 5:
            if(verifica == 0) {
                scelta = 1;
            } else {
                ordinaVettore(vett, neUso);
                printf("\nValore Minimo Vettore: %d\nValore Massimo Vettore: %d\n",vett[0], vett[neUso - 1]);
            }
            break;

        case 6:
            if(verifica == 0) {
                scelta = 1;
            } else {
                valoriVettore(vett, neUso);
                if(positivi == true) {
                    printf("\nSono tutti positivi\n");
                } else {
                    printf("\nNon sono tutti positivi\n");
                }
            }
            break;

        case 7:
            if(verifica == 0) {
                scelta = 1;
            } else {
                sommaValori(vett, neUso, &vP, &vN);
                printf("\nSomma Valori Positivi: %d\n", vP);
            }
            break;

        case 8:
            if(verifica == 0) {
                scelta = 1;
            } else {
                sommaValori(vett, neUso, &vP, &vN);
                printf("\nSomma Valori Negativi: %d\n", vN);
            }
            break;

        case 9:
            if(verifica == 0) {
                scelta = 1;
            } else {
                if(vP > vN * -1) {
                    printf("\nLa somma dei valori positivi e maggiore.\n");
                } else {
                    if(vP < vN * -1) {
                        printf("\nLa somma dei valori negativi e maggiore.\n");
                    } else {
                        printf("\nLa somma dei valori negativi e dei valori positivi e uguale.\n");
                    }
                }
            }
            break;
        }
    } while(scelta != 0);

    return 0;
}
