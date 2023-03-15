#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

int n;
int a[MAX] = {0};
int totalTime = 0;
int maxA = 0;

void input()
{
    cin >> n;
    for (int i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    totalTime = 0;
    maxA = 0;
}

void solve() 
{
    while (n > 1)
    {
        if (n%2 == 0)
        {
            for (int i = 1; i <= n/2; i++)
            {
                a[i] =  a[2*i-1] + a[2*i];
            }
            n = n/2;
        }
        else
        {
            for (int i = 1; i <= n/2 ; i++)
            {
                a[i] = a[2*i-1] + a[2*i];
            }

            a[n/2 + 1] =  a[n];
            n = n/2 + 1;
        }

        for (int i = 1; i <= n ; i++)
        {
            maxA = max(maxA, a[i]);
        }
        totalTime += maxA;
        maxA = 0;

    }
    
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        input();
        solve();

        cout << totalTime << endl;
    }
    return 0;
}
