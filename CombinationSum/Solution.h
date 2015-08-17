#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > result;
		vector<int> item;
		dfs(candidates, target, 0, item, result);
		return result;
	}

	void dfs(vector<int> &candidates, int gap, int start, vector<int> &item, vector<vector<int> > &result)
	{
		if (gap==0)
		{
			result.push_back(item);
			return ;
		}


		for (int i=start; i<candidates.size(); i++)
		{
			if (gap < candidates[i])
			{
				return ;
			}
			item.push_back(candidates[i]);
			dfs(candidates, gap-candidates[i], i, item, result);
			item.pop_back();
		}
	}
};