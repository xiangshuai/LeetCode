#include <string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		if (s.length()<1)
		{
			return 0;
		}
		int result = 0;
		int prev = getRoman(s[0]);
		int curv;
		int result = prev;
		for (int i=1; i<s.length(); i++)
		{
			curv = getRoman(s[i]);
			if (prev==curv)
			{
				result+=curv;
			}
			else if(prev<curv)
			{
				result+=curv-prev;
			}
		}
	}

	int getRoman(char c)
	{
		switch(c)
		{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
		}
	}
};