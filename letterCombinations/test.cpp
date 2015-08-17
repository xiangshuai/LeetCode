#include "Solution.h"
#include <iostream>

int main()
{
	string digits = "23";
	Solution sl;
	vector<string> ret = sl.letterCombinations(digits);

	for (int i=0; i<ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
}