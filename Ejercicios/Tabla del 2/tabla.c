#include <stdio.h>
#include <time.h>


int main() {
	printf("Inicio de la ejecucion del programa.\n");
    clock_t begin=clock();
    printf("Medida de inicio de ejecucion tomada.\n");
	
	int num;

	scanf("%d", &num);
	for(int i = 0;i <= num; i++){
		printf("2 * %d = %d \n",i,2*i );
	}

	clock_t end=clock();
    double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("El tiempo de ejecucion fue %f\n",time_spent);

}