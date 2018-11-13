#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){

	//Cositas a usar
	//char *carpeta= "datos";
	char imgName[5];
	char bs[5];
	char count[5];
	char sys2[50];

	//Pido nombre imagen
	printf("Ingrese el nombre de la imagen prro :v\n");
	scanf("%s", &imgName);
	printf("\n");
	//printf("%s",&imgName);

	//Pido bs
	printf("Ingrese el bs prro :v\n");
	scanf("%s", &bs);
	printf("\n");

	//Pido count
	printf("Ingrese el count prro :v\n");
	scanf("%s", &count);
	printf("\n");

	printf("Listo, ahora armare la imagen prro :v \n");

	//Armo string para crear la imagen

	strcpy(sys2, "dd if=/dev/zero bs=");
	strcat(sys2, &bs);
	strcat(sys2, " count=");
	strcat(sys2, &count);
	strcat(sys2, " of=");
	strcat(sys2, &imgName);
	strcat(sys2, ".img");
	//printf("%s", &sys2);
	system(sys2);

	//Formateo la imagen
	strcpy(sys2, "mkdosfs -F 16 ");
	strcat(sys2, &imgName);
	strcat(sys2, ".img");
	//printf("%s", &sys2);
	system(sys2);

	//Muestro el contenido
	strcpy(sys2, "fsstat ");
	strcat(sys2, &imgName);
	strcat(sys2, ".img");

	printf("%s", &sys2);
	system(sys2);


	/*system("dd if=/dev/zero bs=1024 count=5000 of=1.img");  CHECK
	system("mkdosfs -F 16 1.img");
	system("fsstat 1.img");
	system("mkdir datos");
	system("mount -o loop,rw 1.img datos");
	chdir(carpeta);
	system("echo 'hola' >1.txt");
	//aqui borra
	system("rm -rf");//borra
	carpeta="Final"; //donde estoy creando la imagen
	chdir(carpeta);
	system("umount /datos");
	system("fls 1.img");*/
	
	/*int a;                                                                     
    char buf[BUFSIZ];                                                          

    printf("Please enter a number:\n");                                        
    scanf("%d",&a);                                                            
    printf("Your number is: %d\n",a);                                          
    snprintf(buf, sizeof(buf), "echo %d",a);                                   
    system(buf);*/

	return 0;
}