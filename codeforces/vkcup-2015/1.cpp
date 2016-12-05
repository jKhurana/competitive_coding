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

struct trie
{
    int data[26];
    int flag[26];
    struct trie *arr[26];
};

struct trie *head=null;

void insertintrie(struct trie *head,string s)
{
    struct trie *currentNode=null;
    if(head==null)
    {
        currentNode = (struct trie*)malloc(sizeof(struct trie));
        head=currentNode;
    }
    else
        currentNode=head;
    for(int i=0;i<s.size();i++)
    {
        if(currentNode->arr[s[i]-97]==null)
        {
            struct trie temp = (struct trie*)malloc(struct trie);
            currentNode->flag=0;
            currentNode->data=i+1;
            for(int j=0;j<26;j++)
                temp->arr[j]=null;
            currentNode->arr[s[i]-97]=temp;
            currentNode=temp;
        }
        else
        {
            currentNode=currentNode->arr[s[i]-97];
        }
    }
}

int main()
{
    string s;
    int n;
    fo(i,n)
    {
        cin >> s;
        insertintrie(trie,s);

    }
    return 0;
}
