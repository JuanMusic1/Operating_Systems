#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int numDescomp = 0;
int size = 0;
int sizef = 0;
int sizet = 0;


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
int main(){
    
    //Cositas globales para generar
    printf("Inserte Numero.\n");
    scanf("%d", &numDescomp);
    printf("\n");
    arrprimos = (int*) malloc(sizeof(int));

    genPrimos(numDescomp);

    //Arreglo que analizara y añadira sus factores primos 1 x 1
    
    factores = (int*) malloc(sizeof(int));
    int i_factores = 0;

    //Preparo los procesos a separar
    int i = 0, j = 1, k = 2;
    printf("1\n");
    //crea los fork para sus 3 procesos
    pid_t proces1 = getpid();
    pid_t proces2 = fork();
    //printf("Fork exitoso para el proceso 2 con pid %i\n",proces2);
    pid_t proces3;
    if(proces1 == getpid()){
        proces3 = fork();
    }


    //Aqui funciona todo
    if(proces1 == getpid()){
        printf("Proceso 1 con PID %i\n", getpid());
        while(i <= size -1){
            if((numDescomp % arrprimos[i]) == 0){  
                addfact(arrprimos[i]);  //aqui falta algo
                numDescomp = numDescomp/arrprimos[i];         
                i_factores++;            
                continue;
            }     
            i = i + 3;  
        }
        printA(factores, i_factores);

    } else if(proces2 == 0){
        printf("Proceso 2 con PID %i\n", getpid());
        while(j <= size - 1){
            if((numDescomp % arrprimos[j]) == 0){  
                addfact(arrprimos[j]);  // aqui falta algo
                numDescomp = numDescomp/arrprimos[j];         
                i_factores++;            
                continue;
            }     
            j = j + 3;  
        }
        printA(factores, i_factores);
            
    } else if(proces3 == 0){
        printf("Proceso 3 con PID %i\n", getpid());

        while(k <= size -1){
            if((numDescomp % arrprimos[k]) == 0){  
                addfact(arrprimos[k]);  //x3
                numDescomp = numDescomp/arrprimos[k];         
                i_factores++;       
                continue;
            }     
            k = k + 3;  
        }
        printA(factores, i_factores);

    }


    free(factores);
    free(arrprimos);
    return 0;
}