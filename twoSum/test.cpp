#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	vector<int> input;
	input.push_back(11);
	input.push_back(7);
	input.push_back(15);
	input.push_back(2);

	Solution slt;
	vector<int> res = slt.twoSum(input, 9);

	for (int i=1; i<res.size(); i++)
	{
		cout << res[i-1] << " " << res[i] << endl;
	}
}