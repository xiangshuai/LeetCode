#include<string>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		int index = 0;
		for (int i=0; i<s.size(); i++)
		{
			index = max(index, findLongestPalindrome(s, i));
		}

		string str = s.substr(index, s.size()-index);
		reverse(str.begin(), str.end());
		return str+s;
	}

	int findLongestPalindrome(string s, int pivot) {

 		int i=0;
		while (pivot>=i && pivot+i<s.size() && s[pivot-i]==s[pivot+i])
		{
			i++;
		}

		int j=0;
		while(pivot>=j && pivot+j+1<s.size() && s[pivot-j]==s[pivot+1+j])
		{
			j++;
		}
		int cnt = max(i, j);
		if (pivot-cnt<0)
		{
			return pivot+max(i, j+1);
		}
		return 1;
	}
};

class Solution2 {
public:
	string shortestPalindrome(string s) {
		int index = 0;
		for (int i=s.size()-1; i>=0; i--)
		{
			if (findPalindrome(s, 0, i))
			{
				string str = s.substr(i+1, s.size()-i-1);
				reverse(str.begin(), str.end());
				return str+s;
			}
		}
		return s;
	}

	bool findPalindrome(string s, int left, int right)
	{
		while(left<right)
		{
			if (s[left]!=s[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};

