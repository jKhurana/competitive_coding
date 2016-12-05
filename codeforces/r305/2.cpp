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

int find_max(int p[][3],int n)
{
    int m=p[0][2];
    rep(i,1,n)
    {
        if(m<p[i][2])
            m=p[i][2];
    }
    return m;
}


int main()
{
    int n,m,q,l,all_max=0,index=0;
    int arr[500][500];
    int p[500][3];

    scanf("%d %d %d",&n,&m,&q);

    fo(i,n)
    {
        fo(j,m)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int t_max,temp=0;
    fo(i,n)
    {
        t_max=0;l=-1;
        fo(j,m)
        {
            temp=0;
            if(arr[i][j]==1)
            {
                l=j;
                while(arr[i][j]!=0)
                {
                    temp++;
                    j++;
                }
                if(temp>t_max)
                {
                    p[i][0]=l;
                    p[i][1]=l+temp-1;
                    p[i][2]=temp;
                    t_max=temp;
                }
            }
        }
        if(all_max<p[i][2])
        {
            all_max=p[i][2];
            index=i;
        }
    }

    int x,y;
    fo(i,q)
    {
        scanf("%d %d",&x,&y);
        x=x-1;
        y=y-1;
        if(arr[x][y]==1)
            arr[x][y]=0;
        else
            arr[x][y]=1;
        t_max=0;
        fo(j,m)
        {
            temp=0;
            if(arr[x][j]==1)
            {
                l=j;
                while(arr[x][j]!=0 && j<m)
                {
                    temp++;
                    j++;
                }
                if(temp>t_max)
                {
                    p[x][0]=l;
                    p[x][1]=l+temp-1;
                    p[x][2]=temp;
                    t_max=temp;
                }
            }
        }
    printf("%d\n",find_max(p,n));
    }
    return 0;
}
