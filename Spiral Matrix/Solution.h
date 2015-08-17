#include<vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size();
		if (m<1)
		{
			return res;
		}
		int n = matrix[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		int dir[4][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}};
		
		int r=0, c=0;
		res.push_back(matrix[r][c]);
		visited[r][c] = true;
		for (int i=0; res.size()<m*n; i++)
		{
			int idx = i%4;
			while( c+dir[idx][1]<n && c+dir[idx][1]>=0 
				&& r+dir[idx][0]<m && r+dir[idx][0]>=0
				&& !visited[r+dir[idx][0]][c+dir[idx][1]])
			{
				r += dir[idx][0];
				c += dir[idx][1];
				res.push_back(matrix[r][c]);
				visited[r][c] = true;
			}
		}
		return res;
	}
};