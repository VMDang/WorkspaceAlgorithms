#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;
int n;
long long s[N], f[2], res = -1e18, a[N]; 

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    int tmp;
    for (int i = 1; i <= n ; i++)
    {
        s[i] = s[i-1] + a[i];
    }
    
    f[1] = 1e18;

    for ( int i = 1; i <= n; i++)
    {
        tmp = abs(s[i]) % 2;
        if (f[tmp] != 1e18) 
        {
            res = max(res, s[i] - f[tmp]);
        }
        f[tmp] = min(f[tmp], s[i]);
    }
    
    if (res == -1e18) 
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        cout << res << endl;
    }
    
}

int main()
{
    input();
    solve();           
    return 0;
}
