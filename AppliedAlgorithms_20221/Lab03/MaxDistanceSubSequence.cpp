#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

int t;
int n, C, a[MAX];

bool check (int distance)
{
    int cnt = 1;
    int i = 1, last = 2;
    while (i < n)
    {
        while ((last <= n) && (a[last] - a[i] < distance))
        {
            ++last;
        }
        if (last <= n)
        {
            cnt++;
        }
        if (cnt >= C)
        {
            return true;
        }
        i = last;
        last++;
    }
    return false;
}

int maxDistance()
{
    int l = 0;
    int r = a[n] - a[1];
    while ( l <= r)
    {
        int mid = (l+r)/2;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid -1;
        }
    }
    return r;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> C;
        for (int i = 0; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        cout << maxDistance() << endl;
    }
    
    return 0;
}
