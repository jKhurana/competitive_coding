#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		long long size = (long long)n*(long long)m -1;
		//printf("%lld",size);
		if(size%2!=0)
			printf("Yes\n");
		else
			printf("No\n");

	}
}
