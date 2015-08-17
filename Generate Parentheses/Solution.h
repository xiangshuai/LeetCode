#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		helper(ret, n, n, "");
		return ret;
	}

	void helper(vector<string> &ret, int l, int r, string str)
	{
		if (l>r)
		{
			return;
		}

		if (l==0 && r==0)
		{
			ret.push_back(str);
		}

		if (l>0)
		{
			helper(ret, l-1, r, str+'(');
		}
		if (r>0)
		{
			helper(ret, l, r-1, str+')');
		}
	}

};