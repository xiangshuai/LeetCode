#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ret;

		vector<int> indgree(numCourses, 0);
		vector<vector<bool>> map(numCourses, vector<bool>(numCourses, 0));

		for (int i=0; i<prerequisites.size(); i++)
		{
			if (!map[prerequisites[i].first][prerequisites[i].second])
			{
				map[prerequisites[i].first][prerequisites[i].second] = true;
				indgree[prerequisites[i].first]++;
			}
		}

		queue<int> que;
		for (int i=0; i<numCourses; i++)
		{
			if (indgree[i]==0)
			{
				que.push(i);
			}
		}

		while(!que.empty())
		{
			int cur = que.front();
			que.pop();
			ret.push_back(cur);
			for (int i=0; i<numCourses; i++)
			{
				if (map[i][cur])
				{
					indgree[i]--;
					if (indgree[i]==0)
					{
						que.push(i);
					}
				}
			}
		}

		if (ret.size()<numCourses)
		{
			return vector<int>();
		}
		return ret;
	}
};