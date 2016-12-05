#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<char> VC;
typedef vector<PI> VPI;
typedef vector<string> VS;

// Basic Macros
#define FI			first
#define SE			second 
#define INI(a,v)	memset(a,v,sizeof(a))
#define PB			push_back
#define MP 			make_pair
#define RE(i,s,n)   for(int i=s;i<(n);++i)
#define REP(i,s,n)  for(int i=s;i<=(n);++i)
#define FO(i,n)     re(i,0,n)
#define REV(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define REPV(i,n,s) for(int i=(n);i>=s;--i)
#define FOV(i,n)    rev(i,n,0)

// Macro for taking input
#define SI(x)		scanf("%d",&x)
#define SII(x,y)	scanf("%d%d",&x,&y)
#define SL(x)		scanf("%lld",&x)
#define SLL(x,y)	scanf("%lld%lld",&x,&y)
#define PRI(x)		printf("%d",x)
#define PRL(x)		printf("%lld",x)

int count_digit(LL n,int d)
{
	int count=0;
	while(n!=0)
	{
		int r=n%10;
		if(r==d)
			count++;
		n=n/10;
	}
	return count;
}
int count_trail_digit(LL n,int d)
{
	int count=0;
	while(n!=0)
	{
		int r=n%10;
		if(r==d)
			count++;
		else
			break;
		n=n/10;
	}
	return count;
}

LL next_number(LL old)
{
	int zero=count_trail_digit(old,0);
	if(zero!=0)
	{
		int n=4;
		for(int i=1;i<zero;i++)
		{
			n=n*10;
		}
		return old+n;
	}
	else
	{
		int d=count_digit(old,4);
		int n=4;
		for(int i=1;i<=d;i++)
		{
			n=n*10;
		}
		return n;
	}
}

int main()
{
	int kases;
	cin >> kases;
	REP(kase,1,kases)
	{
		int n;
		SI(n);
		LL temp=4;
		while(temp%n!=0)
		{
			temp=next_number(temp);
		}
		int zero=count_digit(temp,0);
		int four=count_digit(temp,4);
		PRI(2*four+zero);
	}
	return 0;
}