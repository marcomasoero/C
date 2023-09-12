/*
author: Masoero Marco 3AROB
date:
es. 2
testo: Dato un vettore A di interi creare i vettori PARI e DISPARI formati
rispettivamente dagli elementi pari e dispari presenti in A
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <math.h>

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

void caricaVettori(int v[], int vP[], int vD[], int n) {
    for(int k = 0; k < n; k++) {
        if((v[k] % 2) == 0){
            vP[k] = v[k];
        }else{
            vD[k] = v[k];
        }
    }
}

void stampaVettori(int v[], int vP[], int vD[], int n){
    printf("\nVettore\n");
    for(int k = 0; k < n; k++){
        printf("%d ", v[k]);
    }
    printf("\nVettore Pari\n");
    for(int k = 0; k < n; k++){
        printf("%d ", vP[k]);
    }
    printf("\nVettore Dispari\n");
    for(int k = 0; k < n; k++){
        printf("%d ", vD[k]);
    }
}

int main(){
    int vettA[DIM], vettPari[DIM], vettDispari[DIM];
    int neUso;

    neUso = chiediDimensione(DIM);
    caricaVettore(vettA, neUso);
    caricaVettori(vettA, vettPari, vettDispari, neUso);
    stampaVettori(vettA, vettPari, vettDispari, neUso);

    return 0;
}
