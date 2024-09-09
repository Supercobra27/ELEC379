#include <stdio.h>
#include <stdlib.h>

#define N 10

void merge(int** array, int p, int q, int r){
    int* left_array = malloc(sizeof(int)*(q+1));
    int* right_array = malloc(sizeof(int)*(r-q+2));
    int i, j, k;
    for(i = 0; i < q; i++){
        left_array[i] = *array[i];
        printf("%d ", left_array[i]);
    }

    for(i = 0; i < r - q; i++){
        right_array[i] = *array[i+q];
        printf("%d ", right_array[i]);
    }

    i = 0, j = 0, k = p;

    while(i < q+1 && j < (r-q+2)){
        if(left_array[i] <= right_array[j]){
            *array[k] = left_array[i];
            i++;
        }else{
            *array[k] = right_array[j];
            j++;
        }
        k++;
    }

    if(i < q+1){
        while(i < q+1){
            *array[k] = left_array[i];
            i++, k++;
        }
    }

    if(j < r-q+2){
        while(i < r-q+2){
            *array[k] = right_array[j];
            j++, k++;
        }
    }

    free(left_array);
    free(right_array);

}

void merge_sort(int** array, int p, int r){
    if(r == -1){
        r = N-1;
    }

    if(p >= r){
        return;
    }

    int q = (p+r) / 2;
    merge_sort(array, p, q);
    merge_sort(array, q + 1, r);
    merge(array, p, q, r);
}

int main(){
    int* array = malloc(sizeof(int)*N);
    if(array == NULL){
        printf("Memory allocation failed.");
        exit(1);
    }

    for(int i = 0; i < N; i++){
        array[i] = rand() >> 8;
        printf("%d ", array[i]);
    }

    merge_sort(&array, 0, -1);
    printf("Sorting");

    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}