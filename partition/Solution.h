#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {

		vector<vector<string> > rets;
		int n = s.length();
		vector<vector<bool> > dp(n, vector<bool>(n, false));
		for (int i=0; i<n; i++)
		{
			dp[i][i] = true;
		}
		for (int i=n-1; i>=0; i--)
		{
			for (int j=i+1; j<n; j++)
			{
				if (s[i]==s[j] && (dp[i+1][j-1] || i+1 > j-1))
				{
					dp[i][j] = true;
				}
			}
		}

		vector<string> item;
		recursion(rets, 0, s, item, dp);
		return rets;
	}

	void recursion(vector<vector<string>> &rets, int start, string &s, vector<string> &item, vector<vector<bool>> &dp)
	{
		if (start == s.length())
		{
			rets.push_back(item);
			return ;
		}

		for (int i=start; i<s.length(); i++)
		{
			if (dp[start][i])
			{
				string sub = s.substr(start, i-start+1);
				item.push_back(sub);
				recursion(rets, i+1, s, item, dp);
				item.pop_back();
			}
		}
	}
};