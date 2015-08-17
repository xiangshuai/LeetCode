#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(s.size()+1, false);
		vector<vector<bool>> prev(s.size()+1, vector<bool>(s.size(), false));
		dp[0] = true;
		for (int i=1; i<=s.size(); i++)
		{
			for (int j=0; j<i; j++)
			{
				if (dp[j] && wordDict.find(s.substr(j, i-j))!=wordDict.end())
				{
					dp[i] = true;
					prev[i][j] = true;
				}
			}
		}
		vector<string> result;
		vector<string> path;
		gen_path(s, prev, s.length(), path, result);
		return result;
	}

	void gen_path(string &s, vector<vector<bool>> &prev, int len, 
		vector<string> path, vector<string> &result)
	{
		if (len==0)
		{
			reverse(path.begin(), path.end());
			string item = "";
			for (int i=0; i<path.size(); i++)
			{
				item += path[i];
				item.push_back(' ');
			}
			item.pop_back();
			result.push_back(item);
			return ;
		}

		for (int i=0; i<s.size(); i++)
		{
			if (prev[len][i])
			{
				string sub = s.substr(i, len-i);
				path.push_back(sub);
				gen_path(s, prev, i, path, result);
				path.pop_back();
			}
		}
	}
};