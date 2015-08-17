#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ret;
		if (k<1)
		{
			return ret;
		}
		vector<int> item;
		if (k==1)
		{
			item.push_back(n);
			ret.push_back(item);
			return ret;
		}
		for (int i=1; i<10; i++)
		{
			item.push_back(i);
			dfs(1, i, k, n, item, ret);
			item.pop_back();
		}
		return ret;
	}

	void dfs(int level, int sum, int k, int n, vector<int>& item, vector<vector<int>>& ret)
	{
		if (level==k)
		{
			if (sum==n)
			{
				ret.push_back(item);
				
			}
			return ;
		}

		for (int i=item.back()+1; i<9; i++)
		{
			item.push_back(i);
			dfs(level+1, sum+i, k, n, item, ret);
			item.pop_back();
		}
	}
};



