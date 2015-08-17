#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		char *next;
		strtod(s.c_str(), &next);
		if (next==s)
		{
			return false;
		}

		while(*next!='\0')
		{
			if (!isspace(*next))
			{
				return false;
			}
			next++;
		}
		return true;
	}
};