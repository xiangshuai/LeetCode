#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>>  ret;
		sort(num.begin(), num.end());
		if (num.size()<4)
		{
			return ret;
		}
		for (int i=0; i<num.size()-3; i++)
		{
			if (i>0 && num[i]==num[i-1])
			{
				continue;
			}

			for (int j=i+1; j<num.size()-2; j++)
			{
				if (j>i+1 && num[j]==num[j-1])
				{
					continue;
				}
				int front = j+1;
				int end = num.size()-1;
				while(front<end)
				{
					if (front>j+1 && num[front]==num[front-1])
					{
						front++;
						continue;
					}
					else if (end<num.size()-1 && num[end]==num[end+1])
					{
						end--;
						continue;
					}
					int sum = num[i]+num[j]+num[front]+num[end];
					if (sum==target)
					{
						vector<int> item;
						item.push_back(num[i]);
						item.push_back(num[j]);
						item.push_back(num[front]);
						item.push_back(num[end]);
						ret.push_back(item);
						front++;
						end--;
					}
					else if (sum>target)
					{
						end--;
					}
					else
					{
						front++;
					}
				}
			}
		}
		return ret;
	}
};