#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size()!=t.size())
		{
			return false;
		}
		map<char, char> tb1, tb2;
		for (int i=0; i<s.length(); i++)
		{
			if(tb1.find(s[i])!=tb1.end())
			{
				if (tb1[s[i]]!=t[i])
				{
					return false;
				}
			}

			if (tb2.find(t[i])!=tb2.end())
			{
				if (tb2[t[i]]!=s[i])
				{
					return false;
				}
			}

			tb1[s[i]] = t[i];
			tb2[t[i]] = s[i];
		}
		return true;
	}
};