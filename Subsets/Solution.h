#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		dfs(nums, 0, path, result);
		return result;
	}

	void dfs(vector<int> &nums, int step, vector<int> &path, vector<vector<int>> &result)
	{
		result.push_back(path);
		for (int i=step; i<nums.size(); i++)
		{
			path.push_back(nums[i]);
			dfs(nums, i+1, path, result);
			path.pop_back();
		}
	}
};