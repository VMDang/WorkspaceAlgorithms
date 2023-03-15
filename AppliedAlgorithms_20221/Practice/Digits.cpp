#include<bits/stdc++.h>
using namespace std;
const int MAX = 26;
int n;
int x[MAX]; // x[0] = I, x[1] = C, x[2] = T, x[3] = H, x[4] = U, x[5] = S, x[6] = K
bool visited[MAX];
int cnt;

void input(){
    for(int i=0; i<MAX; i++)
        visited[i] = false;
    cnt = 0;
}

bool check(int a, int i){
    if(a == 0 && i == 0) return false;
    if(a == 3 && i == 0) return false;
    if(a == 6 && i == 0) return false;
    if(visited[i]) return false;

    return true;
}

void solution(){  
    int ICT = x[0]*100 + x[1]*10 + x[2];
    int HUST = x[3]*1000 + x[4]*100 + x[5]*10 + x[2];
    
    if((ICT - x[6]*100 - 62 + HUST) == n) cnt++;
}

void TRY(int a){
    for(int i=1; i<10; i++){
        if(check(a,i)){
            visited[i] = true;
            x[a] = i;

            if(a == 6) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;
    input();
    TRY(0);
    cout << cnt << endl;
    
}
