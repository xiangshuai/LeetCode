#include "Solution.h"
#include <iostream>

int main()
{
	vector<int> num;
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);

	Solution1 sl;
	vector<vector<int>> tripples = sl.threeSum(num);

	for (int i=0; i<tripples.size(); i++)
	{
		cout << i+1 << ": " << tripples[i][0] << " ";
		cout << tripples[i][1] << " ";
		cout << tripples[i][2] << endl;
	}
}
