#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int ret = 0;
		if (nums.size()<1)
		{
			return ret;
		}
		ret = nums[0];
		for (int i=1; i<nums.size(); i++)
		{
			if (nums[i]<ret)
			{
				ret = nums[i];
			}
		}
		return ret;
	}
};

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size()-1;

		while(left<=right)
		{
			int mid = (left+right)/2;
			if (nums[left]<=nums[mid] && nums[mid]<=nums[right])
			{
				return nums[left];
			}
			
			if (nums[left]<=nums[mid] && nums[mid]>nums[right])
			{
				left = mid+1;
			}
			else
			{
				right = mid;
			}
		}
	}
};