#include <vector>
#define INT_MAX 2147483647
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		if (n<1)
		{
			return 0;
		}
		int minSum = INT_MAX;
		dfs(triangle, 0, 0, 0, minSum);
		return minSum;
	}

	void dfs(vector<vector<int> > &triangle, int level, int index, int total, int &minSum)
	{
		int n = triangle.size();
		if (level==n)
		{
			if (total<minSum)
			{
				minSum = total;
			}
			return ;
		}

		int dir[2] = {0, 1};
		int m = triangle[level].size();
		for (int i=0; i<sizeof(dir)/sizeof(dir[0]); i++)
		{
			int idx = index+dir[i];
			if (idx>=0 && idx<m)
			{
				dfs(triangle, level+1, idx, total+triangle[level][idx], minSum);
			}
		}
	}
};

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		if (n<1)
		{
			return 0;
		}
		for (int i=1; i<n; i++)
		{
			for (int j=0; j<triangle[i].size(); j++)
			{
				if (j==0)
				{
					triangle[i][j] += triangle[i-1][j];
				}
				else if (j<triangle[i].size()-1)
				{
					triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
				}
				else
				{
					triangle[i][j] += triangle[i-1][j-1];
				}
			}
		}
		sort(triangle[n-1].begin(), triangle[n-1].end());
		return triangle[n-1][0];
	}
};

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		if (n<1)
		{
			return 0;
		}
		vector<int> minSum(triangle.back());
		for (int i=n-2; i>=0; i--)
		{
			for (int j=0; j<triangle[i].size(); j++)
			{
				minSum[j] = triangle[i][j] + min(minSum[j], minSum[j+1]);
			}
		}
		return minSum[0];
	}
};