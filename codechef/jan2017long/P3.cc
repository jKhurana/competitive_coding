#include<stdio.h>
#include<string>

using namespace std;

int getValue(char c)
{
	switch(c)
	{
		case 'A':
			return 1;
		case 'B':
			return 2;
		case 'W':
			return 3;
		default:
			return -1;
	}
}

// In case of brick,only porblem is at the bottom of the brick
int brickcheck(int i,int j,int n,int m,int arr[][])
{
	if(i==n-1)
		return 0;
	if(arr[i+1][j]!=2)
		return 1;
	else
		return 0;

}

int watercheck(int i,int j,int n,int m,int arr[][])
{
	// check left 
	if(j==0)
		return 1;
	if(arr[i][j-1]==1)
		return 1;
	//check right
	if(j==m-1)
		return 1;
	if(arr[i][j+1]==1)
		return 1;
	//check bottom
	if(i==n-1)
		return 0;
	if(arr[i+1][j]==1)
		return 1;
	return 0;
}

int aircheck(int i,int j,int n,int m,int arr[][])
{
	// check left
	if(j==0)
		return 0;
	if(arr[i][j-1])
	
}

int main()
{
	int t,n,m;
	int arr[1000][1000];
	scanf("%d",&t);
	string s;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			cin >> s;
			for(int j=0;j<s.size();j++)
			{
				arr[i][j] = getValue(s[j]);
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j]==2)
				{
					if(aircheck(i,j,n,m,arr))
				}
				else if(arr[i][j]==3)
				{

				}
				else
				{

				}
			}
		}
	}

	return 0;
}
