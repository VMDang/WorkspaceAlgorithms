#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

int n;
multimap <int,int> X;


void input(){

    cin>>n;

    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        X.insert(pair<int,int>(b,a));
    }

}

int solve(){
    int dem = 0;
    multimap<int,int>::iterator k,k1,temp;
    k = X.begin();
    temp = ++X.begin();
    for (k1 = temp; k1 != X.end(); ++k1){
        if (k->first < k1->second){
            dem++;
            k=k1;
        }
    }
    return dem + 1;
}

int main(){
    input();
    multimap<int,int>::iterator kx;
    cout<<solve();
    return 0;
}