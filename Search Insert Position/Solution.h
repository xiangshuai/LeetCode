#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		for (int i=0; i<nums.size(); i++)
		{
			if (i==0 && target<nums[i])
			{
				return i;
			}

			if (nums[i]==target)
			{
				return i;
			}

			if (i>0 && nums[i-1]<target && nums[i]>target)
			{
				return i;
			}
		}
		return nums.size();
	}
};

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		if (n<1)
		{
			return 0;
		}
		if (target<nums[0])
		{
			return 0;
		}
		if (target>nums[n-1])
		{
			return n;
		}
		int left = 0;
		int right = n-1;
		while(left<=right)
		{
			int mid = (left+right)/2;
			if (target==nums[mid])
			{
				return mid;
			}
			
			if (target>nums[mid])
			{
				left = mid+1;
			}
			if (target<nums[mid])
			{
				right = mid-1;
			}
		}
		return left;
	}
};