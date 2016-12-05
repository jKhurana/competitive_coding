#include <iostream>
using namespace std;

int main()
{
    int t;
    long long n;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
    	ans=0;
    	scanf("%lld",&n);
    	if(n==1 || n==2 || n==3)
    		printf("%d\n",1);
    	else if(n%3==0)
    		printf("%lld\n",(long long)(n/3));
    	else
    		{
    			ans+=(long long)(n/3);
    			ans++;
    			if(n%3==1)
    			{
    				ans+=(long long)((n-4)/3*2);
    			}
    			else
    			{
                    ans++;
    				ans+=(long long)((n-5)/3*2);
                }
    			ans+=2;
    			printf("%lld\n",ans);
    		}
    }
    return 0;
}
