//2018008213_Kim Hyunjung_11802
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int s[3][102];
int a[3][102];
int t[3][102];
int l[3][102];
int e1;
int e2;
int x1;
int x2;
int lastStation;

int fastestWay(int n){
    int ans;
    s[1][1] = e1 + a[1][1];
    s[2][1] = e2 + a[2][1];

    for(int j = 2; j <= n; j++){
        if(s[1][j-1] <= s[2][j-1] + t[2][j-1]){
            s[1][j] = s[1][j-1] + a[1][j];
            l[1][j] = 1;
        }else{
            s[1][j] = s[2][j-1] + t[2][j-1] + a[1][j];
            l[1][j] = 2;
        }
        if(s[2][j-1] <= s[1][j-1] + t[1][j-1]){
            s[2][j] = s[2][j-1] + a[2][j];
            l[2][j] = 2;
        }else{
            s[2][j] = s[1][j-1] + t[1][j-1] + a[2][j];
            l[2][j] = 1;
        }
    }
    if(s[1][n] + x1 <= s[2][n] + x2){
        ans = s[1][n] + x1;
        lastStation = 1;
    }else{
        ans = s[2][n] + x2;
        lastStation = 2;
    }   
    return ans;
}

void printStation(int last, int n){
    int i = last;
    stack<pair<int, int>> s;
    s.push({i, n});
    for(int j = n; j > 1; j--){
        i = l[i][j];
        s.push({i, j-1});
    }
    while(!s.empty()){
        int ans1 = s.top().first;
        int ans2 = s.top().second;
        s.pop();
        cout << ans1 << " " << ans2 << "\n";
    }
}

int main(void){
    int n;
    cin >> n >> e1 >> e2 >> x1 >> x2; //station num, initials, finals
    for(int i = 1; i <= n; i++){
        cin >> a[1][i];
    }
    for(int j = 1; j <= n; j++){
        cin >> a[2][j];
    }
    for(int k = 1; k < n; k++){
        cin >> t[1][k];
    }
    for(int w = 1; w <n; w++){
        cin >> t[2][w];
    }

    int ans = fastestWay(n);
    cout << ans << "\n";
    printStation(lastStation, n);

    return 0;
}
