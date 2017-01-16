#include<stdio.h>
#include<iostream>
#define max(a,b) ( (a) < (b) ? (b) : (a) )

using namespace std;


int swap(int *a,int *b)
{
	int c=*a;
	*a = *b;
	*b = c;
	}

void build_heap(int heap[],int n)
{
	int i;
	if(n%2==0)
	{
		i = (n-1)/2 + 1;
		}
	else
	{
		i = (n-1)/2;
		}
	
	for(int j=i;j>0;j--)
	{
		if(2*j+1 <=n)
		{
			int max1 = heap[2*j] > heap[2*j+1] ? 2*j : 2*j+1;
			if(heap[max1] > heap[j])
				swap(heap[max1],heap[j]);
			}
		else if(2*j<=n)
		{
			heap[j] = max(heap[j],heap[2*j]);
			}
		}
	}

int fetch(int heap[],int n)
{
	int item = heap[1];
	heap[1] = heap[n];
	n--;
	int i = 1;
	while(2*i<=n)
	{
		if(2*i+1 <= n)
		{
			int maxindex = heap[2*i] > heap[2*i+1] ? 2*i : 2*i+1;
			if(heap[i]>=heap[maxindex])
				break;
			else
			{
				swap(heap[i],heap[maxindex]);
				i = maxindex;
				}
			}
		else
		{
			if(heap[i] < heap[2*i])
			{
				swap(heap[i],heap[2*i]);
				i = 2*i;
				}
			}
		}
	return item;
	}

int main()
{
	int heap[100001];
	heap[1] = 10;
	heap[2] = 34;
	heap[3] = 56;
	heap[4] = 12;
	heap[5] = 65;
	heap[6] = 23;
	heap[7] = 45;
	int n = 7;
	build_heap(heap,7);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",heap[i]);
		}
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d ",fetch(heap,n));
		n--;
		}
	return 0;
	
	}
