#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		int last = -1;
		int max_len = 0;
		for (int i=0; i<s.size(); i++)
		{
			switch(s[i])
			{
			case '(':
				stk.push(i);
				break;
			case ')':
				if (stk.empty())
				{
					last = i;
				}
				else
				{
					stk.pop();
					if (stk.empty())
					{
						max_len = max(max_len, i-last);
					}
					else
					{
						max_len = max(max_len, i-stk.top());
					}
				}
				break;
			}
		}
		return max_len;
	}
};

// dp solution
class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> f(s.size(), 0);
		int ret = 0;
		for (int i=s.size()-2; i>=0; i--)
		{
			// ((..))
			int match = i+f[i+1]+1;
			if (s[i]=='(' && s[match]==')')
			{
				f[i] = f[i+1]+2;
				// ((..))()
				if (match+1<s.size())
				{
					f[i] += f[match+1];
				}
			}
			ret = max(ret, f[i]);
		}
		return ret;
	}
}

// scan
class Solution
{
public:
	int longestValidParentheses(string s) {
		int answer = 0, start = -1;
		int depth = 0;
		for (int i=0; i<s.size(); i++)
		{
			switch(s[i])
			{
			case '(':
				depth++;
				break;
			case ')':
				depth--;
				if (depth<0)
				{
					start = i;
					depth = 0;
				}
				else if (depth==0)
				{
					answer = max(answer, i-start);
				}
			}
		}

		depth = 0;
		start = s.size();
		for (int i=s.size()-1; i>=0; i--)
		{
			switch(s[i])
			{
			case ')':
				depth++;
				break;
			case '(':
				depth--;
				if (depth<0)
				{
					start = i;
					depth = 0;
				}
				else if(depth==0)
				{
					answer = max(answer, start-i);
				}
			}
		}
		return answer;
	}
};