#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <gmp.h>
#include <time.h>

typedef struct{
  mpz_t dato;
  struct Elemento *sgt;
}Elemento;

Elemento *primero = NULL;
Elemento *ultimo = NULL;

void add(Elemento *e){
  e -> sgt = NULL;
  if (primero==NULL){
    primero = e;
    ultimo = e;
  }else{
    ultimo -> sgt = e;
    ultimo = e;
  }
}

int *primos(int);
bool verificar(int);

int main(){

  printf("Inicio de la ejecucion del programa.\n");
  clock_t begin=clock();
  printf("Medida de inicio de ejecucion tomada.\n");

  int n;
  printf("Cuantos perfectos desea calcular? ");
  scanf("%d", &n);
  int *vec;
  vec = primos(n);
  Elemento *e1 = malloc(sizeof(Elemento));
  mpz_init(e1->dato);
  mpz_set_ui(e1->dato,6);
  add(e1);
  for (int i = 1; i < n; i++){
    mpz_t op1;
    mpz_init(op1);
    mpz_ui_pow_ui(op1, 2, vec[i]-1);
    mpz_t op2;
    mpz_init(op2);
    mpz_ui_pow_ui(op2, 2, vec[i]);
    mpz_sub_ui(op2, op2, 1);
    mpz_t val;
    mpz_init(val);
    mpz_mul(val, op1, op2);
    Elemento *e = malloc(sizeof(Elemento));
    mpz_init(e->dato);
    mpz_set(e->dato,val);
    add(e);
  }
  Elemento *i = e1;
  while (i!=NULL) {
    mpz_out_str(stdout,10,i->dato);
    printf ("\n \n");
    i = i->sgt;
  }

  clock_t end=clock();
  double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
  printf("El tiempo de ejecucion fue %f\n",time_spent);
  return 0;
}

bool verificar(int p){
  mpz_t s;
  mpz_init(s);
  mpz_set_ui(s,4);
  mpz_t M;
  mpz_init(M);
  mpz_ui_pow_ui(M, 2, p);
  mpz_sub_ui(M, M, 1);
  for (int i = 0; i < p-2; i++) {
    mpz_pow_ui(s, s, 2);
    mpz_sub_ui (s, s, 2);
    mpz_mod(s, s, M);
  }
  if (mpz_cmp_ui(s, 0)==0) {
    return true;
  }
  return false;
}

int *  primos(int n){
  static int * nums;
  nums = malloc(n * sizeof(int));
  nums[0]=2;
  int num = 1;
  int cont = 1;
  while (cont!=n){
    num+=2;
    int root = sqrt(num);
    int i = 0;
    bool flag = false;
    while (!flag && i<cont && nums[i]<=root){
      if (num%nums[i]==0) {
        flag = true;
      }
      i++;
    }
    if (!flag && verificar(num)) {
      nums[cont]=num;
      cont++;
    }
  }
  return nums;
}