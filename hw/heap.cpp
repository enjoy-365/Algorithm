#include <iostream>

using namespace std;

int heap[100003];

void swap(int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

void buildheap(int n, int i){
    int parent = i;
    int left = 2*i + 1;
    int right = 2*i +2;

    int large = parent;
    if(left < n && heap[left] > heap[large]){
        large = left;
    }
    if(right < n && heap[right] >= heap[large]){
        large = right;
    }
    if(large != parent){
        swap(large, parent);
        
        buildheap(n, large);
    }
}

void heapsort(int n, int k){
    for(int i = (n-1)/2; i >= 0; i--){
        buildheap(n, i);
    }

    for(int i = 0; i < k; i++){
        /*for(int j = 0;  j< n; j++){
            cout << heap[j] << " " ;
        }
        cout << "\n";*/

        cout << heap[0] << " ";
        heap[0] = heap[n-i-1];
        
        
        /*for(int j = 0;  j < n-i-1; j++){
            cout << heap[j] << " " ;
        }
        cout << "\n";*/

        buildheap(n-i-1, 0);
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i <n; i++){
        cin >> heap[i];
    }

    heapsort(n, k);
    cout << "\n";

    for(int i = 0; i < n-k; i++){
        cout << heap[i] << " ";
    }
    cout << "\n";

    return 0;
}
