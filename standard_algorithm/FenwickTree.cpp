#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void create_fenwick(vector<int> &freq,vector<int> &tree)
{
	int add,j;
	for(unsigned int i=1;i<freq.size();i++)
	{
		add=freq[i];
		j=i;
		while(j<=n-1)
		{
			tree[j]=tree[j]+add;
			
		}
	}
}

int main()
{
	int n,temp;
	scanf("%d",&n);
	vector<int> freq(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		freq.push_back(temp);
	}
	vector<int> tree(n+1,0);
	create_fenwick(freq,tree);
	return 0;
}