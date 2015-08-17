#include <string>
#include <vector>
using namespace std;
#define NULL 0

class Solution {
public:
	int numDistinct(string S, string T) {
		int n = S.length();
		int m = T.length();

		if (n <= m)
		{
			return T==S ? 1 : 0;
		}

		if (m==0)
		{
			return 1;
		}

		int cnt = 0;
		for (int i=0; i<n; i++)
		{
			if (S[i]==T[0])
			{
				cnt += numDistinct(S.substr(i+1), T.substr(1));
			}
		}

		return cnt;
	}
	
};

class Solution2
{
public:
	int numDistinct(string S, string T) {
		int n = S.length();
		int m = T.length();

		if (n<=m)
		{
			return S==T ? 1 : 0;
		}

		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

		for (int i=0; i<m+1; i++)
		{
			for (int j=0; j<n+1; j++)
			{
				if (i==0)
				{
					dp[i][j] = 1;
				}
				else if(j!=0)
				{
					dp[i][j] = dp[i][j-1];
					if (T[i-1]==S[j-1])
					{
						dp[i][j] += dp[i-1][j-1];
					}
				}
			}
		}

		return dp[m][n];
	}
};