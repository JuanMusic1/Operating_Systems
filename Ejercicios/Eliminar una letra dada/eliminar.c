#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Inicio de la ejecucion del programa.\n");
    clock_t begin=clock();
    printf("Medida de inicio de ejecucion tomada.\n");
    int num;
    char caracterelim;
    FILE *archivo;
    char caracter;
    
    archivo = fopen ("bible.txt", "r+");
    if(archivo == NULL){
        fputs("No existe el archivo\n", stderr);
        exit(1);
    }
    
    printf("Ingrese la letra a eliminar del fichero\n");
    scanf("%c",&caracterelim);

    while (fscanf(archivo,"%c",&caracter) != EOF){
        if (caracter == caracterelim){
            fseek(archivo, -1, SEEK_CUR);
            fputc(' ', archivo);
            fflush(archivo);
        }
    }
    
    printf("Listo\n");
    fclose(archivo);

    clock_t end=clock();
    double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("El tiempo de ejecucion fue %f\n",time_spent);
    
    return 0;
}