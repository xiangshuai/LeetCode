#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		return isInterleave(s1, 0, s2, 0, s3, 0);
	}

	bool isInterleave(string &s1, int i1, string &s2, int i2, string &s3, int i)
	{
		if (i1==s1.length() && i2==s2.length() && i==s3.length())
		{
			return true;
		}

		bool m1 = false, m2 = false;
		if (i1<s1.length() && s1[i1]==s3[i])
		{
			m1 =  isInterleave(s1, i1+1, s2, i2, s3, i+1);
		}
		if (i2<s2.length() && s2[i2]==s3[i])
		{
			m2 =  isInterleave(s1, i1, s2, i2+1, s3, i+1);
		}
		return m1 || m2;
	}
};


class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int n1 = s1.length();
		int n2 = s2.length();
		int n3 = s3.length();
		if (n1+n2!=n3)
		{
			return false;
		}
		vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
		dp[0][0] = true;
		for (int i=1; i<n1+1; i++)
		{
			dp[i][0] = (s1[i-1]==s3[i-1]);
		}
		for (int j=1; j<n2+1; j++)
		{
			dp[0][j] = (s2[j-1]==s3[j-1]);
		}

		for (int i=1; i<n1+1; i++)
		{
			for (int j=1; j<n2+1; j++)
			{
				if (s1[i-1]==s3[i+j-1] && dp[i-1][j])
				{
					dp[i][j] = true;
				}
				if (s2[j-1]==s3[i+j-1] && dp[i][j-1])
				{
					dp[i][j] = true;
				}
			}
		}
		return dp[n1][n2];
	}
}