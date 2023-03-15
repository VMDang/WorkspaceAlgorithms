#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

int N;  // number of requests (1,2,...N). Request i has pickup point i and drop off point i + N
int cap;
int A[2*MAX+1][2*MAX+1];

int x[MAX];
int appear[MAX];
int load;
int f;
int f_best;
int x_best[MAX];
int cmin;

void input()
{
    cin >> N >> cap;
    cmin = 1000000;
    for (int i = 0; i <= 2*N; i++)
    {
        for (int j = 0; j <= 2*N; j++)
        {
            cin >> A[i][j];
            if (i != j && cmin > A[i][j])
            {
                cmin = A[i][j];
            } 
        }      
    }  
}

bool check(int v, int k)
{
    if (appear[v] == 1) return false;

    if (v > N)
    {
        if(!appear[v-N]) return false;
    }else
    {
        if(load + 1 > cap) return false;
    }
    
    return true;   
}

void solution()
{
    if (f + A[x[2*N]][0] < f_best)
    {
        f_best = f + A[x[2*N]][0];
        for (int i = 0; i <= 2*N ; i++)
        {
            x_best[i] = x[i];
        }
        
    }
    
}

void TRY(int k)
{
    for (int v = 1; v <= 2*N; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            f += A[x[k-1]][x[k]];
            if (v <= N)
            {
                load += 1;
            }else
            {
                load += -1;
            }
            
            appear[v] = 1;
            if (k == 2*N)
            {
                solution();
            }else
            {
                if ((f + (2*N+1-k)*cmin) < f_best)
                {
                    TRY(k+1);
                }
            }
            
            if (v <= N)
            {
                load -= 1;
            }else
            {
                load -= -1;
            }
            appear[v] = 0;
            f -= A[x[k-1]][x[k]];
        }   
    }
}

void solve()
{
    load = 0;
    f = 0;
    f_best = 1000000;
    for (int i = 1; i <= 2*N; i++)
    {
        appear[i] = 0;
    }
    x[0] = 0;
    TRY(1);
    cout << f_best << endl;
}

void print()
{
     for (int i = 0; i <= 2*N; i++)
     {
        cout << x_best[i] << " ";
     }
     cout << endl;
}

int main(int argc, char const *argv[])
{
    input();
    solve();
    return 0;
}
