#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int begin = 0;
		int end = s.size();
		while(begin<end && s[begin]==' ') begin++;
		while(begin<end && s[end-1]==' ') end--;
		s = s.substr(begin, end-begin);
		if (s.size()<2)
		{
			return ;
		}
		reverse(s.begin(), s.end());
		s.push_back(' ');
		int word_start = 0;
		int i=0;
		while(i<s.size())
		{
			if (s[i]==' ')
			{
				if (word_start==i)
				{
					s.erase(s.begin()+i);
					continue;
				}
				reverse(s.begin()+word_start, s.begin()+i);
				word_start = i+1;
			}
			i++;
		}
		s.pop_back();
	}
};