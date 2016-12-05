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
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())

const int oo = 1000000009;
const double eps = 1e-6;

const int mod = 1000000007;
const int mx = 5003;

const int mx_bit = mx;
typedef int bit_type;

char s[100001];

int main()
{
    int f1=0,f2=0;
    scanf("%s",s);

    int len=strlen(s);
    int i=0,j;
    for(i=0;i<len-1;i++)
    {
        if(s[i]=='A' && s[i+1]=='B')
        {
            f1=1;
            break;
        }
    }
    for(j=i+2;j<len-1;j++)
    {
        if(s[j]=='B' && s[j+1]=='A')
        {
            f2=1;
            break;
        }
    }
    if(!(f1 && f2))
    {
    f1=0;f2=0;
    for(i=0;i<len-1;i++)
    {
        if(s[i]=='B' && s[i+1]=='A')
        {
            f1=1;
            break;
        }
    }
    for(j=i+2;j<len-1;j++)
    {
        if(s[j]=='A' && s[j+1]=='B')
        {
            f2=1;
            break;
        }
    }
    }
    if(f1 && f2)
        printf("YES");
    else
        printf("NO");
    return 0;
}
