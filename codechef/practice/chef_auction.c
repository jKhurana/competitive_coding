#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,m,result=0,i,flag;
    long o,p;
    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        result=0;
        scanf("%d %d %ld",&n,&m,&o);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&p);
            if(i==0 && p<o)
            {
                flag=0;
                printf("%d\n",-1);
            }
            if(p>=o && result<m && flag)
                result++;
        }
        if(flag)
            printf("%d\n",result);
    }
    return 0;
}
