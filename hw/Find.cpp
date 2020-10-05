#include <iostream>
#include <utility>
using namespace std;

int A[100003] = {};
int C[100003] = {};
int cnt;

void counting(int n){
    for(int i = 1; i <= n; i++){
        C[A[i]]++;
    }
}


void counting2(int m){
    int temp;
    for(int i = 1; i <= m; i++){
        cin >> temp; 
        if(C[temp] > 0){
            cnt++;
            C[temp] = 0;
        }
    }
}



int main(void){
    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){    
        cin >> A[i];
    }
    
    counting(n);
    
    counting2(m);
    cout << cnt << "\n";

    return 0;
}
