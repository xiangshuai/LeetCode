#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int pos[256] = {-1};
		
		int total = 0;
		int id = -1;
		for (int i=0; i<s.size(); i++)
		{
			if (pos[s[i]]>id)
			{
				id = pos[s[i]];
			}
			if (i-id>total)
			{
				total = i-id;
			}
			pos[s[i]] = i;
		}
		return total;
	}
};