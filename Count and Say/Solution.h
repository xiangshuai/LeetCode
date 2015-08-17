#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s("1");
		stringstream out;
		while(--n)
		{
			out.flush();
			for (int i=0; i<s.size();)
			{
				int j = i;
				while(s[j]==s[i] && j<s.size())
				{
					j++;
				}
				out << j-i << s[i];
				i = j;
			}
			s = out.str();
		}
		return s;
	}
};