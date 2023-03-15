#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 2;

int n, T, D;
int f[MAX][102], a[MAX], t[MAX];
int res;

void input()
{
    cin >> n >> T >> D;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
}

void solve()
{
    for (int i = 1; i <= n ; i++)
    {
        for (int k = t[i]; k <= T; k++)
        {
            for (int j = max(0, i-D); j <= i-1 ; j++)
            {
                f[i][k] = max(f[i][k], f[j][k-t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    input();
    solve();
    return 0;
}
