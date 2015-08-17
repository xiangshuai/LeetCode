#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		map<string, vector<string>> group;
		for (int i=0; i<strs.size(); i++)
		{
			auto key = strs[i];
			sort(key.begin(), key.end());
			group[key].push_back(strs[i]);
		}

		vector<string> result;
		for (auto it = group.begin(); it!=group.end(); it++)
		{
			if (it->second.size()>1)
			{
				result.insert(result.end(), it->second.begin(), it->second.end());
			}
		}
		return result;
	}
};