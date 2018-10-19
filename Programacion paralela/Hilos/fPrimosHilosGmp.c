#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <gmp.h>


typedef struct{
	mpz_t n;
	struct Nodo *sig;
}Nodo;
Nodo *primerPrimo=NULL;
Nodo *ultimoPrimo=NULL;

void agregarPrimo(mpz_t n){
	Nodo *nodo=malloc(sizeof(Nodo));
	mpz_init(nodo->n);
	mpz_set(nodo->n,n);
	if(primerPrimo==NULL){
		primerPrimo=nodo;
		ultimoPrimo=nodo;
	}else{
		ultimoPrimo->sig=nodo;
		ultimoPrimo=nodo;
	}
}
void imprimirPrimos(){
	Nodo *i=primerPrimo;
	while(i!=NULL){
		mpz_out_str(stdout,10,i->n);
		printf("\n");
		i=i->sig;
	}
}

Nodo *primerFactor=NULL;
Nodo *ultimoFactor=NULL;

void agregarFactor(mpz_t n){
	Nodo *nodo=malloc(sizeof(Nodo));
	mpz_init(nodo->n);
	mpz_set(nodo->n,n);
	if(primerFactor==NULL){
		primerFactor=nodo;
		ultimoFactor=nodo;
	}else{
		ultimoFactor->sig=nodo;
		ultimoFactor=nodo;
	}
}
void imprimirFactor(){
	Nodo *i=primerFactor;
	while(i!=NULL){
		
		mpz_out_str(stdout,10,i->n);
		printf(" ");
		i=i->sig;
	}
}

//defino donde comienza y termina de calcular primos
	mpz_t a;
	
	mpz_t b;
	
	mpz_t input;
	


void nPrimos(){
	mpz_t raiz;
	mpz_init(raiz);
	mpz_sqrt(raiz,input);
	mpz_t i;
	mpz_init(i);
	for(mpz_set(i,a);mpz_cmp(i,b)<=0;mpz_add_ui(i,i,2)){
		if(mpz_cmp_ui(i,2)==0){
			agregarPrimo(i);
			mpz_sub_ui(i,i,1);
			
		}else{
			long divisores=0;
			mpz_t raiz;
			mpz_init(raiz);
			mpz_sqrt(raiz,i);
			Nodo *j=primerPrimo;
			while(j!=NULL && mpz_cmp(j->n,raiz)<=0  && divisores==0){
				mpz_t mod;
				mpz_init(mod);
				mpz_mod(mod,i,j->n);
				if(mpz_cmp_ui(mod,0)==0){
					
					divisores++;
				}
				j=j->sig;
			}
			if(divisores==0 && mpz_cmp_ui(i,1)!=0){
				agregarPrimo(i);
			}
		}

		
	}
	mpz_t aux;
	mpz_init(aux);
	mpz_set(aux,b);
	mpz_add_ui(aux,aux,2);
	
	mpz_set(a,aux);

	mpz_add_ui(b,b,80);
	if(mpz_cmp(b,input)>0){
		mpz_set(b,input);
	}
}


pthread_mutex_t lockFact;


mpz_t res;



