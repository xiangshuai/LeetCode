#include "Solution.h"

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	Solution sl;
	vector<vector<int> > result = sl.subsetsWithDup(nums);
}