#include <stdio.h>
#include <time.h>

//cambiarlo a memoria dinamica
int main() {
    printf("Inicio de la ejecucion del programa.\n");
    clock_t begin=clock();
    printf("Medida de inicio de ejecucion tomada.\n");

    unsigned char m[2000000];
    int tam;
    int i, h;

    m[0] = 0;
    m[1] = 0;
    tam = 2000000;
    for(i = 2; i <= tam; ++i){ 
        m[i] = 1;
    }
    for(i = 2; i*i <= tam; ++i) {
        if(m[i]) {
            for(h = 2; i*h <= tam; ++h)
                m[i*h] = 0;
        }
    }
    int contador;
    contador = 0;
    for(i=2; i<=tam; i++){
        if(m[i] == 1){
            printf("\n %d", i);
            contador++;
        }
        if(contador == 100000){
            i=tam;
        }
    }
    printf("\n");

    clock_t end=clock();
    double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("El tiempo de ejecucion fue %f\n",time_spent);
    return 0;

}
