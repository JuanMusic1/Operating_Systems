#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
        printf("Inicio de la ejecucion del programa.\n");
        clock_t begin=clock();
        printf("Medida de inicio de ejecucion tomada.\n");
        clock_t end=clock();
        double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
        printf("El tiempo de ejecucion fue %f\n",time_spent);
}