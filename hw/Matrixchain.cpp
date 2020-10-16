#include <iostream>
#include <climits>

using namespace std;

int p[105];
int m[105][105];
int s[105][105];
int n;

void chainOrder();
void printParens(int i, int j);
int main(void){
    cin >> n;

    for(int i = 0; i < n+1; i++){
        cin >> p[i];
    }

    chainOrder();

    cout << m[1][n] << "\n";

    

    return 0;
}

void chainOrder(){
    for(int i = 1; i < n+1; i++){
        m[i][i] = 0;
    }
    for(int l = 2; l < n+1; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return;
}
void pirntParens(int i, int j){

}
