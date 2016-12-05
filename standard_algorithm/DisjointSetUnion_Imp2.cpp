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

void dsunion(int a,int b,vector<int> &v)
{
	int root1=findroot(a,v);
	int root2=findroot(b,v);
	v[root2]=root1;
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
	dsinitialize(v);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	dsunion(0,1,v);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	dsunion(0,2,v);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	dsunion(3,4,v);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	printf("\n");
	dsunion(1,4,v);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	return 0;
}