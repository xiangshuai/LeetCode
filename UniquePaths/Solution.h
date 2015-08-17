#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
		return dfs(memo, m, n);
	}

	int dfs(vector<vector<int>> &memo, int m, int n)
	{
		if (m<1 && n<1)
		{
			return 0;
		}

		if (m==1 || n==1)
		{
			return 1;
		}

		return getOrUpdate(memo, m-1, n) + getOrUpdate(memo, m, n-1);
	}

	int getOrUpdate(vector<vector<int>> &memo, int m, int n)
	{
		if (memo[m][n]>0)
		{
			return memo[m][n];
		}
		memo[m][n] = dfs(memo, m, n);
		return memo[m][n];
	}
};