#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n<2)
		{
			return nums.empty() ? 0 : nums[0];
		}

		int a = rob(nums, 0, n-2);
		int b = rob(nums, 1, n-1);
		return max(a, b);
	}

	int rob(vector<int>& nums, int start, int end)
	{
		int n = end-start+1;
		if (n<2)
		{
			return nums.empty() ? 0 : nums[start];
		}
		vector<int> dp(n, 0);
		dp[0] = nums[start];
		dp[1] = max(nums[start], nums[start+1]);

		for (int i=2; i<n; i++)
		{
			dp[i] = max(nums[start+i]+dp[i-2], dp[i-1]);
		}
		return dp[n-1];
	}
};

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n<2)
		{
			return nums.empty() ? 0 : nums[0];
		}
		vector<int> dp(n-1, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for (int i=2; i<n-1; i++)
		{
			dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
		}
		int a = dp[n-2];

		dp[0] = nums[1];
		dp[1] = max(nums[1], nums[2]);
		for (int i=3; i<n; i++)
		{
			dp[i-1] = max(nums[i]+dp[i-3], dp[i-2]);
		}
		int b = dp[n-2];
		return max(a, b);
	}
};