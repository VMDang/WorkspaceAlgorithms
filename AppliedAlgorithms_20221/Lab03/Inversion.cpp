#include <bits/stdc++.h>

using namespace std;

#define MAX 1000006
int const MOD = 1e9+7;

int n;
int a[MAX];
int temp[MAX];

int merge(int left, int mid, int right)
{
    int i = left, j = mid, k = right;
    int inv_cnt = 0;

    while ((i <= mid-1) && (j <= right))
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }else
        {
            temp[k++] = a[j++];

            inv_cnt += (mid - i);
        }
        
    }
    
    while (i <= (mid - 1))
    {
        temp[k++] = a[i++];
    }

    while (j <= right)
    {
        temp[k++] = a[j++];
    }
    
    for (int i = left; i <= right ; i++)
    {
        a[i] = temp[i];
    }
    
    return inv_cnt;
}

int mergeSort(int left, int right)
{
    int mid, inv_cnt = 0;
    if (right > left)
    {
        mid = (right + left) / 2;

        inv_cnt = (inv_cnt + mergeSort(left, mid)) % MOD;
        inv_cnt = (inv_cnt + mergeSort(mid + 1, right)) % MOD;
        inv_cnt = (inv_cnt + merge(left, mid + 1, right)) % MOD;
    }
    return inv_cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    cout << mergeSort(1, n);
    return 0;
}
