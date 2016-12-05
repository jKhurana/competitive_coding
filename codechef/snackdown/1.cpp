#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
//#   define NDEBUG
#endif

#include <stdlib.h>
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
    int kases,flag,sum=0,f_index,l_index,first_time=1;
    int arr[50],n,temp[50],ans[50];
    cin >> kases;
    rep(kase, 1, kases) {
        sum=0;
        flag=0;
        first_time=1;
        scanf("%d",&n);
        fo(i,n)
        {
            scanf("%d",&arr[i]);
        }
        fo(j,n)
        {
            if(arr[j]>=n)
            {
                flag=1;
                break;
            }
            sum=sum+arr[j];
            if(arr[j]!=0 && first_time)
            {
                l_index=j;
                f_index=j;
                first_time=0;
            }
            else if(arr[j]!=0)
            {
                l_index=j;
            }
        }
        if(flag==1 || sum!=n)
        {
            printf("%d\n",-1);
            continue;
        }
        ini(temp,0);
        int p;
        if(f_index==n-1)
            p=0;
        else
            p=f_index+1;
        re(i,f_index,n)
        {
            if(arr[i]!=0)
            {
                while(arr[i]!=0 && p<n)
                {
                    if(arr[p]!=0)
                    {
                        arr[i]=arr[i]-1;
                        temp[p]=1;
                        ans[p]=i;
                    }
                    p++;
                }
            }
        }
        arr[l_index]--;
        temp[f_index]=1;
        ans[f_index]=l_index;
        p=0;
        fo(i,n)
        {
            if(arr[i]!=0)
            {
                while(arr[i]!=0)
                {
                    if(temp[p]==0)
                    {
                        temp[p]=1;
                        arr[i]--;
                        ans[p]=i;
                    }
                    p++;
                }
            }
        }
        fo(i,n-1)
        {
            printf("%d ",ans[i]+1);
        }
        printf("%d",ans[n-1]+1);
        printf("\n");
    }
    return 0;
}
