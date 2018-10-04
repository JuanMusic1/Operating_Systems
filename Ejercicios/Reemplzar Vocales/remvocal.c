#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

	FILE *archivo;
    char caracter;
    
	archivo = fopen ("bible.txt", "r+");
	if(archivo == NULL){
		fputs("No existe el archivo\n", stderr);
		exit(1);
	}

    while (fscanf(archivo,"%c",&caracter) != EOF){
        switch(caracter) {
            case 'a' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('e', archivo);
                fflush(archivo);
                break;
            case 'e' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('i', archivo);
                fflush(archivo);
                break;
            case 'i' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('o', archivo);
                fflush(archivo);
                break;
            case 'o' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('u', archivo);
                fflush(archivo);
                break;
            case 'u' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('a', archivo);
                fflush(archivo);
                break;
            case 'A' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('E', archivo);
                fflush(archivo);
                break;
            case 'E' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('I', archivo);
                fflush(archivo);
                break;
            case 'I' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('O', archivo);
                fflush(archivo);
                break;
            case 'O' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('U', archivo);
                fflush(archivo);
                break;
            case 'U' :
                fseek(archivo, -1, SEEK_CUR);
                fputc('A', archivo);
                fflush(archivo);
                break;
            default:
                
                break;

        }
    }
    
    printf("Listo \n");
    fclose(archivo);
    return 0;
}
