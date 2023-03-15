#include<stdio.h>
#include<stdlib.h>
/*  Sắp xếp lựa chọn SelectionSort
    -Độ phức tạp O(n^2)
    -So sánh: Compare(a,b): thực hiện cố định (n-1)*n/2 lần
    -Đổi chỗ: Swap(a,b): Thực hiện min=0 & max=n-1 lần
*/
void SelectionSort(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (A[min] > A[j])
            {
                min = j;
            }
        }   
        int tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
    }
}
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand();
    }
    SelectionSort(arr,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    
}