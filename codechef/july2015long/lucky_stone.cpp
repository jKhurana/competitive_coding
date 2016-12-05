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
    int n;
    ll number,temp;
    scanf("%d",&n);
    fo(i,n)
    {
        scanf("%lld",&number);
        int r=number%10;
        if(r!=0 &&r!=5)
            printf("%lld\n",number);
        else
        {
            temp=number;
            while(1)
            {
                int r=temp%10;
                if(r==5)
                {
                    number=number*4;
                    temp=number;
                }
                else if(r==0)
                {
                    while(1)
                    {
                        r=temp%10;
                        if(r==0)
                            temp=temp/10;
                        else
                            break;
                    }
                    if(r==5)
                    {
                        number=number*4;
                        temp=number;
                    }
                    else
                    {
                        printf("%lld\n",number);
                        break;
                    }
                }
                else
                {
                    printf("%lld\n",temp);
                    break;
                }
            }
        }
    }
    return 0;
}
