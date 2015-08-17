#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution sl;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	cout << sl.jump(nums) << endl;
}