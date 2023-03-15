#include <bits/stdc++.h>

using namespace std;

int N=16;
int a[1000000];
int Count=0;
int start[1000000] = {0};
int indexEnd=0;

void check() {
	for (int i = 1; i <= N; i++)
	{
		if(a[i] <= a[i-1]  && a[i] < a[i+1]){
			start[i] = 1;
		}
		
	}

	int countTmp = 0;
	for (int i = 1; i <= N; i++)
	{
		if(start[i] == 1){
			indexEnd = i-1;
			countTmp = 1;
		}

		if (start[i+1] == 0 )
		{
			if(countTmp > Count){
				Count = countTmp;
				if (i==N)
				{
					indexEnd = N;
				}
				
			}
			countTmp++;
		}
	}
	
	
}

int main(int argc, char const *argv[])
{
	// cin >> N;
	// for (int i = 1; i <= N; i++)
	// {
	// 	cin >> a[i];
	// }
	start[1] = 1;
	check();


	for (int i = indexEnd-(Count-1); i <= indexEnd; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}
