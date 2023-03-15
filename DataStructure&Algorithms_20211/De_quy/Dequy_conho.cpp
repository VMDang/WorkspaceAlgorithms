/*
    Đệ quy có nhớ tính tổ hợp chập C(k,n);
    Đầu vào: k,n;
    Đầu ra: C(k,n) = ...
*/
#include<iostream>
using namespace std;
const int MAX = 100;
int arr[MAX][MAX];
int C(int k, int n)
{
    if(k==0 || k==n){
        return arr[k][n] = 1;         // Trường hợp cơ sở
    }else if(arr[k][n] == -1){
        arr[k][n] = C(k,n-1) + C(k-1,n-1);          // Cách tính C(k,n) = C(k,n-1) + C(k-1,n-1)
    }
    return arr[k][n];       
}
int main()
{
    int n,k;
    cin >> k >> n;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            arr[i][j] = -1;
        }
    }
    printf("C(%d,%d) = %d",k,n,C(k,n));

}