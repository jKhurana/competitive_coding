#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

// table to represent the ground of Game
int ground[501][501]; 
/* Each entry (i,j) of score represents the maximum score of reaching right border
form cell (i,j).
*/
long long score[501][501]; 
/* Each entry (i,j) of top represents the maximum score of reaching right border if snake enter into
(i,j) from (i-1,j) cell 
*/
long long top[501][501];
/* Each entry (i,j) of bot represents the maximum score of reaching right border if snake enter into
(i,j) from (i+1,j) cell 
*/
long long bot[501][501];
/* Each entry (i,j) of lef represents the maximum score of reaching right border if snake enter into
(i,j) from (i,j-1) cell 
*/
long long lef[501][501];
/* if (i,j) == 1 means cell (i,j) can be reached from left border
   else (i,j) == 0 means cell (i,j) is not reachable from left border 
*/
int reachability[501][501];
// size of grid
int n,m;


/* This method fills the reachability matrix(defined above) using BFS algorithm 
Special care has been taken to keep the teleporate node connected. 
Each cell has been taken as a node of graph.
This method visite each node once so time complexcity of above algorithm is O(n*m)*/
void fill_reachability_matrix()
{

	bool visited[501][501]; // keep track whether node is visited or not

	// assign default value to visit and reachability matrix
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			reachability[i][j]=0;
			visited[i][j]=false;
		}

	queue<pair<int,int> > que;
	for(int i=1;i<=n;i++)
	{
		que.push(make_pair(i,1));
		visited[i][1]=true;
	}

	while(!que.empty())
	{
		pair<int,int> element=que.front();
		que.pop();
		int i=element.first;
		int j=element.second;
		visited[i][j]=true;
		if(ground[i][j]==-1)
		{
			continue;
		}

		reachability[i][j]=1;

		// check the top node
		if(i-1>0 && !visited[i-1][j])
		{
			visited[i-1][j]=true;
			que.push(make_pair(i-1,j));
		}

		// check bottom node
		if(i+1<=n && !visited[i+1][j])
		{
			visited[i+1][j]=true;
			que.push(make_pair(i+1,j));
		}

		// check right node
		if(j+1<=m && !visited[i][j+1])
		{
			visited[i][j+1]=true;
			que.push(make_pair(i,j+1));
		}

		// check for reachability through teleporate
		if(i==1 && !visited[n][j])
		{
			visited[n][j]=true;
			que.push(make_pair(n,j));
		}
		if(i==n && !visited[1][j])
		{
			visited[1][j]=true;
			que.push(make_pair(1,j));
		}
	}
}

/* This mehtod fill the top, bot and lef table using dynamic programming approach in O(n*m).
We fill the table column wise from right to left in the following way
1. First we fill ith column of top table using (i+1)th column of lef table.
2. Second we fill ith column of bot table using (i+1)th column of lef table.
3. Third we fill ith colum of lef table using ith column of top and bot and (i+1)th column of lef table

Note-: Special care has to be taken if cell goes out of ground or there is a block in the way*/
void fill_top_bot_lef_tables()
{
	for(int j=m;j>=0;j--)
	{
			// fill top table
			for(int i=n;i>=1;i--)
			{
				if(i-1>=1)
				{
					long long cellvalue=ground[i][j];
					long long max;
					// assign special value to max in case of right border
					if(j==m)
						max=cellvalue;
					else
						max=-1;
					// If block is present , assign block and go for next iteration
					if(ground[i][j]==-1)
					{
						top[i][j]=-1;
						continue;
					}
					// check bottom
					if(i+1<=n && top[i+1][j]!=-1)
					{
						if(cellvalue+top[i+1][j]>max)
							max=cellvalue+top[i+1][j];
					}
					// check lef
					if(j+1<=m && lef[i][j+1]!=-1)
					{
						if(cellvalue+lef[i][j+1]>max)
							max=cellvalue+lef[i][j+1];
					}
					top[i][j]=max;
				}
				else
					top[i][j]=-1;
			}


			// fill bot table
			for(int i=1;i<=n;i++)
			{
				if(i+1<=n)
				{
					long long cellvalue=ground[i][j];
					long long max;
					// assign special value to max in case of right border
					if(j==m)
						max=cellvalue;
					else
						max=-1;
					// If block is present , assign block and go for next iteration
					if(ground[i][j]==-1)
					{
						bot[i][j]=-1;
						continue;
					}
					// check bottom
					if(i-1>=1 && bot[i-1][j]!=-1)
					{
						if(cellvalue+bot[i-1][j]>max)
							max=cellvalue+bot[i-1][j];
					}
					// check lef
					if(j+1<=m && lef[i][j+1]!=-1)
					{
						if(cellvalue+lef[i][j+1]>max)
							max=cellvalue+lef[i][j+1];
					}
					bot[i][j]=max;
				}
				else
					bot[i][j]=-1;
			}
			// fill lef table
			for(int i=1;i<=n;i++)
				{
					long long max=-1;
					// If block is present , assign block and go for next iteration
					if(ground[i][j]==-1)
					{
						lef[i][j]=-1;
						continue;
					}
					long long cellvalue=ground[i][j];
					// assign special value to max in case of right border
					if(j==m)
						max=cellvalue;
					else
						max=-1;
					// check top
					if(i-1>=1 && bot[i-1][j]!=-1)
					{
						if(cellvalue+bot[i-1][j]>max)
							max=cellvalue+bot[i-1][j];
					}
					// check bottom
					if(i+1<=n && top[i+1][j]!=-1)
					{
						if(cellvalue+top[i+1][j]>max)
							max=cellvalue+top[i+1][j];
					}
					// check bottom
					if(j+1<=m && lef[i][j+1]!=-1)
					{
						if(cellvalue+lef[i][j+1]>max)
							max=cellvalue+lef[i][j+1];
					}
					lef[i][j]=max;
				}
		}
}

/* This method fill the score table using top, bot and lef table*/
void fill_score_table()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			long long max=top[i][j]>bot[i][j]?top[i][j]:bot[i][j];
			score[i][j]=max>lef[i][j]?max:lef[i][j];
		}
	}
}

/* Main Method*/

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&ground[i][j]);
		}
	fill_top_bot_lef_tables();
	fill_score_table();
	fill_reachability_matrix();
	// calculate answer
	long long ans=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(reachability[i][j]==1)
			{
				if(ans< score[i][j])
					ans=score[i][j];
			}
		}
	printf("%lld",ans);
}