#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int a[4];
		for(int i=0;i<4;i++)
			scanf("%d",&a[i]);
		bool flag = false;
		for(int i=1;i<16;i++)
		{
			int j=4;
			int temp = i;
			int sum = 0;
			while(j--)
			{
				if(temp&1)
				{
					sum = sum + a[j];
				}
				temp = temp >> 1;
			}
			if(sum==0)
			{
				flag = true;
				break;
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}