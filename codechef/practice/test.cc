#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct subject {
	int lowelimit;
	int upperlimit;
	int rate;
} sub;

int main()
{
	sub arr[100];
	int n,m,temp,sum=0;
	scanf("%d%d",&n,&m);

	int value = n*m;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&(arr[i].lowelimit),&(arr[i].upperlimit),&(arr[i].rate));
		sum += arr[i].lowelimit;
	}
	if(sum >= value)
		printf("0");
	else
	{
		sort(arr,arr+n,greater<int>());
		
	}


}