/*
author: Masoero Marco 4AROB
date: 15/10/2023
es. 3
testo: Usare il selectionSort con il metodo dei puntatori
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo

#define DIM 6

void scambio(int *s1, int *s2){
    int s3;
    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

void selectionSort1(int vett[], int n){
    int kmin;
    for(int *k = vett; k < vett + n; k++) {
        kmin = *k;
        for(int j = *(k + 1); j < n; j++){
            if(vett[kmin] > vett[j]) // confronti
                kmin = j;
        }
        if(kmin != *k){
            scambio(&vett[*k], &vett[kmin]); //scambi
        }
    }
    return;
}

void stampaVettore(int vett[], int n){
    for(int *k = vett; k < vett + n; k++){
        printf("%d", *k);
    }
}

int main(){
    int vettore[DIM] = {5, 3, 2, 6, 1, 4};
    stampaVettore(vettore, DIM);
    selectionSort1(vettore, DIM);
    printf("\n");
    stampaVettore(vettore, DIM);

    return 0;
}