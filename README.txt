Programa:

    lee un archivo llamado tweets.csv, luego de leerlo y alamacenarlo, crea un identificador de forma que sea posible ordenar
    los datos en orden segun su fecha, estos datos ordenados luego son buscados para con un vector hash hallar un mensaje oculto
  



Para compilar:
- Debe estar en el directorio los archivos "main.c" "sorting.c" "head.h"
- Debe tener instalado el compilador gcc

Para su ejecución:
- Debe ingresar el nombre del ejecutable compilado junto con el archivo (ej: "./main tweets.csv")



Intrucciones de complicacion:

# gcc -o main.c sorting.c 

Makefile->

  #TEST:  gcc -o main.o sorting.o 

  #	$(CC) -o $@ main.o sorting.o  $(FLAGS)


  #main.o: main.c
  #	$(CC) -c main.c $(FLAGS)

  #sorting.o: sorting.c
  #	$(CC) -c sorting.c $(FLAGS)






Francisco Zuñiga | Paralelo 200| Rol: 202130509-2
