#include <iostream>

using namespace std;

int heap[100003];
int top[100003];

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

void insert(int n, int key){
    heap[n] = key;
    int parent = (n-1)/2;
    for(int i = n; heap[parent] < key; i = (i-1)/2){
            swap(parent, i);
    
    }
}

int main(){

    int cmd, a, b;
    int cnt = 0;
    int cnt2 = 0;
    while(1){
        cin >> cmd;

        if(cmd == 0) break;
        else if(cmd == 1){
            cin >> a;
            insert(cnt, a);
            cnt++;

            /*for(int i = 0; i < cnt; i++){
                cout << heap[i] << " ";
            }
            cout << "\n";*/
        }
        else if(cmd == 2){
            top[cnt2] = heap[0];
            heap[0] = heap[cnt-1];
            buildheap(cnt-1,0);
            cnt2++;
            cnt--;

        }else if(cmd == 3){
            cin >> a >> b;

            heap[a-1] = b;
            for(int i = a-1; i >= 0; i--){
                buildheap(cnt, i);
            }
        }
    }

    for(int i = 0; i < cnt2 ; i++){
        cout << top[i] << " ";
    }
    cout << "\n";
    
    for(int i = 0; i < cnt;i++){
        cout << heap[i] << " ";
    }
    cout << "\n";
    return 0;
}
