#include <bits/stdc++.h>

using namespace std;
int n, M;
int a[1000];
int t[1000];
int X[1000];
int f = 0;
int Count = 0;

void setT() {
    t[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        t[i] = t[i-1] + a[i];
    }
}

void TRY(int k){
    int v = 1;
    while (v <= (M-f-(t[n]-t[k]))/a[k])
    {
        X[k] = v;
        f += a[k] * X[k];
        if (k == n)
        {
            if(f == M)  Count++;
        }else
        {
            TRY(k+1);
        }
        f = f - a[k] * X[k];
        v++;
    }
    
}

void solve() {
    setT();
    TRY(1);
}

int main(int argc, char const *argv[])
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve();

    // for (int i = 1; i <= n; i++)
    // {
    //     cout <<"i:"<<i << "  a-" << a[i] << "  t-" << t[i] << endl;   
    // }

    cout << Count;    
}
