#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#define N 100000

using namespace std;

int a[100001];
int b[100001];
int prime[100001];

void find_prime()
{
	prime[1] = 0;
	prime[2] = 1;
	for(int i=3;i<=N;i++)
	{
		prime[i]=1;
	}
	int i=2;
	while(i<=N/2)
	{
		if(prime[i]==1)
		{
			int j=i+i;
			while(j<=N)
			{
				prime[j]=0;
				j = j+i;
			}
		}
		i++;
	}
}

int gcd(int a,int b)
{
	if(a<b)
		return gcd(b,a);
	if(b==0)
		return a;
	else
	{
		return gcd(b,a%b);
	}
}

void insert_map(map<int,vector<int>,std::greater<int>> &data,int key,int value)
{
	map<int,vector<int>>::iterator it;
	it = data.find(key);
	if(it!=data.end())
	{
		vector<int> &v = it->second;
		v.push_back(value);
	}
	else
	{	
		vector<int> v;
		v.push_back(value);
		data.insert(make_pair(key,v));
	}
}

int main()
{
	int n,t;
	find_prime();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int max=0,value;
		bool flag=true;
		b[n-1]=1;
		map<int,vector<int>,std::greater<int>> data;
		insert_map(data,1,n-1);
		for(int i=n-2;i>=0;i--)
		{
			flag = false;
			for(map<int,vector<int>,std::greater<int>>::iterator it=data.begin();it!=data.end();++it)
			{
				vector<int> &v = it->second;
				// find the value to be inserted
				for(int j=0;j<v.size();j++)
				{
					int index = v[j];
					int g = gcd(a[i],a[index]);
					if(g>1)
					{
						value = b[index]+1;
						flag = true;
						break;
					}		
				}
				// insert the value and exit
				if(flag)
				{
					b[i] = value;
					insert_map(data,b[i],i);
					break;
				}
			}
			if(flag==false)
			{
				insert_map(data,1,i);
				b[i]=1;
			}
		}
		max = 0;
		for(int i=0;i<n;i++)
		{
			if(max<b[i])
				max=b[i];
		}
		printf("%d\n",max);
	}
	return 0;
}