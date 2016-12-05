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
    int kases;
    char str[100001];
    char temp[100000];
    unsigned int k;
    cin >> kases;
    rep(kase, 1, kases) {
        map<string,int> uni;
        stack<char> s;
        scanf("%s",str);
        scanf("%u",&k);
        int n=strlen(str);
        if(k>100000)
            printf("-1\n");
        else
        {
            int flag=1,i=0;
            while(str[i]!='\0')
            {
                if(str[i]=='(')
                    s.push(str[i]);
                else
                {
                    if(s.empty())
                    {
                        flag=0;
                        break;
                    }
                    s.pop();
                }
                i++;
            }
            if(!flag || !s.empty())
            {
                if(k==1)
                    printf("%s\n",str);
                else
                    printf("-1\n");
            }
            else
            {
                int j=0,z=0;
                fo(l,n)
                {
                    j=0;z=0;
                    while(str[z]!='\0')
                    {
                        if(z!=l)
                        {
                            temp[j]=str[z];
                            j++;
                        }
                        z++;
                    }
                    temp[j]='\0';
                    string mstr=temp;
                    uni.insert(make_pair(mstr,0));
                }
                if(((signed int)uni.size())<k)
                    printf("-1\n");
                else
                {
                    std::map<string,int>::iterator itr=uni.begin();
                    advance(itr,k-1);
                    cout << itr->first;
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
