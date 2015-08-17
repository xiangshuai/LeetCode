#include "Solution.h"
#include <iostream>

int main()
{
	Solution sl;
	vector<string> ret = sl.generateParenthesis(3);

	for (int i=0; i<ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
}