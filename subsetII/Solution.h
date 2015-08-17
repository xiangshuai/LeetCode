#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		dfs(nums, 0, path, result);
		return result;
	}

	void dfs(vector<int> &nums, int step, vector<int> &path, vector<vector<int> > &rset)
	{
		rset.push_back(path);

		for (int i=step; i<nums.size(); i++)
		{
			if (i!=step && nums[i]==nums[i-1])
			{
				continue;
			}
			path.push_back(nums[i]);
			dfs(nums, i+1, path, rset);
			path.pop_back();
		}
	}
};