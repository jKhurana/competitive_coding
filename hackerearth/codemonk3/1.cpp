#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int main()
{
	int temp,id[100],comp[100],n,ans=0;
	queue<int> q;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		q.push(temp);
		comp[i]=0;
	}
	for(int i=0;i<n;i++)
		scanf("%d",&id[i]);
	while(!q.empty())
	{
		temp=q.front();
		int j=0,flag=0;
		while(id[j]!=temp)
		{
			if(comp[id[j]]==0)
			{
				flag=1;
				break;
			}
			j++;
		}
		if(flag==1)
		{
			q.pop();
			q.push(temp);
			ans++;
		}
		else
		{
			ans++;
			q.pop();
			comp[temp]=1;
		}
	}
	printf("%d",ans);
}
