#include "Solution.h"
#include <iostream>

int main()
{
	vector<int> num;
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-4);

	Solution sl;
	int ret = sl.threeSumClosest(num,1);

	cout << ret << endl;
}
