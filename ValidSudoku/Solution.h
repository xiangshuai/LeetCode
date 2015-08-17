#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int i=0; i<9; i++)
		{
			for (int j=0; j<9; j++)
			{
				if (!isValid(board, i, j))
				{
					return false;
				}
			}
		}
		return true;
	}

	bool isValid(const vector<vector<char> > &board, int x, int y)
	{
		if (board[x][y]=='.')
		{
			return true;
		}

		// 行
		for (int i=0; i<9; i++)
		{
			if(i!=x && board[i][y]==board[x][y])
			{
				return false;
			}
		}

		// 列
		for (int i=0; i<9; i++)
		{
			if (i!=y && board[x][i]==board[x][y])
			{
				return false;
			}
		}

		// 单元
		int rst = x-x%3;
		int cst = y-y%3;
		for (int i=rst; i<rst+3; i++)
		{
			for (int j=cst; j<cst+3; j++)
			{
				if (i!=x && j!=y && board[i][j]==board[x][y])
				{
					return false;
				}
			}
		}
		return true;
	}
};