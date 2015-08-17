#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if (board.empty())
		{
			return ;
		}

		int m = board.size();
		int n = board[0].size();

		for (int i=0; i<n; i++)
		{
			bfs(board, 0, i);
			bfs(board, m-1, i);
		}

		for (int j=0; j<m-1; j++)
		{
			bfs(board, j, 0);
			bfs(board, j, n-1);
		}

		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (board[i][j]=='O')
				{
					board[i][j] = 'X';
				}
				else if (board[i][j]=='+')
				{
					board[i][j] = 'O';
				}
			}
		}

	}

	void bfs(vector<vector<char>> &board, int i, int j)
	{
		typedef pair<int, int> state;
		queue<state> sque;

		int m = board.size();
		int n = board[0].size();

		if (board[i][j]=='O')
		{
			board[i][j] = '+';
			sque.push(state(i, j));
		}

		while(!sque.empty())
		{
			state curst = sque.front();
			sque.pop();

			int x = curst.first;
			int y = curst.second;

			const state new_states[4] = {state(x-1, y), state(x+1, y), 
				state(x, y-1), state(x, y+1)};

			for (int i=0; i<4; i++)
			{
				if(!(new_states[i].first<0 || new_states[i].first>=m
					|| new_states[i].second<0 || new_states[i].second>=n))
				{
					if (board[new_states[i].first][new_states[i].second]=='O')
					{
						board[new_states[i].first][new_states[i].second] = '+';
						sque.push(new_states[i]);
					}
				}
			}
		}
	}
};