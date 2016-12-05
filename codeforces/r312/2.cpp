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
    int n,l=0,r=-1,templ,tempr,flag=1;
    int a[100000],b[1000001];
    scanf("%d",&n);
    ini(b,0);
    fo(i,n)
    {
        scanf("%d",&a[i]);
        b[a[i]]+=1;
    }
    int m=b[0],index=0;
    for(int i=1;i<1000001;i++)
    {
        if(m<b[i])
        {
            m=b[i];
            index=i;
        }
    }
    vector<int> smallest;
    smallest.push_back(index);
    for(int i=0;i<1000001;i++)
    {
        if(m==b[i] && i!=index)
            smallest.push_back(i);
    }
    for(int j=0;j<smallest.size();j++)
    {
        fo(i,n)
        {
            if(smallest[j]==a[i])
            {
                templ=i+1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(smallest[j]==a[i])
            {
                tempr=i+1;
                break;
            }
        }
        if(flag)
        {
            l=templ;r=tempr;flag=0;
        }
        else
        {
            if(tempr-templ+1 < (r-l+1))
            {
                l=templ;
                r=tempr;
            }
        }
    }
    printf("%d %d",l,r);
    return 0;
}