void funcion1(){
	pthread_mutex_lock( &lockFact);
	

	Nodo *n1=primerPrimo;
	while(n1!=NULL && mpz_cmp(input,res)!=0){
		mpz_t mod;
		mpz_init(mod);
		mpz_mod(mod,input,n1->n);
		//printf("--------1\n");
		if(mpz_cmp_ui(mod,0)==0){
			printf("entra ");
			mpz_out_str(stdout,10,n1->n);
			printf("\n");
			agregarFactor(n1->n);
			mpz_mul(res,res,n1->n);
			mpz_t aux;
			mpz_init(aux);
			mpz_cdiv_q(aux,input,n1->n);
			mpz_mod(mod,aux,n1->n);
			//printf("-------2\n");
			while(mpz_cmp_ui(mod,0)==0){
				printf("entra ");
				mpz_out_str(stdout,10,n1->n);
				printf("\n");
				agregarFactor(n1->n);
				mpz_cdiv_q(aux,aux,n1->n);
				mpz_mul(res,res,n1->n);
				mpz_mod(mod,aux,n1->n);
			}
		}
		if(n1->sig ==NULL)
			nPrimos();
		n1=n1->sig;
		if(n1!= NULL && n1->sig ==NULL)
			nPrimos();
		if(n1!=NULL)
			n1=n1->sig;
		if(n1!= NULL && n1->sig ==NULL)
			nPrimos();
		if(n1!=NULL)
			n1=n1->sig;
		//nPrimos();
	}
		

	pthread_mutex_unlock( &lockFact);
}
void funcion2(){
	pthread_mutex_lock( &lockFact);
	

	Nodo *n1=primerPrimo;
	n1=n1->sig;
	while(n1!=NULL && mpz_cmp(input,res)!=0){
		mpz_t mod;
		mpz_init(mod);
		mpz_mod(mod,input,n1->n);
		//printf("--------1\n");
		if(mpz_cmp_ui(mod,0)==0){
			printf("entra ");
			mpz_out_str(stdout,10,n1->n);
			printf("\n");
			agregarFactor(n1->n);
			mpz_mul(res,res,n1->n);
			mpz_t aux;
			mpz_init(aux);
			mpz_cdiv_q(aux,input,n1->n);
			mpz_mod(mod,aux,n1->n);
			//printf("-------2\n");
			while(mpz_cmp_ui(mod,0)==0){
				printf("entra ");
				mpz_out_str(stdout,10,n1->n);
				printf("\n");
				agregarFactor(n1->n);
				mpz_cdiv_q(aux,aux,n1->n);
				mpz_mul(res,res,n1->n);
				mpz_mod(mod,aux,n1->n);
			}
		}
		if(n1->sig ==NULL)
			nPrimos();
		n1=n1->sig;
		if(n1!= NULL && n1->sig ==NULL)
			nPrimos();
		if(n1!=NULL)
			n1=n1->sig;
		if(n1!= NULL && n1->sig ==NULL)
			nPrimos();
		if(n1!=NULL)
			n1=n1->sig;
		//nPrimos();
	}
		
	pthread_mutex_unlock( &lockFact);
}
void funcion3(){
	pthread_mutex_lock( &lockFact);

	Nodo *n1=primerPrimo;
	n1=n1->sig;
	if(n1!=NULL)
		n1=n1->sig;
	while(n1!=NULL && mpz_cmp(input,res)!=0){
		mpz_t mod;
		mpz_init(mod);
		mpz_mod(mod,input,n1->n);
		//printf("--------1\n");
		if(mpz_cmp_ui(mod,0)==0){
			printf("entra ");
			mpz_out_str(stdout,10,n1->n);
			printf("\n");
			agregarFactor(n1->n);
			mpz_mul(res,res,n1->n);
			mpz_t aux;
			mpz_init(aux);
			mpz_cdiv_q(aux,input,n1->n);
			mpz_mod(mod,aux,n1->n);
			//printf("-------2\n");
			while(mpz_cmp_ui(mod,0)==0){
				printf("entra ");
				mpz_out_str(stdout,10,n1->n);
				printf("\n");
				agregarFactor(n1->n);
				mpz_cdiv_q(aux,aux,n1->n);
				mpz_mul(res,res,n1->n);
				mpz_mod(mod,aux,n1->n);
			}
		}
		if(n1->sig ==NULL)
			nPrimos();
		n1=n1->sig;
		if(n1!= NULL && n1->sig ==NULL)
			nPrimos();
		if(n1!=NULL)
			n1=n1->sig;
		if(n1!= NULL && n1->sig ==NULL)
			nPrimos();
		if(n1!=NULL)
			n1=n1->sig;
		//nPrimos();
	}
		

	pthread_mutex_unlock( &lockFact);
}

	


int main(int argc, char const *argv[]){

	printf("Inicio de la ejecucion del programa.\n");
    clock_t begin=clock();
    printf("Medida de inicio de ejecucion tomada.\n");

	mpz_init(input);
	mpz_set_str(input,argv[1],10);

	mpz_init(res);
	mpz_set_ui(res,1);
	

	mpz_init(a);
	mpz_set_ui(a,2);
	mpz_init(b);
	mpz_add_ui(b,b,9);
	if(mpz_cmp(b,input)>0){
		mpz_set(b,input);
	}

	

	nPrimos();
	//imprimirPrimos();


	pthread_t thread1, thread2, thread3;
	
	pthread_create( &thread1, NULL, &funcion1, NULL);
    pthread_create( &thread2, NULL, &funcion2, NULL);
    pthread_create( &thread3, NULL, &funcion3, NULL);
 
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    pthread_join( thread3, NULL);
 	
 	imprimirFactor();
 	printf("\n");

 	//imprimirPrimos();

 	clock_t end=clock();
    double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("El tiempo de ejecucion fue %f\n",time_spent);
 
    exit(EXIT_SUCCESS);


	
	
}
