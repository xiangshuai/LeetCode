#include <iostream>
#include "Solution.h"

int main()
{
	string start = "red";
	string end = "tax";
	unordered_set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");
	Solution2 sl;
	vector<vector<string>> ret = sl.findLadders(start, end, dict);
	for (int i=0; i<ret.size(); i++)
	{
		for (int j=0; j<ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}