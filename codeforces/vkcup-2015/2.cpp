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

struct Node
{
    int data;
    vector<struct Node*> child;
};

struct Node *root=(struct Node*)malloc(sizeof(struct Node));

void insertNode(struct Node *root,int value)
{
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data=value;
    struct Node *temp=root;
    struct Node *parent=root;
    int i,nodesize;
    while(1)
    {
        nodesize=temp->child.size();
        for(i=0;i<temp->child.size();i++)
        {
            if(value % temp->child[i]->data==0)
            {
                parent=temp;
                temp=temp->child[i];
                break;
            }
        }
        if(i==nodesize)
        {
            parent->child.push_back(n);
            break;
        }
    }

}
int maxHeight(struct Node *root)
{
    if(root==NULL)
        return 0;
    int height=0;
    for(int i=0;i<root->child.size();i++)
    {
        int temp = maxHeight(root->child[i]);
        if(height<temp)
            height=temp;
    }
    return height+1;
}

int main()
{
    int n,temp;
    scanf("%d",&n);
    fo(i,n)
    {
        scanf("%d",&temp);
        insertNode(root,temp);
    }

    printf("%d",maxHeight(root));
    return 0;
}
