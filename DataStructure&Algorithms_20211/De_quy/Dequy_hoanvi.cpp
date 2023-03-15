/*
   Liệt kê các hoán vị của số n sử dụng thuật toán đệ quy:
   Input: n
   Output: Các hoán vị từ 1-->n 
*/
#include<iostream>
using namespace std;
int m[100] ={0};
int x[100] = {0};
int n;
void solution(){
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}
void TRY(int i)
{
    for(int v=1; v<=n; v++){
        if (!m[v])
        {
            x[i] = v;
            m[v] = 1;
            if(i == n)
                solution();
            else TRY(i+1) ; 
            m[v] = 0;
        }
        
    }
}
int main(){  
    cin >> n;
    TRY(1);
}