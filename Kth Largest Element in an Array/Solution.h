#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		quickSort(nums, 0, nums.size()-1);
		for (int i=nums.size()-1; i>=0; i--)
		{
			if (i<nums.size()-1 && nums[i]==nums[i+1])
			{
				k++;
			}
			if (--k==0)
			{
				return nums[i];
			}
		}
		return 0;
	}

	int partition(vector<int>& nums, int left, int right)
	{
		int guard = nums[left];
		while(left<right)
		{
			while(left<right && nums[right]>=guard)
			{
				right--;
			}
			nums[left] = nums[right];
			while(left<right && nums[left]<=guard)
			{
				left++;
			}
			nums[right] = nums[left];
		}
		nums[left] = guard;
		return left;
	}

	void quickSort(vector<int>& nums, int left, int right)
	{
		if (left<right)
		{
			int p = partition(nums, left, right);
			quickSort(nums, left, p-1);
			quickSort(nums, p+1, right);
		}
	}
};