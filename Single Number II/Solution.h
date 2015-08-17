#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> counts;

		for (int i=0; i<nums.size(); i++)
		{
			counts[nums[i]]++;
		}

		for (auto it=counts.begin(); it!=counts.end(); it++)
		{
			if (it->second<3)
			{
				return it->first;
			}
		}
	}
};