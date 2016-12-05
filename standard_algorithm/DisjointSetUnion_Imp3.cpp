#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define ini(a,v) memset(a,v,sizeof(a))
#define MAX 100000

// Root base implementation of Disjoint Union Set

void dsinitialize(vector<int> &v)
{
	for(unsigned int i=0;i<v.size();i++)
	{
		v[i]=i;
	}
}

int findroot(int i,vector<int> &v)
{
	while(v[i]!=i)
	{
		i=v[i];
	}
	return i;
}

void dsunion(int a,int b,vector<int> &v,vector<int> &size)
{
	int root1=findroot(a,v);
	int root2=findroot(b,v);
	if(size[root1]>=size[root2])
	{
		v[root2]=root1;
		size[root1]+=size[root2];
	}
	else
	{
		v[root1]=root2;
		size[root2]+=size[root1];	
	}
}

bool dsfind(int a,int b,vector<int> &v)
{
	int root1=findroot(a,v);
	int root2=findroot(b,v);
	if(root1==root2)
		return true;
	else
		return false;
}

int main()
{
	vector<int> v(6,0);
	vector<int> size(6,1);
	dsinitialize(v);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	dsunion(0,1,v,size);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	dsunion(2,3,v,size);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	dsunion(2,4,v,size);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\nSize:");
	for(int i=0;i<v.size();i++)
		printf("%d ",size[i]);
	printf("\n");
	dsunion(0,4,v,size);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\nSize:");
	for(int i=0;i<v.size();i++)
		printf("%d ",size[i]);
	return 0;
}