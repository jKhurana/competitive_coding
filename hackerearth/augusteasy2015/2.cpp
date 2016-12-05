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

int main()
{
    string str;
    int n;
    cin >> n >> str;
    int f[50000],l[50000];
    int i;
    for(i=0;i<str.size()/2;i++)
    {
        f[i]=str[i]-96;
    }
    int k=0;
    for(;i<str.size();i++,k++)
    {
        l[k]=str[i]-97;
    }
    sort(f,f+str.size()/2);
    sort(l,l+str.size()/2);
    int e=0,g=0,s=0;
    for(int i=0;i<str.size()/2;i++)
    {
        if(f[i]==l[i])
        {
            g+=1;
            s+=1;
        }
        else if(f[i]>l[i])
        {
            e+=(f[i]-l[i]);
            s+=(f[i]-l[i])+1;
        }
        else
        {
            e+=(l[i]-f[i]);
            g+=(l[i]-f[i])+1;
        }
    }
    if(e<g)
    {
        if(e<s)
            printf("%d",e);
        else
            printf("%d",s);
    }
    else
    {
        if(g>s)
            printf("%d",s);
        else
            printf("%d",g);
    }
    return 0;
}
