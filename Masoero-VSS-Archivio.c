#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct{
    char* titolo;
    char* autore;
    int anno;
}Libreria;

int menu() {
    int scelta;

    printf("\n\n0 esci");
    printf("\n1 Stampa l'archivio");
    printf("\n2 Ordina l'archivio");
    printf("\n3 Stampa l'archivio ordinato");
    printf("\nScelta: ");
    scanf("%d", &scelta);

    return scelta;
}

int contaRighe(char filename[], char riga[]){
    FILE *fp;
    int k = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
    }else{
        while(fgets(riga, DIM_RIGA, fp)){
            k++;
        }
    }

    fclose(fp);

    return k;
}

void stampaValori(Libreria array[], int contatore){
    printf("\n");
    for(Libreria *k = array; k < array + contatore; k++){
        printf("%s %s %d\n", k->titolo, k->autore, k->anno);
    }
    printf("\n");
}

void scambio(Libreria *s1, Libreria *s2){
    Libreria s3;
    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

void bubbleSort1(Libreria vett[], int n){
    for (int sup = n - 1; sup > 0; sup--){
        for (Libreria *k = vett; k < vett + n ; k++){
            if (k->anno > (k + 1)->anno){
                scambio(k, (k + 1));
            }
        }
    }
}

int main(){
    int scelta, verifica;
    char filename[] = "./libreria.csv";
    char riga[DIM_RIGA];
    FILE* fp;
    char* campo;
    Libreria *array;

    int righe = contaRighe(filename, riga);
    array = (Libreria*)malloc(righe*sizeof(Libreria));
    int contatore = 0;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste", filename);
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");
        (array + contatore)->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->autore = strdup(campo);
        campo = strtok(NULL, ",");
        (array + contatore)->anno = atoi(campo);
        contatore++;
    }

    do {
        scelta = menu();

        switch(scelta) {
        case 0:
            break;

        case 1:
            stampaValori(array, contatore);
            verifica++;
            break;

        case 2:
            if(verifica == 0) {
                scelta = 1;
            } else {
                bubbleSort1(array, contatore);
            }
            break;

        case 3:
            if(verifica == 0) {
                scelta = 1;
            } else {
                stampaValori(array, contatore);
            }
            break;
        }
    } while(scelta != 0);

    fclose(fp);

    return 0;
}