#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
		auto last = find_if_not(first, s.rend(), ::isalpha);
		return distance(first, last);
	}
};

class Solution2 {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		int n = s.size();
		for (int i=n-1; i>=0; i--)
		{
			if (s[i]==' ')
			{
				s.pop_back();
			}
			else
			{
				break;
			}
		}
		for (int i=0; i<s.size(); i++)
		{
			if (s[i]!=' ')
			{
				len++;
			}
			else
			{
				len=0;
			}
		}
		return len;
	}
};


class Solution3 {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		auto it = s.begin();
		while(*it)
		{
			if (*it++!=' ')
			{
				len++;
			}
			else if (*it && *it!=' ')
			{
				len=0;
			}
		}
		return len;
	}
};