#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int esPrimo(int n){
    int i,a;
    a = 0;

    for(i = 1; i<= n; i++){
        if(n%i == 0){
            a++;
        }
    }

    if(a == 2){
        return 1;
    } else {
        return 0;
    }      
}
void printPrim(int cont){
    if(esPrimo(cont)){
        printf("El numero %i es primo\n", cont);
    }

}

int main(){

    int n,contador = 1;

    printf("Ingrese hasta el numero que quiere analizar\n");

    scanf("%i",&n);

    pid_t proces1 = getpid();
    pid_t proces2 = fork();
    //printf("Fork exitoso para el proceso 2 con pid %i\n",proces2);
    pid_t proces3;
    if(proces1 == getpid()){
        proces3 = fork();
    }

    if(proces1 == getpid()){
        
        printf("Proceso 1 con PID %i\n", getpid());
            while(contador <= (n/3)){
                printPrim(contador);
                contador++;
            }

    } else if(proces2 == 0){
         printf("Proceso 2 con PID %i\n", getpid());
         contador = (n/3);
            while(contador <= 2*(n/3)){
                printPrim(contador);
                contador++;
            }
      }else if(proces3 == 0){
            printf("Proceso 3 con PID %i\n", getpid());
            contador = 2*(n/3);
            while(contador <= n){
                printPrim(contador);
                contador++;
            }
        }
    return 0;
}