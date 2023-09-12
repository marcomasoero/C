/*
author: Masoero Marco 3AROB
date:
es. 1
testo: Verificare se un vettore è speculare (per es. è formato dagli elementi 1,2,3,2,1)
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <stdbool.h>

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

bool vSpeculare(int v[], int n){
    int k = 0;
    bool vSpec = true;

    do{
        if(v[k] != v[n - k - 1]){
            vSpec = false;
        }else{
            k++;
        }
    }while((k < (n / 2)) && (vSpec == true));

    return vSpec;
}

int main(){
    int vett[DIM];
    int neUso;
    bool vSpec;

    neUso = chiediDimensione(DIM);
    caricaVettore(vett, neUso);

    if(vSpeculare(vett, neUso) == true){
        printf("Vettore speculare");
    }else{
        printf("Vettore non speculare");
    }

    return 0;
}
