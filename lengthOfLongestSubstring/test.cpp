#include "Solution.h"
#include <iostream>
#include <map>

int main()
{
	string str = "bbabcbbdacweb";
	Solution sl;
	int len = sl.lengthOfLongestSubstring(str);
	cout << len << endl;
}