#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

int main(int argc, char const *argv[])
{
    int n, a[MAX];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int Count = 0;
    for (int i = 2; i < n; i++)
    {
        if(a[i] > a[i+1] && a[i] > a[i-1]) Count++;
    }
    
    cout << Count;
}
