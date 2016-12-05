#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int main()
{
	int n,temp1,temp2;
	stack<int> s;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp1);
		if(temp1==1)
		{
			if(s.empty())
				printf("No Food\n");
			else
			{
				printf("%d\n",s.top());
				s.pop();
			}
		}
		else
		{
			scanf("%d",&temp2);
			s.push(temp2);
		}
	}
    return 0;
}
