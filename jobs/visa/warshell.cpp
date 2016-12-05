#include <iostream>
#include <stdio.h>
#include <limits>
#define MAX 100
#define min(a,b) ((a) > (b) ? (b) : (a))
using namespace std;

int a[MAX][MAX];

void initialize(int v)
{
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			a[i][j]=numeric_limits<int>::max();
}

void warshall(int v)
{
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			for(int k=0;k<v;k++)
				{
					if(a[i][k]!=numeric_limits<int>::max() && a[k][j]!=numeric_limits<int>::max())
					{
						a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
					}
				}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int v,p,q;
		scanf("%d%d",&v,&p);
		initialize(v);
		int s, d, w;
		for(int i=0;i<p;i++)
		{
			scanf("%d%d%d",&s,&d,&w);
			a[s][d]=w;
			a[d][s]=w;
		}
		warshall(v);
		scanf("%d",&q);
		int flag=0;
		long long sum=0;
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&s,&d);
			if(a[s][d]!=numeric_limits<int>::max())
				sum+=a[s][d];
			else
			{
				flag=1;break;
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("%lld\n",sum);


	}

}