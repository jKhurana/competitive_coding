#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

// brute O(mn) solution of exact pattern matching
void brute_force(string p,string t)
{
	int i=0; // for string t
	int j=0; // for string p

	for(i=0;i<(t.size()-p.size()+1);i++)
	{
		int temp=i;
		for(j=0;j<p.size();j++)
		{
			if(p[j]!=t[temp])
				break;
			temp++;
		}
		if(j==p.size())
			ans.push_back(i);
	}
}

//--------------------------------------------------------------------------KMP Algorithm---------------------------------------------------

// compute the preprocessing of kmp algorithm
// index i represent the widest boundry of i-1 index of string
void kmp_preprocessing(string &p,vector<int> &b)
{
	int i=0, j=-1;
    b[i]=j;
    while (i<p.size())
    {
        while (j>=0 && p[i]!=p[j]) j=b[j];
        i++; j++;
        b[i]=j;
    }
}

void kmp_searching(vector<int> &b,string p,string t)
{
	int i=0, j=0;
    while (i<t.size())
    {
        while (j>=0 && t[i]!=p[j]) j=b[j];
        i++; j++;
        if (j==p.size())
        {
            ans.push_back(i-j);
            j=b[j];
        }
    }

}

int main()
{
	string t,p;
	cin >> t >> p;
	vector<int> b(p.size()+1,0);
	kmp_preprocessing(p,b);
	kmp_searching(b,p,t);
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
}