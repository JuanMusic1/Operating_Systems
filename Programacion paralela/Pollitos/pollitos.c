#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define COMIDA_DISPONIBLE  1000

pthread_t pollito1, pollito2, pollito3, pollito4, pollito5, pollito6;

pthread_mutex_t cuch1, cuch2, cuch3, cuch4, cuch5, cuch6;

void * comer();

 int main(){
    
    if (pthread_mutex_init(&cuch1, NULL) != 0){
        printf("\n mutex 1 init failed\n");
        return 1;
    }
    if (pthread_mutex_init(&cuch2, NULL) != 0){
        printf("\n mutex 2 init failed\n");
        return 1;
    }
    if (pthread_mutex_init(&cuch3, NULL) != 0){
        printf("\n mutex 3 init failed\n");
        return 1;
    }
    if (pthread_mutex_init(&cuch4, NULL) != 0){
        printf("\n mutex 4 init failed\n");
        return 1;
    }
    if (pthread_mutex_init(&cuch5, NULL) != 0){
        printf("\n mutex 5 init failed\n");
        return 1;
    }
    if (pthread_mutex_init(&cuch6, NULL) != 0){
        printf("\n mutex 6 init failed\n");
        return 1;
    }

    int err;
    if (err = pthread_create( &pollito1, NULL, &comer, NULL) != 0){
        printf("Pollito 1 falla");
        return 1;
    }
     if (err = pthread_create( &pollito2, NULL, &comer, NULL) != 0){
        printf("Pollito 2 falla");
        return 1;
    }
     if (err = pthread_create( &pollito3, NULL, &comer, NULL) != 0){
        printf("Pollito 3 falla");
        return 1;
    }
     if (err = pthread_create( &pollito4, NULL, &comer, NULL) != 0){
        printf("Pollito 4 falla");
        return 1;
    }
     if (err = pthread_create( &pollito5, NULL, &comer, NULL) != 0){
        printf("Pollito 5 falla");
        return 1;
    }
     if (err = pthread_create( &pollito6, NULL, &comer, NULL) != 0){
        printf("Pollito 6 falla");
        return 1;
    }

    pthread_join( pollito1, NULL);
    pthread_join( pollito2, NULL);
    pthread_join( pollito3, NULL);
    pthread_join( pollito4, NULL);
    pthread_join( pollito5, NULL);
    pthread_join( pollito6, NULL);    

	exit(EXIT_SUCCESS);

    pthread_mutex_destroy(&cuch1);

    return 0;

}
