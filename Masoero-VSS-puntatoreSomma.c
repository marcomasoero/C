/*
author: Masoero Marco 4AROB
date: 10/10/2023
es. 4
testo: Sommare gli elementi di un vettore con il metodo dei puntatori
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <string.h>
#include <math.h>

#define DIM 5

int main(){
    int vettore[DIM] = {1, 2, 3, 4, 5};
    int somma = 0;

    for(int *k = vettore; k < vettore + DIM; k++){
        somma += *k;
    }

    printf("Somma: %d", somma);

    return 0;
}