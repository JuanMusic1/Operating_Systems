#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int numDescomp;

typedef struct {
    int dato;
    struct Nodo *sgt;
} Nodo;

Nodo *primer = NULL;
Nodo *final = NULL;

void addNodo(int numero){
    Nodo *temp = malloc(sizeof(Nodo));
    temp -> sgt = NULL;
    temp -> dato = numero;

    if(primer == NULL){
        primer = temp;
        final = temp;
    } else {
        final -> sgt = temp;
        final = temp;
    }

}
void genPrimoscriba(int tam){
    int i, h;

    addNodo(0);     //m[0] = 0;
    addNodo(0);     //m[1] = 0;
    for(i = 2; i <= tam; ++i) 
        addNodo(1);

    Nodo *iter = primer;
    for(i = 0; i*i <= tam; ++i) {
        if(iter -> dato) {
            int k, l = 0;
            for(h = 2; i * h <= tam; ++h)
                for( k = 1; k <= h;k++){
                    l+=i;
                }
                (iter + l) -> dato = 0;
                l = 0;
        }
        iter = iter -> sgt;
    }
}


int main(){
    //Pido el numero a descomponer
    printf("Ingrese el numero a descomponer\n");
    scanf("%d",&numDescomp);

    genPrimoscriba(numDescomp);

    Nodo *inter = primer;
    while(inter != NULL){
        printf("%d\n", inter -> dato);
        inter = inter -> sgt;
    }

    
    


    return 0;
}