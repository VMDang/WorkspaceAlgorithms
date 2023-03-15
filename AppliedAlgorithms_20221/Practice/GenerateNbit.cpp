#include <bits/stdc++.h>

using namespace std;

int n;

void input()
{
    cin >> n;
}

void printBits(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void solve(int arr[], int i)
{
    if (i == n)
    {
        printBits(arr);
        return;
    }
    

    arr[i] = 0;
    solve(arr, i + 1);

    arr[i] = 1;
    solve(arr, i + 1);

}

int main(int argc, char const *argv[])
{
    int arr[n];

    input();
    solve(arr, 0);
    return 0;
}
