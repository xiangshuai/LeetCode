#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int rcnt=0, wcnt=0, bcnt=0;
		for (int i=0; i<nums.size(); i++)
		{
			switch(nums[i])
			{
			case 0: rcnt++; break;
			case 1: wcnt++; break;
			case 2: bcnt++; break;
			default: break;
			}
		}

		for (int i=0; i<rcnt; i++)
		{
			nums[i] = 0;
		}

		for (int i=rcnt; i<rcnt+wcnt; i++)
		{
			nums[i] = 1;
		}

		for (int i=rcnt+wcnt; i<rcnt+wcnt+bcnt; i++)
		{
			nums[i] = 2;
		}
	}
};

class Solution {
public:
	void sortColors(vector<int>& nums) {
		quickSort(nums, 0, nums.size()-1);
	}

	void quickSort(vector<int>& nums, int left, int right)
	{
		if (left<right)
		{
			int m = partition(nums, left, right);
			quickSort(nums, left, m-1);
			quickSort(nums, m+1, right);
		}
	}

	int partition(vector<int>& nums, int left, int right)
	{
		int pivot = nums[left];
		while(left<right)
		{
			while(left<right && nums[right]>pivot) right--;
			nums[left] = nums[right];
			while(left<right && nums[left]<=pivot) left++;
			nums[right] = nums[left];
		}
		nums[left] = pivot;
		return left;
	}
};