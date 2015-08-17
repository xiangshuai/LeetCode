#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.length();
		int m = word2.length();

		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

		for (int i=0; i<n+1; i++)
		{
			for (int j=0; j<m+1; j++)
			{
				if (i==0)
				{
					dp[i][j] = j;
				}
				else if (j==0)
				{
					dp[i][j] = i;
				}
				else
				{
					if (word1[i-1]==word2[j-1])
					{
						dp[i][j] = dp[i-1][j-1];
					}
					else
					{
						int inst = dp[i][j-1]+1;
						int del = dp[i-1][j]+1;
						int sub = dp[i-1][j-1]+1;
						dp[i][j] = min(inst, min(del, sub));
					}
				}
			}
		}
		return dp[n][m];
	}
};