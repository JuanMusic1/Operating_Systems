#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
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
    return 0;
}