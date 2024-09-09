#include <stdio.h>
#include <stdlib.h>

#define N 10

void insertion_sort(int* array, size_t count){
    int key, j, i;
    for(i = 0; i < count; i++){
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

int main(){
    int *array = malloc(sizeof(int)*N);
    if(array == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    int i;
    for(i = 0; i < N; i++){
        array[i] = rand() >> 8;
        printf("%d ", array[i]);
    }

    printf("\n");

    insertion_sort(array,N);
    for(i = 0; i < N; i++){
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}