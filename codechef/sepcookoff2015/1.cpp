#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
//#   define NDEBUG
#endif

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <limits.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)   for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())
#define pi(x)       printf("%d",(x));
#define pl(x)       printf("%ld",(x));
#define pll(x)      printf("%d",(x));
#define pf(x)       printf("%f",(x));
#define pd(x)       printf("%llf",(x));

const int oo = 1000000009;
const double eps = 1e-6;

const int mod = 1000000007;
const int mx = 5003;

const int mx_bit = mx;
typedef int bit_type;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);

		unordered_set<string> phrase;
		vector<string> dict;
		fo(i,n)
		{
			string temp;
			cin >> temp;
			dict.push_back(temp);
		}

		fo(i,k)
		{
			int len,flag=1;
			scanf("%d",&len);
			fo(j,len)
			{
				string temp;
				cin >> temp;
				phrase.insert(temp);
			}
		}

		fo(i,n)
		{
			auto it=phrase.find(dict[i]);
			if(it!=phrase.end())
				printf("YES ");
			else
				printf("NO ");
		}
		printf("\n");
	}
	return 0;
}