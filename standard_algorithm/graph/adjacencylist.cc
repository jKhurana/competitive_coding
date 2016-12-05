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
#define FO(i,s,n)   for(int i=s;i<(n);++i)
#define FOE(i,s,n)   for(int i=s;i<=(n);++i)
#define REV(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define REVE(i,n,s) for(int i=(n);i>=s;--i)

// Macro for taking input
#define SCI(x)		scanf("%d",&x)
#define SCII(x,y)	scanf("%d%d",&x,&y)
#define SCL(x)		scanf("%lld",&x)
#define SCLL(x,y)	scanf("%lld%lld",&x,&y)
#define PRI(x)		printf("%d",x)
#define PRL(x)		printf("%lld",x)
#define PRLL(x)		printf("%lld",x)

vector<list<int>*> graph;

void addEdge(int u,int v)
{
	graph[u]->push_back(v);
	graph[v]->push_back(u);
}

int main()
{
	int n;
	SCI(n);

	FO(i,0,n)
	{
		list<int> *l =new list<int>();
		graph.PB(l);
	}

	int e;
	int u,v;
	SCI(e);
	FO(i,0,e)
	{
		SCII(u,v);
	}

}