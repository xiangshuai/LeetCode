#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> ret1;
		vector<int> ret2;
		vector<int> tmpnum = numbers;
		sort(tmpnum.begin(), tmpnum.end(), compare);
		bool flag = false;
		for (int i=0; i<tmpnum.size(); i++)
		{
			int j = i+1;
			int k = tmpnum.size();
			while(j <= k)
			{
				int m = (j+k)/2;
				if (tmpnum[i]+tmpnum[m]==target)
				{
					ret1.push_back(tmpnum[i]);
					ret1.push_back(tmpnum[m]);
					flag = true;
					break;
				}
				else if(tmpnum[i]+tmpnum[m] < target)
				{
					j = m+1;
				}
				else if(tmpnum[i]+tmpnum[m] > target)
				{
					k = m-1;
				}
			}
			if (flag)
			{
				break;
			}
		}
		if (ret1.size()==2)
		{
			for (int i=0; i<numbers.size(); i++)
			{
				if (ret1[0]==numbers[i] || ret1[1] == numbers[i])
				{
					ret2.push_back(i+1);
				}
			}
		}
		return ret2;
	}
private:
	static bool compare(int a, int b)
	{
		return a<b;
	}
};

#endif
