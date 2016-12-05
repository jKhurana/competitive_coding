#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
#include<climits>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

// http://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/

//max subarray sum
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > points(n,vector<int>(m));
	vector<vector<int> > dp(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>points[i][j];

	cout<<"-------------"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<points[i][j]<<"   ";
		cout<<endl;
	}
	cout<<"======================="<<endl;
	dp[n-1][m-1] = (points[n-1][m-1]>0)?1:((points[n-1][m-1]==0)?1:abs(points[n-1][m-1])+1);
	cout<<" last cell : "<<dp[n-1][m-1]<<endl;
	//if last cell is positive the, fill it with 1
	//else if it is 0, then fill it with 1
	//else fill it with 1 more than the magnitude of the negative number.. -5 ==> 6

	for(int i=n-2;i>=0;i--){
		//fill the last column, bottom up
		dp[i][m-1] = max(dp[i+1][m-1]-points[i][m-1],1);
	}
	for(int j=m-2;j>=0;j--){
		//fill the last row, right to left
		dp[n-1][j] = max(dp[n-1][j+1]-points[n-1][j],1);
	}
	int min_points_on_exit;
	for(int i = n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			min_points_on_exit = min(dp[i+1][j], dp[i][j+1]);
			dp[i][j] = max(min_points_on_exit - points[i][j], 1);

		}
	}

	cout<<"------DP table-------"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<"======================="<<endl;

	cout<<"Min points needed : "<<dp[0][0]<<endl;
	return 0;

}