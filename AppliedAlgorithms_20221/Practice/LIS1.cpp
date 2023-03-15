#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n = 9;
int a[MAX] = {3,1,2,4,3,5,6,8,9};
int S[MAX];
int c_max = 0;

void input(){
    c_max = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){
    S[0] = 1;
    c_max = S[0];
    for(int i=1; i<n; i++){
        int r;
        for(r=0; r<i; r++){
            if(a[r] + 1 == a[i])
                break;
        }

        if(r >= i){
            S[i] = 1;
            continue;
        }

        S[i] = S[r] + 1;

        c_max = max(S[i], c_max);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;

    while(T > 0){
        input();
        solve();
        
        cout << c_max << endl;
        T--;
    }
}
