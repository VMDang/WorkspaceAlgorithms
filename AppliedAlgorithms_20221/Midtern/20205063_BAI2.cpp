#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
priority_queue<int> q;
int n;
int a[MAX];
queue<string>truyvan;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        q.push(a[i]);
    }
}
int main(){
    input();
    string hoi;
    int k;
    do{
        cin >> hoi;
        if(hoi == "*") continue;
        if(hoi == "insert"){
            cin >> k;
            q.push(k);
        }
        if(hoi == "delete-max"){
            cout << q.top() << endl;
            q.pop();
        }
    } while(hoi != "*");
}