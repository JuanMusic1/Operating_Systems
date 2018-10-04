#include <stdio.h>


int main() {
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


}
