#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string ip;
		dfs(s, 0, 4, ip, result);
		return result;
	}

	void dfs(string &s, int start, int step, string &ip,vector<string> &result)
	{
		int n = s.size();
		if (start==n && step==0)
		{
			ip.resize(ip.size()-1);
			result.push_back(ip);
			return ;
		}

		if (n-1-start > step*3)
		{
			return ;
		}

		if (n-1-start < step)
		{
			return ;
		}

		int num = 0;
		for (int i=start; i<start+3 && i<n; i++)
		{
			num = num*10 + s[i]-'0';
			if (num<=255)
			{
				ip += s[i];    
				dfs(s, i+1, step-1, ip + '.', result);
			}
			if (num==0)
			{
				break;
			}
		}
	}
};