#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int N;
int Count = 0;

int sumSubSequence(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j ; k++)
    {
        sum += a[k];
    }

    return sum;
}

bool isEven(int sum) {
    if (sum%2 == 0)
    {
        return true;
    }
    else return false;
}

void run() {
    for (int i = 1; i < N; i++)
    {
        for (int j = i+1; j <= N; j++)
        {
            if(isEven(sumSubSequence(i,j)))
                Count++;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    run();

    cout << Count;
    return 0;
}
