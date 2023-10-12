/*
author: Masoero Marco 4AROB
date: 09/10/2023
es. 3
testo: Usare il bubbleSort con il metodo dei puntatori
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

void bubbleSort1(int vett[], int n){
    int k, sup;
    for (sup = n - 1; sup > 0; sup--){
        for (k = 0; k < sup ; k++){
            if (*(vett + k) > *(vett + k + 1)){
                scambio(vett + k, vett + k + 1);
            }
        }
    }
}

void stampaVettore(int vett[], int n){
    for(int k = 0; k < n; k++){
        printf("%d", *(vett + k));
    }
}

int main(){
    int vettore[DIM] = {5, 3, 2, 6, 1, 4};
    stampaVettore(vettore, DIM);
    bubbleSort1(vettore, DIM);
    printf("\n");
    stampaVettore(vettore, DIM);

    return 0;
}