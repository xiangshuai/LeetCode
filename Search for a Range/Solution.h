#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret(2, -1);
		const int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
		const int r = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
		
		if (nums[l]!=target)
		{
			return ret;
		}
		else
		{
			ret[0] = l;
			ret[1] = r;
			return ret;
		}
	}
};


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> ret(2, -1);
		if (n<1)
		{
			return ret;
		}
		int left = 0; 
		int right = n-1;
		
		while(left < right)
		{
			int mid = (left+right)/2;

		}
	}
};