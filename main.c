
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct pila {
    int dato;
    char nombre[MAX];
    struct pila *sig;
}tpila;

void inicializar_pila(tpila **p);
tpila *genera_pila(int num, char nom[]);
void poner_en_pila(tpila **p, int num, char nom[]);
void sacar_de_pila(tpila **p, int *num, char nom[]);
void mostrar_pila(tpila **p);

int main() {
    tpila *p;
    inicializar_pila(&p);
    poner_en_pila(&p,8,"Juan");
    poner_en_pila(&p,2,"Pepe");
    poner_en_pila(&p,3,"Pedro");
    poner_en_pila(&p,4,"Ismael");
    mostrar_pila(&p);
    return 0;
}

void inicializar_pila(tpila **p) {
    *p = NULL;
}

tpila *genera_pila(int num, char nom[]) {
    tpila *aux = malloc(sizeof(tpila));
    aux->dato = num;
    strcpy(aux->nombre,nom);
    aux->sig = NULL;
    return aux;
}

void poner_en_pila(tpila **p, int num, char nom[]) {
    tpila *nuevo = genera_pila(num,nom);
    nuevo->sig = *p;
    *p = nuevo;
}

void sacar_de_pila(tpila **p, int *num, char nom[]) {
    tpila *aux = *p;

    if(aux == NULL) {
        puts("Pila vacia");
        system("pause");
    } else {
        *num = aux->dato;
        strcpy(nom,aux->nombre);
        *p = aux->sig;
        free(aux);
    }
}

void mostrar_pila(tpila **p) {
    int n;
    char nom[MAX];
    if(*p != NULL) {
        sacar_de_pila(p,&n,nom);
        printf("Numero: %d",n);
        printf("\nNombre: %s\n",nom);
        mostrar_pila(&(*p));
        poner_en_pila(&(*p),n,nom);
    }
}
