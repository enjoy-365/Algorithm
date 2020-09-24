//2018008213_Kim.Hyunjung
#include <iostream>
#include <stdlib.h>

using namespace std;

int arr[30002];

void insertionSort(int size);
void printArr(int size);

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    insertionSort(n);
    printArr(n);

    return 0;
}

void insertionSort(int size){
    for(int j = 1; j < size; j++){
        int key = arr[j];
        int i = j-1;
        while(i >= 0 && arr[i] < key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

void printArr(int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << "\n";
    }
}
