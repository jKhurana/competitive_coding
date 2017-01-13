#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main()
{
	int t,n,temp,max=-1,index=-1;
	scanf("%d",&t);
	while(t--)
	{
		max = -1;index=-1;
		vector<pair<int,int>> p;
		int ans[50000];
		vector<int> tree[50000];
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			p.push_back(make_pair(temp,i));
			if(max<temp)
			{
				max = temp;
				index = i;
			}
		}
		sort(p.begin(),p.end());
		for(int i=0;i<n;i++)
			ans[i]=index;
		int s,d;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&s,&d);
			tree[s-1].push_back(d-1);
			tree[d-1].push_back(s-1);
		}
		


		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		int i=n-1,j=n-2;
		while(i>0)
		{
			vector<int> adj = tree[p[i].second];
			for(int k=0;k<adj.size();k++)
			{
				if(ans[adj[k]]==p[i].second)
					ans[adj[k]]=p[j].second;
			}
			if(ans[p[i].second]==p[i].second)
				ans[p[i].second]=p[j].second;
			i--;
			j--;
		}
		// work for i=0
		vector<int> adjlist = tree[p[i].second];
		for(int k=0;k<adjlist.size();k++)
		{
			if(ans[adjlist[k]]==p[i].second)
				ans[adjlist[k]]=-1;
		}
		if(ans[p[i].second]==p[i].second)
			ans[p[i].second]=-1;

		for(int k=0;k<n;k++)
		{
			if(ans[k]==-1)
				printf("%d ",ans[k]);
			else
				printf("%d ",ans[k]+1);
		}
		printf("\n");

	}
}
