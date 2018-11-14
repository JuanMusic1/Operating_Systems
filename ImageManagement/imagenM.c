#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearImg(char sys[], char imgN[], char bs[], char count[]){

		strcpy(sys, "dd if=/dev/zero bs=");
		strcat(sys, bs);
		strcat(sys, " count=");
		strcat(sys, count);
		strcat(sys, " of=");
		strcat(sys, imgN);
		//strcat(sys, ".img");
}

void formatearImg(char imgN[], char sys[]){

	FILE *fp;
	fp = fopen(imgN,"r");
	if (fp == NULL) {
		fputs ("File error",stderr);
		exit (1);
	} else {
		fclose (fp);
		strcpy(sys, "mkdosfs -F 16 ");
		strcat(sys, imgN);
		//strcat(sys, ".img");
	}

}

void mostrarInfo(char imgN[], char sys[]){

	FILE *fp;
	fp = fopen(imgN,"r");
	if (fp == NULL) {
		fputs ("File error",stderr);
		exit (1);
	} else {
		strcpy(sys, "fsstat ");
		strcat(sys, imgN);
		//strcat(sys, ".img");
	}

}

void montarImg(char imgN[], char sys[]){
	system("mkdir datos");
	strcpy(sys, "mount -o loop,rw "); 	
	strcat(sys, imgN); 	
	strcat(sys, " datos"); 
}

void desmontarImg(char imgN[], char sys[]){
	chdir("/home/juanmusic1/Operating_Systems/ImageManagement"); 	
	strcpy(sys, "umount datos/"); 
}

char* readinput() { 
	#define CHUNK 200    
	char* input = NULL;    
	char tempbuf[CHUNK];    
	size_t inputlen = 0, templen = 0;    
	do {        
		fgets(tempbuf, CHUNK, stdin);        
		templen = strlen(tempbuf);        
		inputlen += templen;        
		input = realloc(input, inputlen+1);        
		strcat(input, tempbuf);     
		} 
	while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');
	     return input; 
}


void crearArchivo(char img[], char sys[]){
	char str1[255];


	printf("Ingrese el nombre del archivo: ");
	scanf("%s", &str1);
	printf("Ingrese el contenido del archivo: ");
	char *a  = readinput();
	a = readinput();
	
	chdir("datos");
	strcpy(sys, "echo '");
	strcat(sys, a);
	strcat(sys, "' > ");
	strcat(sys, str1);
	strcat(sys,".txt");
	
}



void borrarArchivo(char fileN[], char sys[]){ 	
	strcpy(sys, "rm "); 	
	strcat(sys, fileN); 
}


void flsImg(char imgN[], char sys[]){ 	
	chdir("/home/juanmusic1/Operating_Systems/ImageManagement"); 	
	strcpy(sys, "fls "); 	
	strcat(sys, imgN); 
}

int main(int argc, char const *argv[]){

	//-----Cositas a usar-----
	char imgName[10];
	char bs[5];
	char count[6];
	char sys2[50];
	//char *a  = inputString(stdin, 10);
	//printf("%s", a);


	//-----Pido nombre imagen-----
	printf("Ingrese el nombre de la imagen con extencion prro :v\n");
	scanf("%s", &imgName);
	printf("\n");
	
	//-----Pido bs-----
	printf("Ingrese el bs prro :v\n");
	scanf("%s", &bs);
	printf("\n");

	//------Pido count-----
	printf("Ingrese el count prro :v\n");
	scanf("%s", &count);
	printf("\n");


	//-----Armo string para crear la imagen-----
	crearImg(&sys2, imgName, bs, count);
	//printf("%s", &sys2);
	system(sys2);

	//-----Formateo la imagen--------
	formatearImg(imgName, &sys2);
	//printf("%s", &sys2);
	system(sys2);

	//-----Muestro el contenido-----
	mostrarInfo(imgName, &sys2);
	//printf("%s", &sys2);
	system(sys2);

	//------Montar la imagen-------- 	
	montarImg(imgName, &sys2);
	//printf("%s", &sys2); 	
	system(sys2);

	char *des;
	int i = 1;
	while(i){
		printf("Seleccione la accion a realizar\n");
		printf("A)Crear archivo B)Borrar archivo C)Salir\n");

		des = readinput();
		switch(*des){
			case 'A' :
				//------Crear Archivos------
				crearArchivo(imgName,&sys2);
				//printf("%s", &sys2); 	
				system(sys2);
				printf("Archivo creado\n");
				break;
			case 'B' :
				//Borrar archivo de la imagen 	
				//chdir("datos"); //Donde se esta montando la imagen 	
				system("ls"); 	
				char fileN[255]; 	
				printf("Nombre del archivo a borrar: "); 	
				scanf("%s", &fileN); 	
				borrarArchivo(fileN, &sys2); 	
				system(sys2); 	
				system("ls");
				printf("Archivo borrado\n");
				break;
			case 'C' :
				i = 0;
				break;
		}
	}
	//-------Desmontar la imagen -------	
	desmontarImg(imgName, &sys2);
	//printf("%s", &sys2); 	
	system(sys2);

	
	//-----Fls de la imagen----- 	
	flsImg(imgName, &sys2); 
	//printf("%s", &sys2); 	
	system(sys2);


	return 0;
}