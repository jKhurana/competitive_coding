#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,k,n,x,y,rp,ans,c,p;
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d %d %d",&x,&y,&k,&n);
        rp=x-y;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&p,&c);
            if(ans==0)
            {
                if(rp<=p && c<=k)
                    ans=1;
            }
        }
        if(ans==1)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
    }

    return 0;
}
