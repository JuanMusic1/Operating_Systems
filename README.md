# Sistemas Operativos
Repositorio con ejercicios y trabajos del curso de Sistemas Operativos de la Universidad EIA 2018-2 


### Dependencias

Se necesita en general el lenguaje [C](https://es.wikipedia.org/wiki/C_(lenguaje_de_programaci%C3%B3n)).

Instala las dependencias para usar.

```sh
$ sudo apt-get install lpthread libgmp3 
$ sudo service apache2 restart
```
El repositourio usa archivos Makefile para hacer mas facil la compilacion

Cada archivo Makefile tiene las opciones
```sh
$ make //para compilar todos los ararchivos en C
$ make <tipo de compilacion> // para compilar uno en especifico
$ make debug //para debuguear el codigo
```
