#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define ini(a,v) memset(a,v,sizeof(a))
#define MAX 100000

// Basic representation of Disjoi8nt Union Set

void dsinitialize(vector<int> &v)
{
	for(unsigned int i=0;i<v.size();i++)
	{
		v[i]=i;
	}
}

void dsunion(int a,int b,vector<int> &v)
{
	int temp=v[b];
	for(unsigned int i=0;i<v.size();i++)
	{
		if(v[i]==temp)
			v[i]=v[a];
	}
}

bool dsfind(int a,int b,vector<int> &v)
{
	if(v[a]==v[b])
		return true;
	else
		return false;
}

int main()
{
	vector<int> v(10,0);
	dsinitialize(v);
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	dsunion(1,2,v);
	dsunion(3,4,v);
	dsunion(4,8,v);
	dsunion(3,9,v);
	dsunion(5,6,v);
	printf("\n");
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	return 0;
}