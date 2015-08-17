#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.size()==0)
		{
			return true;
		}
		
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

		int count = 0;
		while(!que.empty())
		{
			int cur = que.front();
			que.pop();
			count++;
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
		return count == numCourses;
	}
};