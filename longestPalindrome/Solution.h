#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int idi = 0;
		int mxlen = 0;
		for (int i=0; i<s.size(); i++)
		{
			for (int j=i+1; j<s.size(); j++)
			{
				int slen = j-i+1;
				if (slen%2==0)
				{
					bool flag = true;
					int li = (j+i)/2;
					int ri = (j+i)/2 + 1;
					for (int k=0; k<slen/2; k++)
					{
						if (s[li-k]!=s[ri+k])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						if (slen>mxlen)
						{
							mxlen = slen;
							idi = i;
						}
					}
				}
				else
				{
					bool flag = true;
					int li = (j+i)/2 - 1;
					int ri = (j+i)/2 + 1;
					for (int k=0; k<slen/2; k++)
					{
						if (s[li-k]!=s[ri+k])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						if (slen>mxlen)
						{
							mxlen = slen;
							idi = i;
						}
					}
				}
			}
		}

		return s.substr(idi, mxlen);
	}
};

class Solution1
{
public:
	string longestPalindrome(string s) {
		int n = s.length();
		bool *table;
		table = new bool[n*(n+1)/2];

		int maxlen = 1;
		string str;
		for (int i=0; i<n; i++)
		{
			*(table+i*n-i*(i-1)/2) = true;
			str = s[i];
		}
		for (int i=0; i<n-1; i++)
		{
			if (s[i]==s[i+1])
			{
				*(table+i*n-i*(i-1)/2+1) = true;
				maxlen = 2;
				str = s.substr(i, maxlen);
			}
			else
			{
				*(table+i*n-i*(i-1)/2+1) = false;
			}
		}

		for (int i=n-3; i>=0; i--)
		{
			for (int j=i+2; j<n; j++)
			{
				if (s[i]==s[j])
				{
					*(table+i*n-i*(i-1)/2+j-i) = *(table+(i+1)*n-i*(i+1)/2+j-i-2);
					if ((j-i+1>maxlen) && (*(table+i*n-i*(i-1)/2+j-i)))
					{
						maxlen = j-i+1;
						str = s.substr(i, maxlen);
					}
				}
				else
				{
					*(table+i*n-i*(i-1)/2+j-i) = false;
				}
			}
		}
		return str;
	}

};

class Solution2
{
public:
	string longestPalindrome(string s) {
		string str;
		int len = s.length();
		if (len==0)
		{
			return "";
		}
		string maxstr = s.substr(0, 1);

		for (int i=0; i<len; i++)
		{
			str = palindrome(s, i, i);
			if (maxstr.length()<str.length())
			{
				maxstr = str;
			}
			str = palindrome(s, i, i+1);
			if (maxstr.length()<str.length())
			{
				maxstr = str;
			}
		}
		return maxstr;
	}

	string palindrome(string &s, int i, int j)
	{
		int len = s.length();
		while(i>=0 && j<len && s[i]==s[j])
		{
			i--;
			j++;
		}
		return s.substr(i+1, j-i-1);
	}
};