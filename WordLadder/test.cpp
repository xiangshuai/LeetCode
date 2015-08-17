#include <iostream>
#include "Solution.h"

int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	Solution2 sl;
	cout << sl.ladderLength(start, end, dict) << endl;
}