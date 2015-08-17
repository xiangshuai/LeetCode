#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> levels1, levels2;
		split(version1, levels1);
		split(version2, levels2);

		while (levels1.size()<levels2.size())
		{
			levels1.push_back(0);
		}

		while (levels2.size()<levels1.size())
		{
			levels2.push_back(0);
		}


		for (int i=0; i<levels1.size() && i<levels2.size(); i++)
		{
			if (levels1[i]>levels2[i])
			{
				return 1;
			}
			if (levels1[i]<levels2[i])
			{
				return -1;
			}
		}
		return 0;
	}

	bool split(string version, vector<int> &levels)
	{
		version.push_back('.');
		int lv_start = 0;
		for (int i=0; i<version.size(); i++)
		{
			if (version[i]=='.')
			{
				string lv = version.substr(lv_start, i-lv_start);
				levels.push_back(strToInt(lv));
				lv_start = i+1;
			}
		}
		version.pop_back();
		return true;
	}

	int strToInt(string str)
	{
		int ret = 0;
		for (int i=0; i<str.size(); i++)
		{
			ret *= 10;
			ret += str[i]-'0';
		}
		return ret;
	}
};