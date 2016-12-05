#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t,temp,k;
    int a[100000],count=0;
    unsigned int n;
    int ans[10];

    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        getchar();// for new line
        scanf("%u",&n);
        getchar();
        for(int j=0;j<n;j++)
        {
            scanf("%d",&temp);
            for(k=0;k<count;k++)
            {
                if(a[k]==temp)
                    break;
            }
            if(k==count)
            {
                a[count]=temp;
                count++;
            }
        }
        ans[i]=count;
    }
    for(int i=0;i<t;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
