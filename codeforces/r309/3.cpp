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
    char s[101];
    int two[11][2],three[112][3];
    int r,q,q1,k=0,t1flag=0,t2flag=0,t3flag=0,nflag=1;

    for(int i=16;i<100;i+=8)
    {
        r=i%10;
        q=i/10;
        two[k][0]=q;two[k][1]=r;
        k++;
    }
    k=0;
    for(int i=104;i<1000;i+=8)
    {
        r=i%10;
        q=(i/10)%10;
        q1=i/100;
        three[k][0]=q1;three[k][1]=q;three[k][2]=r;
        k++;
    }
    scanf("%s",s);
    int i=0;
    while(s[i]!='\0')
    {
        int n=s[i]-48;
        if(n%2==0)
        {
            // for 1 digit
           if(n%8==0)
           {
                printf("YES\n");
                printf("%d",n);
                nflag=0;
                break;
           }
           // for 2 digit
            for(int j=0;j<11;j++)
            {
                if(two[j][1]==n)
                {
                    for(k=0;k<=i-1;k++)
                    {
                        if((s[k]-48)==two[j][0])
                        {
                            printf("YES\n");
                            printf("%d%d",two[j][0],two[j][1]);
                            t1flag=1;nflag=0;
                            break;
                        }
                    }
                    if(t1flag==1)
                        break;
                }
            }
            if(t1flag)
                break;
            // logic ofr 3 digit
            for(int j=0;j<112;j++)
            {
                t2flag=0;t3flag=0;
                if(three[j][2]==n)
                {
                    for(k=0;k<=i-1;k++)
                    {
                        if((s[k]-48)==three[j][0])
                        {
                            t2flag=1;
                            break;
                        }
                    }
                    for(k=k+1;k<=i-1;k++)
                    {
                        if((s[k]-48)==three[j][1])
                            t3flag=1;
                    }
                    if(t2flag && t3flag)
                    {
                        printf("YES\n");
                        printf("%d%d%d",three[j][0],three[j][1],three[j][2]);
                        nflag=0;
                        break;
                    }
                }
            }
            if(t2flag && t3flag)
                break;
        }
        i++;
    }
    if(nflag)
        printf("NO");

    return 0;
}
