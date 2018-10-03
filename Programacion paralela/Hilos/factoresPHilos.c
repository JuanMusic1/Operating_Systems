#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define clear() printf("\033[H\033[J")

//para 1x1 le falta una comprobacion para cuando le de
//comprueba si un numero es primo, devuelve 1 si lo es, en caso contrario devuelve 0
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

//Genera numeros primos hasta ese numero en un arreglo para posterior uso
void generarPrimos(int numDescompo, int *retor){

    int j = 0;
    while(j < ((numDescompo/2)+1) ){
        int i;
        for(i = 2; i <= numDescompo; i++){
            if(esPrimo(i)){
                retor = realloc(retor, sizeof(int)*2);
                retor[j] = i;
                j++;
            }
        }
        j = numDescompo;
    }
}

void printA(int *vecto, int indice){
    int i = 0;
    
    while(i < indice){
        printf("%d\n", vecto[i]);
        i++;
    }
}

void cleanArr(int tam, int *vetor){
    for(int i = 0; i < tam; i++){
        vetor[i] = 0;
    }
        
}



int main(){
    int numDescompo;
    //Pide el numero a descomponer
    printf("Ingrese el numero a descomponer\n");
    scanf("%d", &numDescompo);
    printf("\n");

    //Crea el arreglo con los primos hasta ese numero
    int *arrprimos = malloc(sizeof(NULL)*1);
    generarPrimos(numDescompo, arrprimos);
    
    //Arreglo que analizara y añadira sus factores primos 1 x 1
    int factores[(numDescompo/2) + 1];
    int i_factores = 0;
    
    //cleanArr(((numDescompo/2)-1),factores);
    //cleanArr((numDescompo/2)-1),arrprimos);


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


    
    if(proces1 == getpid()){
        printf("Proceso 1 con PID %i\n", getpid());
        while(i <= ((numDescompo/2)+1)){
            if((numDescompo % arrprimos[i]) == 0){  
                factores[i_factores] = arrprimos[i];  //aqui falta algo
                numDescompo = numDescompo/arrprimos[i];         
                i_factores++;            
                continue;
            }     
            i = i + 3;  
        }
        

    } else if(proces2 == 0){
        printf("Proceso 2 con PID %i\n", getpid());
        while(j <= ((numDescompo/2)+1)){
            if((numDescompo % arrprimos[j]) == 0){  
                factores[i_factores] = arrprimos[j];  // aqui falta algo
                numDescompo = numDescompo/arrprimos[j];         
                i_factores++;            
                continue;
            }     
            j = j + 3;  
        }
        printA(factores, i_factores);
            
    } else if(proces3 == 0){
        printf("Proceso 3 con PID %i\n", getpid());

        while(k <= (numDescompo/2)+1){
            if((numDescompo % arrprimos[k]) == 0){  
                factores[i_factores] = arrprimos[k];  //x3
                numDescompo = numDescompo/arrprimos[k];         
                i_factores++;            
                continue;
            }     
            k = k + 3;  
        }
        printA(factores, i_factores);

    }
    return 0;
}