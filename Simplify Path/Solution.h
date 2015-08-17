#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dirs;
		for (auto it = path.begin(); it!=path.end();)
		{
			it++;
			auto j = find(it, path.end(), '/');
			string dir = string(it, j);
			if (!dir.empty() && dir!=".")
			{
				if (dir=="..")
				{
					if (!dirs.empty())
					{
						dirs.pop_back();
					}
				}
				else
				{
					dirs.push_back(dir);
				}
			}
			it = j;
		}

		stringstream out;
		if (dirs.empty())
		{
			out << "/";
		}
		else
		{
			for (int i=0; i<dirs.size(); i++)
			{
				out << "/" << dirs[i];
			}
		}
		return out.str();
	}
};