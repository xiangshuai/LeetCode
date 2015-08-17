#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.size()==0)
		{
			return 0;
		}

		m = obstacleGrid.size();
		n = obstacleGrid[0].size();

		memo = vector<vector<int>> (m, vector<int>(n, 0));

		return dfs(obstacleGrid, 0, 0);
	}

	int dfs(vector<vector<int> > &obstacleGrid, int i, int j)
	{
		if (i>=m || j>=n)
		{
			return 0;
		}

		if (obstacleGrid[i][j]==1)
		{
			return 0;
		}

		if (i==m-1 || j==n-1)
		{
			return 1;
		}

		return getOrUpdate(obstacleGrid, i+1, j) + getOrUpdate(obstacleGrid, i, j+1);
	}

	int getOrUpdate(vector<vector<int> > &obstacleGrid,int i, int j)
	{
		if (memo[i][j]>0)
		{
			return memo[i][j];
		}
		memo[i][j] = dfs(obstacleGrid, i, j);
		return memo[i][j];
	}
private:
	vector<vector<int>> memo;
	int m;
	int n;
};