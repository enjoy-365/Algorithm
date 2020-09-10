#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size);
void printArr(int arr[], int size);

int main(void){
    int arr[] = {22, 2, 4, 6, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, size);
    printArr(arr, size);

    return 0;
}

void insertionSort(int arr[], int size){
    for(int j = 1; j < size; j++ ){
        int key = arr[j];
        int i = j-1;
        while(i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

void printArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
