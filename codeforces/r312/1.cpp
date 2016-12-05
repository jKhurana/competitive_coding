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

bool pairCompare(const std::pair<int, int>& firstElem, const std::pair<int, int>& secondElem) {
  return firstElem.first < secondElem.first;

}

int main()
{
    int n,x,a,possize,negsize,totalapple=0;
    vector<pair<int,int> > pos;
    vector<pair<int,int> > neg;
    scanf("%d",&n);
    fo(i,n)
    {
        scanf("%d %d",&x,&a);
        if(x<0)
            neg.push_back(make_pair(x,a));
        else
            pos.push_back(make_pair(x,a));
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    if(pos.size()==neg.size())
    {
        possize=negsize=pos.size();
    }
    else if(pos.size()<neg.size())
    {
        possize=pos.size();
        negsize=possize+1;
    }
    else
    {
        negsize=neg.size();
        possize=negsize+1;
    }
    fo(i,possize)
    {
        totalapple+=pos[i].second;
    }
    for(int i=neg.size()-1;negsize>0;i--,negsize--)
    {
        totalapple+=neg[i].second;
    }
    printf("%d",totalapple);
    return 0;
}
