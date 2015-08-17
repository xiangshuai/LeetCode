#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		for (int i=0; i<tokens.size(); i++)
		{
			if (!isOperator(tokens[i]))
			{
				stk.push(atoi(tokens[i].c_str()));
			}
			else
			{
				int b = stk.top();
				stk.pop();
				int a = stk.top();
				stk.pop();
				int c;
				if (tokens[i]=="+")
				{
					
					c = a+b;
				}
				else if (tokens[i]=="-")
				{
					c = a-b;
				}
				else if (tokens[i]=="*")
				{
					c = a*b;
				}
				else 
				{
					c = a/b;
				}
				stk.push(c);
			}
		}
		return stk.top();
	}
	
	bool isOperator(const string &op)
	{
		return op.size()==1 && string("+-*/").find(op) != string::npos;
	}

};