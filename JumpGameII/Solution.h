#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0;
		if (nums.size()==0)
		{
			return step;
		}
		queue<int> qnums;
		qnums.push(0);
		while(!qnums.empty())
		{
			step++;
			int curi = qnums.front();
			qnums.pop();
			for (int i=0; i<nums[curi]; i++)
			{
				if (curi+i+1>=nums.size()-1)
				{
					return step;
				}
				qnums.push(curi+i+1);
			}
		}
		return INT_MAX;
	}
};

class Solution1 {
public:
	int jump(vector<int>& nums) {
		int step = 0;
		int last = 0;
		int cur = 0;

		int n = nums.size();
		for (int i=0; i<n; i++)
		{
			if (cur>=n-1)
			{
				return step++;
			}
			if (i>cur)
			{
				return -1;
			}
			if (i>last)
			{
				last = cur;
				step++;
			}
			cur = max(cur, i+nums[i]);
		}
		return INT_MAX;
	}
};