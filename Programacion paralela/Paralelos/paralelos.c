#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    int contador = 0;
    pid_t principal = getpid(), hijo = fork();

    if(principal == getpid()){
        printf("Soy el proceso padre con ID %i, Voy a hacer la talbe del 1 al 5.\n", getpid());
        for(contador = 1; contador <= 5; contador++){
            printf("2*%i = %i\n",contador,2*contador);

        }
    } else {
        printf("Soy el proceso padre con ID %i, Voy a hacer la talbe del 2 al 10.\n", getpid());
        for(contador = 6; contador <= 10; contador++){
            printf("2*%i = %i\n",contador,2*contador);

        }

    }

    return 0;
}