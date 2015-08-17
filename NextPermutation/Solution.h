#include <vector>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		nextPermutation(nums.begin(), nums.end());
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