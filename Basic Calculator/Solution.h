#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> stk_val;
		stack<char> stk_op;
		for (int i=0; i<s.size(); i++)
		{
			if (i<s.size() && isdigit(s[i]))
			{
				int res = 0;
				while (i<s.size() && isdigit(s[i]))
				{
					res *= 10;
					res += s[i++]-'0';
				}
				stk_val.push(res);
			}

			if (i==s.size() || s[i]=='+' || s[i]=='-' || s[i]==')')
			{
				while(!stk_op.empty() && stk_op.top()!='(')
				{
					int tmp = stk_val.top();
					stk_val.pop();
					if (stk_op.top()=='+')
					{
						stk_val.top() += tmp;
					}
					else if(stk_op.top()=='-')
					{
						stk_val.top() -= tmp;
					}
					stk_op.pop();
				}
				if (i==s.size())
				{
					break;
				}
				else if (s[i]==')')
				{
					stk_op.pop();
				}
				else
				{
					stk_op.push(s[i]);
				}
			}
			if (s[i]=='(')
			{
				stk_op.push(s[i]);
			}
		}
		return stk_val.top();
	}
};