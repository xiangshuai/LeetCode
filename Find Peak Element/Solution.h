#include <vector>
using namespace std;

// O(n)
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		for (int i=1; i<n; i++)
		{
			if (i==1 && nums[i]<nums[i-1])
			{
				return 0;
			}

			if (i==n-1 && nums[i]>nums[i-1])
			{
				return n-1;
			}

			if (nums[i]>nums[i-1] && nums[i]>nums[i+1])
			{
				return i;
			}
		}
		return 0;
	}
};

// O(Logn)
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return binarySearch(nums, 0, nums.size()-1);
	}

	int binarySearch(vector<int>& nums, int low, int high)
	{
		int mid = low + (high-low)/2;

		if (low==high)
		{
			return mid;
		}

		if (mid==0)
		{
			return nums[low]>nums[high] ? low : high;
		}

		if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
		{
			return mid;
		}

		if (nums[mid]<nums[mid-1])
		{
			return binarySearch(nums, low, mid-1);
		}
		else
		{
			return binarySearch(nums, mid+1, high);
		}
	}
};