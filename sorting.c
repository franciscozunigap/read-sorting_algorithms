#include "head.h"
//Tareas: 
    //Reporte


// Lectura y asignación

int large(char *nombre_archivo){ 
    FILE *archivo = fopen(nombre_archivo,"r");
    int lineas;
    char linea[5000];
    while (!feof(archivo)) {
        fgets(linea,sizeof(linea),archivo); 
        lineas++;

    }
    fclose(archivo);


    return lineas;
}

tweet *leer(char *nombre_archivo, int largo){
    FILE *datos = fopen(nombre_archivo,"r");

    int large_linea = 3000;
    char linea[large_linea];

    tweet *tweets = malloc(sizeof(tweet)*largo); //Reservo memoria para el arreglo
    int i=0;
    for(i=0;i<largo;i++){
        fgets(linea,sizeof(linea),datos); 


        char *str = strtok(linea, ";");
        tweets[i].fecha = malloc(sizeof(char*)*strlen(str));
        strcpy(tweets[i].fecha, str);

        str = strtok(NULL, ";");
        tweets[i].hora = malloc(sizeof(char*)*strlen(str));
        strcpy(tweets[i].hora, str);

        str = strtok(NULL, ";");
        tweets[i].user = malloc(sizeof(char*)*strlen(str));
        strcpy(tweets[i].user, str);

        str = strtok(NULL, "");
        tweets[i].mensaje = malloc(sizeof(char*)*strlen(str)); 
        strcpy(tweets[i].mensaje, str);
    
        
    }

    fclose(datos);

    return tweets;
}
      
void id(tweet *array, int largo){
    struct tm time;
    int i;
    for(i=0; i<largo;i++){
        sscanf(array[i].fecha, "%d-%d-%d", &time.tm_year, &time.tm_mon, &time.tm_mday);
        sscanf(array[i].hora, "%d:%d:%d", &time.tm_hour, &time.tm_min, &time.tm_sec);
    

        time.tm_year -= 1900;
        time.tm_mon -= 1;
        time.tm_isdst = 0;
    
        array[i].id = mktime(&time);

    }

}

void print(tweet *arr, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("[fecha: %s  hora: %s]\n", arr[i].fecha, arr[i].hora);
        
}

void libre(tweet *array, int largo){
    int i;
    for(i=0;i<largo;i++){
        free(array[i].fecha);
        free(array[i].hora);
        free(array[i].user);
        free(array[i].mensaje);

    }

    
}



// Insertion sort

void insertionsort(tweet *arr, int n){
    clock_t insertion = clock();
    long int i, j;
    tweet key;

    for(i=0 ; i < n ; i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j].id > key.id){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    reporte(insertion, "Insertion sort: \n", "O(n2)");
    
}


// Merge sort

void merge(tweet *arr, long int l, long int m, long int r){

    long int i, j, k;
    long int n1 = m - l + 1;
    long int n2 = r - m;
    
    tweet *L = malloc(sizeof(tweet)*n1);
    tweet *R = malloc(sizeof(tweet)*n2);
 

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort (tweet *arr , long int left , long int right) { 

    if (left < right) {

        long int m = left + (right - left) / 2;

        mergeSort(arr , left , m);
        mergeSort (arr , m+1 , right);
        merge(arr , left , m , right);
    }
    

}

void mergesort(tweet *arr , long int left , long int right){
    clock_t merge = clock();
    mergeSort (arr , left , right);
    reporte(merge, "Merge: \n", "O(nlogn)");

}

// Radix sort

int getMax(tweet *arr, long int n) {
    long int mx = arr[0].id;
    long int i;
    for (i = 1; i < n; i++)
        if (arr[i].id > mx)
            mx = arr[i].id;
    return mx;
}

void countSort(tweet *array, long int n, long int exp) {
    tweet *output = malloc(sizeof(tweet)*n); // output array
    long int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(array[i].id / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i].id / exp) % 10] - 1] = array[i];
        count[(array[i].id / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        array[i] = output[i];
        
}

void radixsort(tweet *arr, long int n) {
    clock_t radix = clock();// RELOJ
    long int m = getMax(arr, n);
    long int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);

    reporte(radix, "Radixsort: \n", "O(n)");
}


// Reporte

void reporte(clock_t begin, char *sort, char *complejidad){
    // Tiempo de ejecución
    // Complejidad
    clock_t end = clock(); // Mostrará tiempo de ejecución
    double time_spent = 0.0;
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    FILE *msj = fopen("Reporte.txt","a");
 
    fprintf(msj, "%s\n", sort);  
    fprintf(msj,"Complejidad algoritmica: %s \n", complejidad);
    fprintf(msj,"Tiempo de ejecución: %f segundos\n\n\n", time_spent);

}



// Mensaje

void mensaje(char *nombre_archivo, tweet *array){
    FILE *keys = fopen(nombre_archivo,"r"); // abrir archivo
    char linea[4000];
    fgets(linea,sizeof(linea), keys); //leer linea completa
    char *num = strtok(linea, " ");
    int pos;
    int i=0;
    FILE *msj = fopen("Mensaje.txt","w");


    if(num != NULL){
        while (num != NULL){
            i++;

            //buscar
            sscanf(num,"%d",&pos);
            if(array[pos].mensaje != NULL){
                //printf("%s\n", array[pos].mensaje);
                fprintf(msj, "%s\n", array[pos].mensaje);

            }else{
                printf(" ");
            }
            
            num = strtok(NULL, " ");
        }

    
}


    fclose(keys);
    fclose(msj);

}
