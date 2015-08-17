#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> buff;
		for (int i=0; i<s.size(); i++)
		{
			if (!buff.empty())
			{
				switch(s[i])
				{
				case ')':
					if (buff.top()=='(')
					{
						buff.pop();
					}
					else
					{
						return false;
					}
					break;
				case ']':
					if (buff.top()=='[')
					{
						buff.pop();
					}
					else
					{
						return false;
					}
					break;
				case '}':
					if (buff.top()=='{')
					{
						buff.pop();
					}
					else
					{
						return false;
					}
					break;
				default:
					buff.push(s[i]);
				}
			}
			else
			{
				buff.push(s[i]);
			}
		}
		if (buff.empty())
		{
			return true;
		}
		return false;
	}
};