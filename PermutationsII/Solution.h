#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		do 
		{
			result.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return result;
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

class Solution2 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		map<int, int> cttb;
		for (int i=0; i<nums.size(); i++)
		{
			cttb[nums[i]]++;
		}
		vector<int> p;
		permute(nums, cttb, p, result);
		return result;
	}

	void permute(vector<int> &nums, map<int, int> &cttb, vector<int> &p, vector<vector<int>> &result)
	{
		int n = nums.size();
		if (p.size()==n)
		{
			result.push_back(p);
			return ;
		}

		for (map<int, int>::iterator it = cttb.begin(); it!=cttb.end(); it++)
		{
			int count = 0;
			for (int j=0; j<p.size(); j++)
			{
				if (p[j]==it->first)
				{
					count++;
				}
			}
			if (count<it->second)
			{
				p.push_back(it->first);
				permute(nums, cttb, p, result);
				p.pop_back();
			}
		}
	}
}