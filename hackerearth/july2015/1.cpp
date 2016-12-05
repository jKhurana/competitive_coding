#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main()
{
	int t,n,ans,temp;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		map<int,int> even;
        map<int,int> odd;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
            scanf("%d",&temp);
            if(temp%2==0)
            {
                if(even.find(temp)==even.end())
                {
                    even.insert(pair<int,int>(temp,1));
                }
                else
                {
                    even[temp]+=1;
                }
            }
            else
            {
                if(odd.find(temp)==odd.end())
                {
                    odd.insert(pair<int,int>(temp,1));
                }
                else
                {
                    odd[temp]+=1;
                }
            }
        }
		int seven=even.size();
		int sodd=odd.size();
		ans+=(seven*(seven-1)/2);
		ans+=(sodd*(sodd-1)/2);
		for(map<int,int>::iterator it=even.begin();it!=even.end();it++)
		{
			if(it->second>1)
				ans++;
		}
		for(map<int,int>::iterator it=odd.begin();it!=odd.end();it++)
		{
			if(it->second>1)
				ans++;
		}
		printf("%d\n",ans);
	}

    return 0;
}
