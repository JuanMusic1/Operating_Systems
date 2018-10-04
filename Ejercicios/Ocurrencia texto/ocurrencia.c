#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


 //lista ligada para recorrer esto
typedef struct Nodo{
    char letra;
	int cantidad;
    struct Nodo *siguiente;
}Nodo;

Nodo *primero = NULL;
Nodo *ultimo = NULL;

void agregar(Nodo *nodo){
    nodo -> siguiente = NULL;
    if(primero == NULL){
        primero = nodo;
        ultimo = nodo;
    } else {
        ultimo -> siguiente = nodo;
        ultimo = nodo;
    }
}

int main() {

	char caracter;
	FILE *archivo;
	archivo = fopen ("bible.txt", "r+t");
	Nodo *primer = malloc(sizeof(Nodo));
	if(archivo == NULL){
		fputs("No existe el archivo\n", stderr);
		exit(1);
	} else {
		caracter = fgetc(archivo);
		primer -> letra = caracter;
		primer -> cantidad = 0;
		primer -> cantidad++;
		agregar(primer);

		while((caracter = fgetc(archivo)) != EOF){
			Nodo *i = primero;
			int siMetio = 1;
			while(i != NULL){
				
				if(caracter == (i -> letra)){
					i -> cantidad++;
					siMetio = 0;
				}
				i = i -> siguiente;
				
			}
			if(siMetio){
				Nodo *agreg = malloc(sizeof(Nodo));
				agreg -> letra = caracter;
				agreg -> cantidad = 0;
				agreg -> cantidad++;
				agregar(agreg);
				//i = NULL;
			}
			
		}
	}

	Nodo *i = primero;
    while(i != NULL){
		if((i -> letra) == 10){
        	printf("Cantidad de caracteres ENTER: %d \n", i -> cantidad);
        	
		} else if((i -> letra) == 13){
					printf("Cantidad de caracteres /r: %d \n", i -> cantidad);
			
		} else {
			printf("Cantidad de caracteres %c: %d \n", i -> letra, i -> cantidad);
		}
		i = i -> siguiente;
    }

	fclose(archivo);
	return 0;
}