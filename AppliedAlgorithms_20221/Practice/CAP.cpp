#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

int T;
int n, m;
int a[MAX] ;
int b[MAX] ;
int Count = 0;

void input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        Count = 0;
        solve();
    }
    
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            if (a[i] == b[j])
            {
                Count++;
                break;
            }
            
        }
        
    }
    cout << Count << endl;
}

int main(int argc, char const *argv[])
{
    input();
    return 0;
}

