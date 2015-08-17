#include <vector>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		if (n<1)
		{
			return 0;
		}
		int ret = 0;
		int m = grid[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				if (dfs(grid, visited, i, j))
				{
					ret++;
				}
			}
		}
		return ret;
	}

	bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
	{
		int n = grid.size();
		int m = grid[0].size();
		if (x<0 || y<0 || x==n || y==m || grid[x][y]=='0' || visited[x][y])
		{
			return false;
		}
		
		visited[x][y] = true;
		int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
		int i=0; 
		for (int i=0; i<sizeof(dir)/sizeof(dir[0]); i++)
		{
			dfs(grid, visited, x+dir[i][0], y+dir[i][1]);
		}
		return true;
	}
};