#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		
		if (strs.size()<1)
		{
			return "";
		}

		int minj = INT_MAX;
		for (int i=1; i<strs.size(); i++)
		{
			int j = 0;
			while(j<strs[0].length() && j<strs[i].length())
			{
				if (strs[0][j]==strs[i][j])
				{
					j++;
				}
				else
				{
					break;
				}
			}
			if (j < minj)
			{
				minj = j;
			}
		}
		return strs[0].substr(0, minj);

	}
};