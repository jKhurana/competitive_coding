#include <iostream>
#define for(a,b) for(int i=a;i<b;i++)

using namespace std;

int main()
{
    int t;
    long n,k;
    long a[100001],b[100001];
    long maxprof=0,temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(0,n)
        {
            cin >> a[i];
        }
        for(0,n)
        {
            cin >> b[i];
        }
        for(0,n)
        {
            temp=k/a[i];
            temp*=b[i];
            if(maxprof<temp)
                maxprof=temp;
        }
        cout << maxprof << "\n";
    }
    return 0;
}
