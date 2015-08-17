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
		vector<int> dp(n, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i=2; i<n; i++)
		{
			dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
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
		int a = nums[0];
		int b = max(nums[0], nums[1]);

		for (int i=2; i<nums.size(); i++)
		{
			if (i%2==0)
			{
				a = max(nums[i]+a, b);
			}
			else
			{
				b = max(nums[i]+b, a);
			}
		}
		return max(a, b);
	}
}