#include "head.h"


int main(int argc, char *argv[]){

    int largo = large(argv[1]); // lee para guardar la cantidad de lineas

    //ORDENAMIENTO

    tweet *array = leer(argv[1], largo);
    id(array, largo); // Genera id para cada tweet 

    // Insertion sort

    //insertionsort(array, largo); 

    libre(array, largo);
    free(array);


    tweet *array2 = leer(argv[1], largo);
    id(array2, largo); // Genera id para cada tweet 

    // Merge sort

    mergesort(array2, 0, largo);
    
    libre(array2, largo);
    free(array2);

    // Radix sort

    tweet *array3 = leer(argv[1], largo);
    id(array3, largo); // Genera id para cada tweet 

    radixsort(array3, largo);




    // MENSAJE


    mensaje("keys.txt", array3);

    libre(array3, largo);
    free(array3);
    

    return 0;

};

   




