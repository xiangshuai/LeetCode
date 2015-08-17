#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > result;
		vector<int> item;
		dfs(num, target, 0, item, result);
		return result;
	}

	void dfs(vector<int> &num, int gap, int start, vector<int> &item, vector<vector<int> > &result)
	{
		if (gap==0)
		{
			result.push_back(item);
			return ;
		}

		int previous = -1;
		for (int i=start; i<num.size(); i++)
		{
			if (previous==num[i])
			{
				continue;
			}
			previous = num[i];
			if (gap < num[i])
			{
				return ;
			}
			item.push_back(num[i]);
			dfs(num, gap-num[i], i+1, item, result);
			item.pop_back();
		}
	}
};