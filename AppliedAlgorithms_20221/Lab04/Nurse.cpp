#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 2;
const int MOD = 1e9 + 7;

int n, k1, k2;
int f[MAX][2];
int res;

void input()
{
    cin >> n >> k1 >> k2;  
}

void solve()
{
    f[0][0] = f[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k1; j <= k2; j++)
        {
            if ((i - j) < 0)
            {
                break;
            }
            f[i][1] = f[i][1] + f[i-j][0];
            f[i][1] = f[i][1] % MOD;
        }
        f[i][0] = f[i-1][1];
    }
    res = (f[n][0] + f[n][1]) % MOD;
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    input();
    solve();
    return 0;
}
