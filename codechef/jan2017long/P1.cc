#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int t;
	long long c,d,l;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%lld%lld%lld",&c,&d,&l);
		if(l%4!=0)
		{
			printf("no\n");
			continue;
			}
		long long dlegs = 4 * d;
		if(dlegs > l) {
			printf("no\n");
			continue;
		}
		long long r = l- dlegs;
		long long clegs = 4*c ;
		
		if(clegs<r)
		{
			printf("no\n");
			continue;
			}
		long long extra = clegs-r;
		if(extra <= 8*d)
		{
			printf("yes\n");
			}
		else
		{
			printf("no\n");
			}
	}
		
	}
