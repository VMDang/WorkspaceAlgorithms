#include<iostream>
using namespace std;
int main(){
    int n,day[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> day[i];
    }
    int max= day[0];
 /*   for(int i=0;i<n;i++){
        for (int j = i+1; j < n; j++)
        {
            int sum=day[i];
            for(int k=i;k<j;k++){
                if( day[k]< day[k+1]){
                    sum += day[k+1];
                }else break;
                
                if(sum > max ){
                    max = sum;
                }
            }
        }
        
    }
*/ 
/*   for(int i=0;i<n;i++){
        int sum=day[i];
        for(int j=i;j<n-1;j++){
            if(day[j]<day[j+1]){
                sum += day[j+1];
            }else break;
            if(sum > max){
                max = sum;
            }
        }
    }
*/
    int ptucuoi=0;
    int sum=day[ptucuoi];
    for(int i=1;i<n;i++){ 
        
        if(day[i-1]<day[i]){
            int u= sum+day[i];
            int v= day[i];
            if(u > v){
                sum = u;        
            }else sum = v;      
            if(sum > max){
                max = sum;
            }
        }else {
            ptucuoi = i; 
            sum = day[i]; 
        }
    }
    cout << max;
}