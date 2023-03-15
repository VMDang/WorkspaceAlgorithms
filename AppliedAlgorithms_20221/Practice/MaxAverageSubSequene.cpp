#include <bits/stdc++.h>
using namespace std;

int a[1000000] ;
int N;
int k;
float average = 0;

float averageSubSequence(int i, int j) {
    float sum = 0;
    for (int k = i; k <= j ; k++)
    {
        sum += a[k];
    }

    return sum/(j-i+1);
}

void run() {
    for (int i = 1; i <= N-k+1; i++)
    {
        for (int j = i+k-1; j <= N; j++)
        {
            float tmp = averageSubSequence(i,j);
            cout << tmp << endl;
            if (tmp > average)
            {
                average = tmp;
            }
            
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    cin >> N >> k;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    run();

    printf("%.5lf", average);
    return 0;
}
