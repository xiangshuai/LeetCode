#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		if (n<1)
		{
			return res;
		}
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		int dir[4][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}};

		int r=0, c=0;
		int cval = 1;
		res[r][c] = cval++;
		visited[r][c] = true;
		for (int i=2; cval<n*n; i++)
		{
			int idx = i%4;
			while( c+dir[idx][1]<n && c+dir[idx][1]>=0 
				&& r+dir[idx][0]<n && r+dir[idx][0]>=0
				&& !visited[r+dir[idx][0]][c+dir[idx][1]])
			{
				r += dir[idx][0];
				c += dir[idx][1];
				res[r][c] = cval++;
				visited[r][c] = true;
			}
		}
		return res;
	}
};