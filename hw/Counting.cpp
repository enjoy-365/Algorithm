#include <iostream>
#include <utility>
using namespace std;

int A[100003] = {};
int B[100003] = {};
int C[100003] = {};
pair<int, int> query[100003];

void counting(int n, int m){
    for(int i = 1; i <= n; i++){
        C[A[i]]++;
    }
    for(int i = 1; i<=m; i++){
        C[i] = C[i] + C[i-1];
    }
    /*for(int i = n; i > 0; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }*/
}

int main(void){
    int n, m, k;

    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++){
        cin >> query[i].first >> query[i].second;
    }
    for(int i = 1; i <= n; i++){    
        cin >> A[i];
    }
    
    counting(n, m);
    
    for(int i = 1; i <= k; i++){
        cout << C[query[i].second] - C[(query[i].first) -1] << "\n";
    }

    return 0;
}
