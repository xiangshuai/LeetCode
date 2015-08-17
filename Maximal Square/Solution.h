#include<vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int ret = 0;
		if (matrix.size()<1)
		{
			return ret;
		}
		int n = matrix.size();
		int m = matrix[0].size();

		vector<vector<int>> dp(n, vector<int>(m, 0));
		
		for (int i=0; i<n; i++)
		{
			if (matrix[i][0]=='1')
			{
				dp[i][0] = 1;
			}
		}

		for (int j=0; j<m; j++)
		{
			if (matrix[0][j]=='1')
			{
				dp[0][j] =  1;
			}
		}

		for (int i=1; i<n; i++)
		{
			for (int j=1; j<m; j++)
			{
				if (matrix[i][j]=='1')
				{
					dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j])) + 1;
				}
			}
		}

		for (int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				ret = max(ret, dp[i][j]);
			}
		}
		return ret*ret;
	}

};