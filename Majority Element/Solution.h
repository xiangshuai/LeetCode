#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> tb;
		for (int i=0; i<nums.size(); i++)
		{
			if(tb.find(nums[i])==tb.end())
			{
				tb[nums[i]] = 1;
			}
			else
			{
				tb[nums[i]]++;
			}
		}
		pair<int, int> ret(tb.begin()->first, tb.begin()->second);
		for (auto it=tb.begin(); it!=tb.end(); it++)
		{
			if (it->second > ret.second)
			{
				ret = *it;
			}
		}
		return ret.first;
	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		vector<int> buff;
		for (int i=0; i<nums.size(); i++)
		{
			if (buff.size()<1)
			{
				buff.push_back(nums[i]);
			}
			else if (buff.back()!=nums[i])
			{
				buff.pop_back();
			}
			else
			{
				buff.push_back(nums[i]);
			}
		}
		return buff[0];
	}
};