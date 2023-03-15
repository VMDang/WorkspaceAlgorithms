#include <bits/stdc++.h>
using namespace std;

int a[10000] ;
int N, k, m;
int Count = 0;

int sumSubSequence(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j ; k++)
    {
        sum += a[k];
    }

    return sum;
}

bool checkEqual(int sum) {
    if (sum == m)
    {
        return true;
    }
    else return false;
}

void run() {
    for (int i = 0; i < N-k+1; i++)
    {
        for (int j = i+k-1; j < N; j++)
        {
            if(checkEqual(sumSubSequence(i,j)))
                Count++;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> k >> m;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    run();

    cout << Count;
    return 0;
}
