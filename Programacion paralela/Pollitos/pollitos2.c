#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

//int esta = 1000;

pthread_t pollito1, pollito2, pollito3, pollito4, pollito5, pollito6;

pthread_mutex_t cuch1, cuch2, cuch3, cuch4, cuch5, cuch6; //tazon;

void * comer(int);

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
    /*if(pthread_mutex_init(&tazon, NULL)!= 0){
        printf("\n mutex tazon init failed\n");
        return 1;
    }*/

    int err;
    if ((err = pthread_create( &pollito1, NULL, &comer, (void *)1)) != 0){
        printf("Pollito 1 falla");
        return 1;
    }
    if ((err = pthread_create( &pollito2, NULL, &comer, (void *)2)) != 0){
        printf("Pollito 2 falla");
        return 1;
    }
     if ((err = pthread_create( &pollito3, NULL, &comer, (void *)3)) != 0){
        printf("Pollito 3 falla");
        return 1;
    }
     if ((err = pthread_create( &pollito4, NULL, &comer, (void *)4)) != 0){
        printf("Pollito 4 falla");
        return 1;
    }
     if ((err = pthread_create( &pollito5, NULL, &comer, (void *)5)) != 0){
        printf("Pollito 5 falla");
        return 1;
    }
     if ((err = pthread_create( &pollito6, NULL, &comer, (void *)6)) != 0){
        printf("Pollito 6 falla");
        return 1;
    }

    pthread_join( pollito1, NULL);
    pthread_join( pollito2, NULL);
    pthread_join( pollito3, NULL);
    pthread_join( pollito4, NULL);
    pthread_join( pollito5, NULL);
    pthread_join( pollito6, NULL);

    pthread_mutex_destroy(&cuch1);
    pthread_mutex_destroy(&cuch2);
    pthread_mutex_destroy(&cuch3);
    pthread_mutex_destroy(&cuch4);
    pthread_mutex_destroy(&cuch5);
    pthread_mutex_destroy(&cuch6);
    //pthread_mutex_destroy(&tazon);
    //exit(EXIT_SUCCESS);
    return 0;

}

void * comer(int i){
    int come = 0;
    bool izq, der;

    while(come < 100){

        //congelo 1 y 6
        if(i == 1){
            pthread_mutex_lock(&cuch6);
            pthread_mutex_lock(&cuch1);
            izq = true;
            der = true;
            //congelo 2 y 1
        } else if(i == 2){
            pthread_mutex_lock(&cuch2);
            pthread_mutex_lock(&cuch1);
            izq = true;
            der = true;
            //congelo 3 y 2
        } else if(i == 3){
            pthread_mutex_lock(&cuch2);
            pthread_mutex_lock(&cuch3);
            izq = true;
            der = true;
            //congelo 4 y 3
        } else if(i == 4){
            pthread_mutex_lock(&cuch4);
            pthread_mutex_lock(&cuch3);
            izq = true;
            der = true;
            //congelo 5 y 4
        } else if(i == 5){
            pthread_mutex_lock(&cuch4);
            pthread_mutex_lock(&cuch5);
            izq = true;
            der = true;
            //congelo 6 y 5
        } else if(i == 6){
            pthread_mutex_lock(&cuch6);
            pthread_mutex_lock(&cuch5);
            izq = true;
            der = true;
        }
    
        if(izq == true && der == true){
            //pthread_mutex_lock(&tazon);
            come++;
            //esta--;
            //pthread_mutex_unlock(&tazon);
            if(i == 1){
                printf("\nGolosa 1 come esta\n");
                //printf("Esta tiene %d\n", esta);
                printf("Golosa 1 tiene: %d\n", come);
                izq = false;
                der = false;
                pthread_mutex_unlock(&cuch6);
                pthread_mutex_unlock(&cuch1);
            }else if(i == 2){
                printf("\nGolosa 2 come esta\n");
                //printf("Esta tiene %d\n", esta);
                printf("Golosa 2 tiene: %d\n", come);
                izq = false;
                der = false;
                pthread_mutex_unlock(&cuch1);
                pthread_mutex_unlock(&cuch2);
            } else if(i == 3){
                printf("\nGolosa 3 come esta\n");
                //printf("Esta tiene %d\n", esta);
                printf("Golosa 3 tiene: %d\n", come);
                izq = false;
                der = false;
                pthread_mutex_unlock(&cuch2);
                pthread_mutex_unlock(&cuch3);
            } else if(i == 4){
                printf("\nGolosa 4 come esta\n");
                //printf("Esta tiene %d\n", esta);
                printf("Golosa 4 tiene: %d\n", come);
                izq = false;
                der = false;
                pthread_mutex_unlock(&cuch4);
                pthread_mutex_unlock(&cuch3);
            } else if(i == 5){
                printf("\nGolosa 5 come esta\n");
                //printf("Esta tiene %d\n", esta);
                printf("Golosa 5 tiene: %d\n", come);
                izq = false;
                der = false;
                pthread_mutex_unlock(&cuch5);
                pthread_mutex_unlock(&cuch4);
            }else if(i == 6){
                printf("\nGolosa 6 come esta\n");
                //printf("Esta tiene %d\n", esta);
                printf("Golosa 6 tiene: %d\n", come);
                izq = false;
                der = false;
                pthread_mutex_unlock(&cuch6);
                pthread_mutex_unlock(&cuch5);
            }

        } 
        
    }
    printf("ACABA %d \n", i);
    return NULL;
}