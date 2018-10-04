#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <gmp.h>

typedef struct Nodo{
    mpz_t dato;
    struct Nodo *siguiente;
}Nodo;

//Nodos de la lista de perfectos
Nodo *primeroP = NULL;
Nodo *ultimoP = NULL;

void agregarP(int num){
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo -> siguiente = NULL;
    mpz_inits(nodo -> dato, num);
    if(primeroP == NULL){
        primeroP = nodo;
        ultimoP = nodo;
    } else {
        ultimoP -> siguiente = nodo;
        ultimoP = nodo;
    }
}


void genPrimos(int num){
    mpz_t cantidad;
    mpz_t contador;
    mpz_inits(contador, 2);
    mpz_inits(cantidad, 10);
    

    while(cantidad != 0){
        

    }

}

void imprimirLista(){
    Nodo *i = primeroP;
     while(i != NULL){
        printf("%ld \n", mpz_out_str(stdout,10, i -> dato) );
        i = i -> siguiente;
     }
}

int main() {
    int cantPedir = 0;
    printf("\n Ingrese la cantidad de Numeros Perfectos a Imprimir. \n");
    scanf("%d", &cantPedir);
    mpz_t temp;
    mpz_inits(temp,0);
    if(cantPedir >= 4){
        
        
    }

    

    return 0;
}