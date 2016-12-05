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
#include <cstring>

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
#define MAX(a,b)	( (a) > (b) ? (a) : (b) )

// Macro for taking input
#define DEPI(x) scanf("%d",&x)
#define DEPII(x,y) scanf("%d%d",&x,&y)

int T[5001][5001][5001];
int arr[5001];
int n,k,d,m;

long long maxLC(int i,int k,int l)
{
	if(i>n)
		return 0;
	if(l!=-1 && T[i][k][l]!=-1)
		return T[i][k][l];
	LL currLC=0;
	if(l!=-1)
	{
		int diff=i-l;
		if(diff<=d)
			currLC=m*arr[i];
		else
			currLC=arr[i];
	}
	else
	{
		currLC=arr[i];
	}
	if(k==0)
	{
		T[i][k][l]=currLC+maxLC(i+1,k,l);
		return T[i][k][l];
	}
	T[i+1][k][l]=maxLC(i+1,k,l);
	T[i+1][k-1][i]=maxLC(i+1,k-1,i);
	T[i][k][l] = MAX(currLC+T[i+1][k][l],T[i+1][k-1][i]);
	return T[i][k][l];
}

int main()
{
	int kases;
	cin >> kases;
	REP(kase,1,kases)
	{
		scanf("%d%d%d%d",&n,&k,&d,&m);
		REP(i,1,n)
			scanf("%d",&arr[i]);
		memset(T,-1,sizeof(T[0][0])*5001*5001*5001);
		printf("%lld",maxLC(1,k,-1));
	}
	return 0;
}