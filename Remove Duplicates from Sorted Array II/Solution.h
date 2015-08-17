#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n<3)
		{
			return n;
		}

		int end=1;
		for (int i=2; i<n; i++)
		{
			if (nums[i]==nums[end-1])
			{
				continue;
			}
			nums[++end] = nums[i];
		}
		return end+1;
	}
};