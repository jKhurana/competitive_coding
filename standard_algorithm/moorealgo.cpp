#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n,a[1000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int major_index=0,count=1;
	// first find candidate for majority 
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[major_index])
			count++;
		else
			count--;
		if(count==0)
		{
			major_index=i;
			count=1;
		}
	}

	// verify that found element is in majority or not
	int element = a[major_index];
	count=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==element)
			count++;
	}
	if(count>n/2)
	{
		printf("%d",element);
	}
	else
	{
		printf("%d",-1);
	}
}