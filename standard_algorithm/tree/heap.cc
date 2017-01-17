#include<stdio.h>
#include<iostream>

using namespace std;


int swap(int *a,int *b)
{
	int c=*a;
	*a = *b;
	*b = c;
	}

void heapify(int heap[],int n,int i)
{
	if(i>n || 2*i>n)
		return;
	while (2*i<=n)
	{
		if(2*i+1 <= n)
		{
			int maxindex = heap[2*i] > heap[2*i+1] ? 2*i : 2*i+1;
			if(heap[i]>=heap[maxindex])
				break;
			else
			{
				swap(heap+i,heap+maxindex);
				i = maxindex;
				}
			}
		else
		{
			if(heap[i] < heap[2*i])
			{
				swap(heap+i,heap+2*i);
				i = 2*i;
				}
				else
					break;
			}
		}

	}

void build_heap(int heap[],int n)
{
	int i;
	i = n%2==0 ? (n-1)/2 + 1 : (n-1)/2;
	for(int j=i;j>0;j--)
	{
			heapify(heap,n,j);
		}
	}

int fetch(int heap[],int *n)
{
	if(*n<=0)
		return -1;
	int item = heap[1];
	heap[1] = heap[*n];
	(*n)--;
	heapify(heap,*n,1);
	return item;
	}

int main()
{
	int heap[100001],n=7;
	heap[1] = 10;
	heap[2] = 34;
	heap[3] = 56;
	heap[4] = 12;
	heap[5] = 65;
	heap[6] = 23;
	heap[7] = 45;
	build_heap(heap,7);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",heap[i]);
		}
	printf("\n");
	int item = fetch(heap,&n);
	while(item!=-1)
	{
		printf("%d ",item);
		item = fetch(heap,&n);
	}
	return 0;

	}
