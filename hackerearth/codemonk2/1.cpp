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

int find_place(int x1,int y1,int x2,int y2,int x,int y)
{
    if(x==x1 && y==y1)
        return 1;
    if(x==x2 && y==y1)
        return 2;
    if(x==x2 && y==y2)
        return 3;
    if(x==x1 && y==y2)
        return 4;
    if(x==x1 && y>y1 && y<y2)
        return 5;
    if(x>x1 && x<x2 && y==y1)
        return 6;
    if(x==x2 && y>y1 && y<y2)
        return 7;
    if(y==y2 && x>x1 && x<x2)
        return 8;
    if(x==x1 && y<y1)
        return 9;
    if(x==x2 && y<y1)
        return 10;
    if(y==y1 && x>x2)
        return 11;
    if(y==y2 && x>x2)
        return 12;
    if(x==x2 && y>y2)
        return 13;
    if(x==x1 && y>y2)
        return 14;
    if(y==y2 && x<x1)
        return 15;
    if(y==y1 && x<x1)
        return 16;
    if(x<x1 && y<y1)
        return 17;
    if(x>x1 && x<x2 && y<y1)
        return 18;
    if(x>x2 && y<y1)
        return 19;
    if(x>x2 && y>y1 && y<y2)
        return 20;
    if(x>x2 && y>y2)
        return 21;
    if(x>x1 && x< x2 && y>y2)
        return 22;
    if(x<x1 && y>y2)
        return 23;
    if(x<x1 && y>y1 && y<y2)
        return 24;
    if(x>x1 && x<x2 && y>y1 && y<y2)
        return 25;
    return 0;
}

int main()
{
    int kases;
    int x1,y1,x2,y2;
    int pos[4];
    int a[8];
    cin >> kases;
    rep(kase, 1, kases) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d %d %d %d",&a[0],&a[1],&a[4],&a[5]);
        a[2]=a[4];
        a[3]=a[1];
        a[6]=a[0];
        a[7]=a[5];
        for(int i=0,k=0;i<8;i+=2,k++)
        {
            pos[k]=find_place(x1,y1,x2,y2,a[i],a[i+1]);
        }
        //fo(i,4)
        //{
          //  printf("%d ",pos[i]);
        //}
        if(pos[0]==1 || pos[0]==5 || pos[0]==6 || pos[0]==25)
        {
            printf("Rectangle\n");
            continue;
        }
        if(pos[0]==2 || pos[0]==4 || pos[0]==7 || pos[0]==8)
        {
            printf("Line\n");
            continue;
        }
        if(pos[0]==3)
        {
            printf("Point\n");
            continue;
        }
        if((pos[0]>=11 && pos[0]<=14) || (pos[0]>=19 && pos[0]<=23))
        {
            printf("Apart\n");
            continue;
        }
        if(pos[0]==9)
        {
            if(pos[3]==1)
                printf("Line\n");
            else if(pos[3]==9)
                printf("Apart\n");
            else
                printf("Rectangle\n");
            continue;
        }
        if(pos[0]==10)
        {
            if(pos[3]==2)
                printf("Point\n");
            else if(pos[3]==10)
                printf("Apart\n");
            else
                printf("Line\n");
            continue;
        }
        if(pos[0]==15)
        {
            if(pos[1]==4)
                printf("Point\n");
            else if(pos[1]==15)
                printf("Apart\n");
            else
                printf("Line\n");
            continue;
        }
        if(pos[0]==16)
        {
            if(pos[1]==1)
                printf("Line\n");
            else if(pos[1]==16)
                printf("Apart\n");
            else
                printf("Rectangle\n");
            continue;
        }
        if(pos[0]==24)
        {
            if(pos[1]==5)
                printf("Line\n");
            else if(pos[1]==24)
                printf("Apart\n");
            else
                printf("Rectangle\n");
            continue;
        }
        if(pos[0]==18)
        {
            if(pos[3]==6)
                printf("Line\n");
            else if(pos[3]==18)
                printf("Apart\n");
            else
                printf("Rectangle\n");
            continue;
        }
        if(pos[0]==17)
        {
            if(pos[1]==17)
                printf("Apart\n");
            else if(pos[1]==9)
            {
                if(pos[2]==9)
                    printf("Apart\n");
                else if(pos[2]==1)
                    printf("Point\n");
                else
                    printf("Line\n");
            }
            else
            {
                if(pos[2]==18)
                    printf("Apart\n");
                else if(pos[2]==6)
                    printf("Line\n");
                else
                    printf("Rectangle\n");
            }
            continue;
        }
    }
    return 0;
}
