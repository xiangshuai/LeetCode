#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int reach = 1;
		int n = nums.size();
		for (int i=0; i<n && i<reach; i++)
		{
			reach = max(reach, i+1+nums[i]);
		}
		return reach>=n;

	}
};