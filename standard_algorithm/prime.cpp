#include <iostream>
#include <queue>
#include <list>
#include <math.h>

using namespace std;

int isPrime(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    //int sroot=sqrt(n);
    for(int i=3;i<n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
// Driver program for checking Prime
int main()
{
    int n;
    while(1)
    {
        cin >>n;
        if(n==-1)
            break;
        int result=isPrime(n);
        if(result)
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }
    return 0;
}


