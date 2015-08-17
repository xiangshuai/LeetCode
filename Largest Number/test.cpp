#include "Solution.h"

int main()
{
	vector<int> nums;
	nums.push_back(999999998);
	nums.push_back(999999997);
	nums.push_back(999999999);
	Solution sl;
	string s = sl.largestNumber(nums);
	return 0;
}