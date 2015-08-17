#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		vector<string> strs;
		strs.resize(nRows, "");

		int id = 0;
		int dir = 1;
		for(int i=0; i<s.size(); i++)
		{
			if (id<=0)
			{
				id = 0;
				dir = 1;
			}
			else if(id>=(nRows-1))
			{
				id = nRows - 1;
				dir = -1;
			}
			strs[id] += s[i];
			id+=dir;
		}
		string cstr="";
		for (int i=0; i<strs.size(); i++)
		{
			cstr+=strs[i];
		}
		return cstr;
	}
};