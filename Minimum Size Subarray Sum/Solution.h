#include <vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = INT_MAX;
		int total = 0;
		for (int i=0; i<nums.size(); i++)
		{
			total = 0;
			int j = i;
			for (; j<nums.size(); j++)
			{
				total += nums[j];
				if (total>=s)
				{
					len = min(len, j-i+1);
					break;
				}
			}
			if(j==nums.size())
			{
				break;
			}
		}
		if (len==INT_MAX)
		{
			len = 0;
		}
		return len;
	}
};

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if(n<1)
		{
			return 0;
		}
		int min_len = n+1;

		int start = 0;
		int sub_total = nums[0];
		if(sub_total >= s)
		{
			return 1;
		}
		for(int i=1; i<nums.size(); i++)
		{
			sub_total += nums[i];
			while(sub_total>=s && start<=i)
			{
				sub_total -= nums[start];
				min_len = min(min_len, i-start+1);
				start++;
			}
		}
		if(min_len==n+1)
		{
			return 0;
		}
		return min_len;
	}
}