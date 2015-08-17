#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> tb;
		for (int i=0; i<nums.size(); i++)
		{
			auto it = tb.find(nums[i]);
			if (it!=tb.end() && i-tb[nums[i]]<=k)
			{
				return true;
			}
			else
			{
				tb[nums[i]] = i;
			}
		}
		return false;
	}
};