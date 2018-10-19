#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

pthread_t hilo1, hilo2, hilo3;

pthread_mutex_t lock;


int numDescomp = 0;
int size = 0;
int sizef = 0;
int sizet = 0;
int i_factores = 0;
int i = 0, j = 1, k = 2;

int *arrprimos;
int *factores;
int *temp;


void addArrP(int numerito){
    arrprimos = realloc(arrprimos, sizeof(int) * (size + 1));
    arrprimos[size] = numerito;
    size++;
}

void addfact(int numerito){
    factores = realloc(factores, sizeof(int) * (sizef + 1));
    factores[sizef] = numerito;
    sizef++;
}

void addtemp(int numerito){
    temp = realloc(temp, sizeof(int) * (sizet + 1));
    temp[sizet] = numerito;
    sizet++;
}


void genPrimos(int tam){
    int i, h;
    temp = (int*) malloc(sizeof(int));

    addtemp(0);//m[1] = 0;
    addtemp(0); //m[2] = 0;
    for(i = 2; i <= tam; ++i) 
        addtemp(1);

    for(i = 1; i*i <= tam +1; ++i) {
        if(temp[i]) {
            for(h = 2; i*h <= tam; ++h)
                temp[i*h] = 0;
        }
    }
    //Aqui paso al arreglo de primos
    for(i = 0; i <= tam +1; i++){
        if(temp[i] == 1){
            addArrP(i);
        }
    }
    free(temp);

}

void printA(int *vecto, int indice){
    int i = 0;
    
    while(i < indice){
        printf("%d\n", vecto[i]);
        i++;
    }
}

void * proceso1(void *arg){

    pthread_mutex_lock(&lock);

    //printf("Proceso 1\n");
    while(i < size){
        if((numDescomp % arrprimos[i]) == 0){
            addfact(arrprimos[i]);  //aqui falta algo
            numDescomp = numDescomp/arrprimos[i];         
            i_factores++;            
            continue;
        }     
        i = i + 3;  
    }
    //printA(factores, i_factores);

    pthread_mutex_unlock(&lock);


    return NULL;
}

void * proceso2(void *arg){

    pthread_mutex_lock(&lock);

    //printf("Proceso 2\n");
    while(j < size){
        if((numDescomp % arrprimos[j]) == 0){
            addfact(arrprimos[j]);  // aqui falta algo
            numDescomp = numDescomp/arrprimos[j];         
            i_factores++;            
            continue;
        }     
        j = j + 3;  
    }
    //printA(factores, i_factores);

    pthread_mutex_unlock(&lock);

}

void * proceso3(void *arg){

    pthread_mutex_lock(&lock);
    
    //printf("Proceso 3\n");
    while(k < size){
        if((numDescomp % arrprimos[k]) == 0){
            addfact(arrprimos[k]);  //x3
            numDescomp = numDescomp/arrprimos[k];         
            i_factores++;       
            continue;
        }     
        k = k + 3;  
    }
    printA(factores, i_factores);

    pthread_mutex_unlock(&lock);
}
int main(){
    
    int err;
    //Cositas globales para generar
    printf("Inserte Numero.\n");
    scanf("%d", &numDescomp);
    printf("\n");
    arrprimos = (int*) malloc(sizeof(int));

    genPrimos(numDescomp);

    //Arreglo que analizara y añadira sus factores primos 1 x 1
    factores = (int*) malloc(sizeof(int));

    printf("1\n");
    //Preparo los hilos para ejecutar el programa
    if (pthread_mutex_init(&lock, NULL) != 0){
        printf("\n mutex init failed\n");
        return 1;
    }
    err = pthread_create(&hilo1, NULL, &proceso1, NULL);
    if (err != 0){
        printf("\ncan't create thread :[%d]", strerror(err));
    }
    err = pthread_create(&hilo2, NULL, &proceso2, NULL);
    if (err != 0){
        printf("\ncan't create thread :[%d]", strerror(err));
    }
    err = pthread_create(&hilo3, NULL, &proceso3, NULL);
    if (err != 0){
        printf("\ncan't create thread :[%d]", strerror(err));
    }


    
    //Aqui funciona todo
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);

    pthread_mutex_destroy(&lock);


    free(factores);
    free(arrprimos);
    return 0;
}