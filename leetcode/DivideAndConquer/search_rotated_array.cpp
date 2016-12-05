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

int find_pivot(vector<int>& nums,int start,int end){

if(start>=end)return -1;

int mid=(start+end)/2;

if(mid+1<nums.size())
{
if(nums.at(mid)>nums.at(mid+1)) return mid;
}

if(mid-1>=0)
{
if(nums.at(mid)<nums.at(mid-1)) return mid-1;
}

if(nums.at(start) >= nums.at(mid))
    return find_pivot(nums,0,mid-1);

else
    return find_pivot(nums,mid+1,end);
}

int bs(vector<int>&nums ,int start,int end,int target){

    if(start>end) return -1;

    int mid=(start+end)/2;

    if(nums.at(mid)==target) return mid;

    if(target>nums.at(mid))
        return bs(nums,mid+1,end,target);

    else
        return bs(nums,start,mid-1,target);
}

 int _search(vector<int>& nums, int target) {
        int pivot=find_pivot(nums,0,(nums.size()-1));
        if(pivot==-1)
            return bs(nums,0,(nums.size()-1),target);

        if(nums.at(pivot)==target) return pivot;

        if(target <= nums.at(pivot) && target >= nums.at(0))
            return bs(nums,0,pivot-1,target);

        else
            return bs(nums,pivot+1,nums.size()-1,target);
    }

int main()
{
    vector<int> a;
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    cout << _search(a,0);
    return 0;
}
