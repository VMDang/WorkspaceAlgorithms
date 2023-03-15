#include <iostream>
#include <vector>
using namespace std;
int n;

int main()
{
    cin >> n;
    vector<int> a(n);
    vector<int> sumSubSequence(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sumSubSequence[0] = a[0];
    
    sumSubSequence[1] = a[0] > a[1] ? a[0] : a[1];
    
    for (int i = 2; i < n; i++)
    {
        sumSubSequence[i] = max(sumSubSequence[i-1], sumSubSequence[i-2] + a[i] );
    }

    cout << sumSubSequence[n-1] << endl;
    return 0;
}
