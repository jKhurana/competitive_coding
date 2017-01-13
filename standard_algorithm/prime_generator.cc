#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#define N 100001

using namespace std;

int a[N];

int main()
{
	int n;
	scanf("%d",&n);
	a[1] = 0;
	a[2] = 1;
	for(int i=3;i<=n;i++)
	{
		a[i]=1;
	}
	int i=2;
	while(i<=n/2)
	{
		if(a[i]==1)
		{
			int j=i+i;
			while(j<=n)
			{
				a[j]=0;
				j = j+i;
			}
		}
		i++;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
}