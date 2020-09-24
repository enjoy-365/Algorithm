#include <iostream>
#include <stdlib.h>
#include <limits.h>


using namespace std;

int arr[100005];

void Merge(int p, int q, int r);
void Merge_Sort(int p, int r);
void printArr(int n);

int main(void){
    int n;
    cin >> n;
    arr[0] = -1;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    Merge_Sort(1, n);
    printArr(n);

    return 0;
}

void Merge(int p, int q, int r){
        int n1 = q-p+1;
        int n2 = r-q;

        int L[n1+2];
        int R[n2+2];

        for(int i=1; i <= n1; i++){
            L[i] = arr[p + i-1];
        }
        for(int j = 1; j <= n2; j++){
            R[j] = arr[q+j];
        }
        L[n1+1] = INT_MIN;
        R[n2+1] = INT_MIN;

        int i = 1;
        int j = 1;

        for(int k = p; k <= r; k++){
            if(L[i] >= R[j]){
                arr[k] = L[i];
                i = i+1;
            }else{
                arr[k] = R[j];
                j = j + 1;
            }
        }
}

void Merge_Sort(int p, int r){
    if(p < r){
        int q = (p + r)/2;
        Merge_Sort(p, q);
        Merge_Sort(q+1, r);
        Merge(p, q, r);
    }
}

void printArr(int n){
    for(int i= 1; i <=n; i++){
        cout << arr[i] << "\n";
    }
}
