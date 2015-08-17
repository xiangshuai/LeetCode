#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		if (n<1)
		{
			return 0;
		}
		vector<int> dp(n+1, 0);
		dp[0] = 1;
		for (int i=1; i<n+1; i++)
		{
			if (i==1)
			{
				if (s[i-1]=='0')
				{
					return 0;
				}
				else
				{
					dp[i] = 1;
				}
			}
			else
			{
				if (s[i-1]=='0')
				{
					if (s[i-2]=='1' || s[i-2]=='2')
					{
						dp[i] = dp[i-2];
					}
					else
					{
						return 0;
					}
				}
				else
				{
					if (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))
					{
						dp[i] = dp[i-1]+d[i-2];
					}
					else
					{
						dp[i] = dp[i-1];
					}
				}
			}
		}
		return dp[n];
	}
};