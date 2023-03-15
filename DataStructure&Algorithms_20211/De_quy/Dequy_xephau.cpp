/*
    Xếp n quân hậu vào bàn cờ vua NxN sao cho 2 quân hậu bất kì không thể ăn nhau
    Input: kích thước bàn cờ N;
    Output: Mỗi dòng là 1 cách xếp các quân hậu
            Mỗi số trong 1 dòng vị trí quân hậu tương ứng vị trí hàng 1-->N
*/
#include<iostream>
using namespace std;
int x[100] = {0};
int n;
int check(int v, int k){
    for(int i=1; i<=k-1; i++){
        if(x[i]==v) return 0;
        if(x[i]+i == v+k) return 0;
        if(x[i]-i == v-k) return 0;
    }
    return 1;
}

void solution(){
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void TRY(int k)
{
    for (int v = 1; v <=n ; v++)
    {
        if(check(v,k)){
            x[k] = v;
            if(k == n){
                solution();
            }else TRY(k+1);
        }
    }
    
}
int main(){
    cin >> n;
    TRY(1);
}