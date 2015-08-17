#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		return isMatch(s.c_str(), p.c_str());
	}

	bool isMatch(const char* s, const char* p)
	{
		if (*p=='*')
		{
			while(*p=='*')
			{
				p++;
			}
			if (*p=='\0')
			{
				return true;
			}

			while (*s!='\0' && !isMatch(s, p))
			{
				s++;
			}
			return *s!='\0';
		}

		else if (*p=='\0' || *s=='\0')
		{
			return *s==*p;
		}

		else if (*s==*p || *p=='?')
		{
			return isMatch(s+1, p+1);
		}
		else
		{
			return false;
		}
	}
};

class Solution2 {
public:
	bool isMatch(string s, string p) {
		return isMatch(s.c_str(), p.c_str());
	}

	bool isMatch(const char* s, const char* p)
	{
		bool pst = false;
		const char *str, *ptr;
		const char *rs, *rp;
		for (str=s, ptr=p; *str!='\0'; str++, ptr++)
		{
			switch(*ptr)
			{
			case '?':
				break;
			case '*':
				pst = true;
				while(*ptr=='*') ptr++;
				if (*ptr=='\0')
				{
					return true;
				}
				rs = str;
				rp = ptr;
				str = str--;
				ptr = ptr--;
				break;
			default:
				if(*str!=*ptr)
				{
					if (!pst)
					{
						return false;
					}
					rs++;
					str = rs-1;
					ptr = rp-1;
				}
			}
		}
		while(*ptr=='*') 
		{
			ptr++;
		}

		return *ptr=='\0';

	}
};

class Solution
{
public:
	bool isMatch(string s, string p) {

		bool pstar = false;
		int ri = rj = 0;
		int i=0, j=0;
		for (; i<s.size(); i++,j++)
		{
			switch(p[j])
			{
			case '?':
				break;
			case '*':
				pstar = true;
				while(p[j]=='*') j++;
				if (j==p.size())
				{
					return true;
				}
				ri = i;
				rj = j;
				i = ri-1;
				j = rj-1;
				break;
			default:
				if (s[i]!=p[j])
				{
					if (pstar)
					{
						ri++;
						i = ri-1;
						j = rj-1;
					}
					else
					{
						return false;
					}
				}
			}
		}
		while(p[j]=='*') j++;

		return p[j]=='\0';
	}
};