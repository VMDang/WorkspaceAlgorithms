#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int a[10000];
int n=0;
void insert(int x, int p)
{
    for (int i = n-1; i >= p; i--)
    {
       a[i+1] = a[i];
    }
    a[p] = x;
    n++;
}
void delete(int p)
{
    for (int i = p+1; i < n-1; i++)
    {
        a[i-1] = a[i];
    }
    n--;
    
}
int locate(int x)
{
    for (int i = 0; i < n-1; i++)
    {
       if (a[j]==x)
       {
         return j;
       }
       
    }
    return -1;
}
 void Print(int a[],int n)
 {
     for (int i = 0; i < n; i++)
     {
         printf("%d ",a[i]);
     }
     
 }
int main()
{
 srand((int)time(0));
 for (int i = 0; i < 100; i++)
 {
    insert(rand(),i);
 }
 for (int i = 0; i < 50; i++)
 {
     int r = 0 + rand()%(100+1-0);
     delete(r);
 }
 
}