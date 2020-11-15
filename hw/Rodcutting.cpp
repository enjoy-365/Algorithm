//2018008213_KimHyunjung_11802
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int p[103];
int r[103];
int s[103];
int ans[102];

void cutRod(int n){
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        int q = INT_MIN;
        for(int i = 1; i <= j; i++){
            if(q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

void printRod(int n){
    int cnt = 0;
    int num = n;
    while(n > 0){
        ans[cnt] = s[n];
        n = n-s[n];
        cnt++;
    }
    sort(ans, ans+cnt);
    for(int i = 0; i < cnt; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(void){
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    cutRod(n);
    cout << r[n] << "\n";
    printRod(n);

    return 0;
}
