#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ret;
		do 
		{
			ret.push_back(nums);
		} while (nextPermutation(nums.begin(), nums.end()));
		return ret;
	}

	bool nextPermutation(vector<int>::iterator begin, vector<int>::iterator end)
	{
		if (begin==end)
		{
			return false;
		}

		if (begin==end-1)
		{
			return false;
		}

		vector<int>::iterator it = end-1;

		for (;;)
		{
			vector<int>::iterator iit = it;
			it--;
			if (*it < *iit)
			{
				vector<int>::iterator jt = end;
				while(*it >= *--jt);
				swap(*it, *jt);
				reverse(iit, end);
				return true;
			}
			if (it==begin)
			{
				reverse(begin, end);
				return false;
			}
		}
	}
};