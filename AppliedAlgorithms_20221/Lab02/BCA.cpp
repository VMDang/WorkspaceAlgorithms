#include <bits/stdc++.h>

using namespace std;

const int N = 50;   

vector <int> T[N];  // T[i] is the list of teachers that can be assigned to cource i
int m, n;
int load[N];
int res;
bool conflict[N][N];
int x[N];

void input()
{
    cin >> m >> n;

    for (int t = 1; t <= m ; t++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k ; j++)
        {
            int c;
            cin >> c;
            T[c].push_back(t);
        }
    }

    for (int i = 1; i <= n ; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            conflict[i][j] = false;
        }
    }
    
    int K;
    cin >> K;

    for (int k = 1; k <= K; k++)
    {
        int i, j;
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }   
}
 
bool check(int t, int k)
{
    for (int i = 1; i <= k-1 ; i++)
    {
        if (conflict[i][k] && (x[i] == t))
            return false;
    }

    return true;
}

void solution()
{
    int maxLoad = 0;
    for (int t = 1; t <= m; t++)
    {
        maxLoad = max(maxLoad, load[t]);
    }

    if (maxLoad < res) res = maxLoad;  
    
}

void Try(int k)
{
    for (int i = 0; i < T[k].size(); i++)
    {
        int t = T[k][i];
        if (check(t,k))
        {
            x[k] = t;   // assign course l to teacher t
            load[t] += 1;

            if (k == n)
            {
                solution();
            }else
            {
                if(load[t] < res)   Try(k+1);
            }
            
            load[t] -= 1;
        } 
    } 
}

int main(int argc, char const *argv[])
{
    input();
    for (int t = 1; t <= m ; t++)
    {
        load[t] = 0;
    }
    res = 1e9;
    Try(1);
    cout << res << endl;
    return 0;
}
