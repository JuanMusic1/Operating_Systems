
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define clear() printf("\033[H\033[J")

typedef struct {
    int dato;
    struct Nodo *sigt;
}Nodo;

Nodo *primer = NULL;
Nodo *ultimo = NULL;

Nodo *primerG = NULL;
Nodo *ultimoG = NULL;

void add(Nodo *nodo){
    nodo -> sigt = NULL;
    if(primer == NULL){
        primer = nodo;
        ultimo = nodo;
    } else { 
        ultimo -> sigt = nodo;
        ultimo = nodo;
    }
}
void addG(Nodo *nodo){
    nodo -> sigt = NULL;
    if(primer == NULL){
        primerG = nodo;
        ultimoG = nodo;
    } else { 
        ultimoG -> sigt = nodo;
        ultimoG = nodo;
    }
}

void agregar(int num){
    Nodo *temp = malloc(sizeof(Nodo));
    temp -> dato = num;
    add(temp);

}

void agregarG(int num){
    Nodo *temp = malloc(sizeof(Nodo));
    temp -> dato = num;
    addG(temp);

}

void genPrimosCriba(int tam, Nodo *mento){
    int i, h;
    Nodo *m;
    agregarG(0);
    agregarG(0);
    for(i = 2; i <= tam; ++i){ 
        agregarG(1);
    }
    Nodo *i = primerG;
    while(i != NULL){
        if(i->dato){
            for(h = 2; (i->dato*h) <= tam; ++h){
                
            }
        }
    }
    for(i = 2; i*i <= tam; ++i) {
        if(m[i]) {
            for(h = 2; i*h <= tam; ++h)
                m[i*h] = 0;
        }
    }
    int inde = 0;

    for(i = 0; i<=tam; i++){
        if(m[i] == 1){
            mento[inde] = i;
            inde++;
        }
    }
}


void printNodos(Nodo *nod){
    Nodo *i = nod;
    while(i != NULL){
        printf("%i\n", i->dato);
    }
}


int main(){
    int numDescompo;
    //Pide el numero a descomponer
    printf("Ingrese el numero a descomponer\n");
    scanf("%d", &numDescompo);
    printf("\n");

    Nodo *primerNodo = malloc(sizeof(Nodo));
    primerNodo -> dato = 5;

    add(primerNodo);

   
    genPrimosCriba(numDescompo, arrprimos);
    
    int factores[(numDescompo/2)];
    int i_factores = 0;
    //Info Muestral, son estudios adicionales que permitan adiconar info algo


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
        while(i <= (numDescompo/2)+1){
            if((numDescompo % arrprimos[i]) == 0){  
                factores[i_factores] = arrprimos[i];  //aqui falta algo
                numDescompo = numDescompo/arrprimos[i];         
                i_factores++;            
                continue;
            }     
            i = i + 3;  
        }
        printA(factores, i_factores);

    } else if(proces2 == 0){
        printf("Proceso 2 con PID %i\n", getpid());
        while(j <= (numDescompo/2)+1){
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