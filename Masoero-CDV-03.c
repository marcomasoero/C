/*
author: Masoero Marco 3AROB
date:
es. 3
testo: Caricare un vettore, quindi ordinarlo con gli algoritmi di ordinamento
studiati (chiedere all’utente quale vuole utilizzare) e quindi chiedere quale
elemento si vuole cercare e utilizzare l’algoritmo di ricerca opportuno.
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <stdbool.h>

#define LUNG 50
#define DIM 100

int chiediDimensione(int n) {
    int k;
    do {
        printf("Inserisci la dimensione del vettore: ");
        scanf("%d", &k);
    } while(k < 0 || k > n);

    return k;
}

void caricaVettore(int v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("Elemento in posizione [%d]: ", k);
        scanf("%d", &v[k]);
    }
}

void stampaVettore(int v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

void ordinaVettore(int v[], char tipo[], int n) {
    printf("\nInserisci il tipo di ordinamento che preferisci:\n selectionsort\n bubblesort1\n bubblesort2\n bubblesort3\n");
    scanf("%s", tipo);
    if (strcmp(tipo, "selectionsort")== 0) {
        ordinaSSort(v, n);
    } else {
        if (strcmp(tipo, "bubblesort1")== 0) {
            ordinaBSort1(v, n);
        } else {
            if (strcmp(tipo, "bubblesort2")== 0) {
                ordinaBSort2(v, n);
            } else {
                if (strcmp(tipo, "bubblesort3")== 0) {
                    ordinaBSort3(v, n);
                }else{
                    ordinaVettore(v, tipo, n);
                }
            }
        }
    }
}

void ordinaSSort(int vett[], int n) {
    int k, kmin, j;
    for(k = 0; k < n - 1; k++) {
        kmin = k;
        for(j = k + 1; j < n; j++) {
            if(vett[kmin] > vett[j]) // confronti
                kmin = j;
        }
        if(kmin != k)
            scambio(&vett[k], &vett[kmin]); //scambi
    }
    stampaVettore(vett, n);
    return;

}

void ordinaBSort1(int vett[], int n) {
    int k, sup;
    for (sup = n - 1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (vett[k] > vett[k + 1])
                scambio( &vett[k], &vett[k + 1]);
        }
    }
    stampaVettore(vett, n);
}

void ordinaBSort2(int vett[], int n) {
    int k, sup;
    bool sca;
    sup = n - 1;
    sca = true;
    while ((sup > 0) && sca == true) {
        sca = false;
        for (k = 0; k < sup; k++) {
            if (vett[k] > vett[k + 1]) {
                scambio( &vett[k], &vett[k + 1]);
                sca = true;
            }
        }
        sup--;
    }
    stampaVettore(vett, n);
}

void ordinaBSort3(int vett[], int n) {
    int k, sup, sca;
    sup = n - 1 ;
    while(sup > 0) {
        sca = 0 ;
        for (k = 0; k < sup ; k++) {
            if (vett[k] > vett[k + 1]) {
                scambio(&vett[k], &vett[k + 1]);
                sca = k;
            }
        }
        sup = sca;
    }
    stampaVettore(vett, n);
}

void scambio(int *s1, int *s2) {
    int s3;

    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

int cercaVettore(int v[], int n) {
    int nx, k, x;
    nx = 0;
    printf("\nInserisci l'elemento che si vuole cercare:\n");
    scanf("%d", &x);
    for (k = 0; k < n; k++) {
        if(x == v[k]) {
            nx++;
        }
    }
    return nx;
}

int main() {
    char tipo[LUNG];
    int vett[DIM];
    int neUso, nx = 0;

    neUso = chiediDimensione(DIM);
    caricaVettore(vett, neUso);
    stampaVettore(vett, neUso);
    ordinaVettore(vett, tipo, neUso);
    nx = cercaVettore(vett, neUso);

    if(nx == 0) {
        printf("Elemento non presente.");
    } else {
        printf("Elemento presente %d volte.", nx);
    }

    return 0;
}
