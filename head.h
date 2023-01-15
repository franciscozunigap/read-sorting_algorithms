#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>



typedef struct twitter {
long int id; //Dato creado en relación a la fecha y hora del tweet
char *fecha; 
char *hora;
char *user;
char *mensaje;
} tweet ;




// Lectura y asignación
int large(char *nombre_archivo); // retorna el largo del archivo
tweet *leer(char *nombre_archivo, int largo); // lee y asigna a un arreglo los datos
void id(tweet *array, int largo); // crea un identificador para cada tweet
void print(tweet *arr, int n); //Imprime el arreglo 



// Insertion sort
void insertionsort(tweet *arr, int n); // Ordenamiento (O(n´2)) con reporte


// Merge sort
void mergeSort (tweet *arr , long int left , long int right);
void merge(tweet *arr, long int l, long int m, long int r);
void mergesort(tweet *arr , long int left , long int right); //  // Ordenamiento (O(nlogn)) con reporte



// Radix sort
int getMax(tweet *arr, long int n);
void countSort(tweet *array, long int n, long int exp);
void radixsort(tweet *arr, long int n);  // Ordenamiento (O(n)) con repote



// Reporte
void reporte(clock_t begin, char *sort, char *complejidad); // Genera un reporte.txt con el tiempo de ejecucion del algoritmo y su complejidad

// Mensaje
void mensaje(char *nombre_archivo, tweet *array); // Genera un mensaje.txt en donde se encuenta el mensaje oculto

//Free
void libre(tweet *array, int largo); // Libera la memoria reservada para los datos tweets del arreglo