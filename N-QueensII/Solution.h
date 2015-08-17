#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		int result = 0;
		if (n==0)
		{
			return result;
		}
		vector<int> queen(n, -1);
		dfs(result, queen, 0);
		return result;
	}

	void dfs(int &result, vector<int> &queen, int row)
	{
		int n = queen.size();
		if (row==n)
		{
			result++;
			return ; 
		}

		for (int col=0; col<n; col++)
		{
			if (canPut(queen, row, col))
			{
				queen[row] = col;
				dfs(result, queen, row+1);
				queen[row] = -1;
			}
		}
	}

	bool canPut(const vector<int> &queen, int row, int col)
	{
		int n = queen.size();
		for (int i=0; i<row; i++)
		{
			if (queen[i]==col || abs(row-i) == abs(col-queen[i]))
			{
				return false;
			}
		}
		return true;
	}

};