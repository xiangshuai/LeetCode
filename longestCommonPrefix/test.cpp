#include <iostream>
#include "Solution.h"

int main()
{
	string s1 = "abcdefg";
	string s2 = "abc";
	string s3 = "abx";
	vector<string> strs;
	strs.push_back(s1);
	strs.push_back(s2);
	strs.push_back(s3);
	Solution sl;
	cout << sl.longestCommonPrefix(strs) << endl;
}