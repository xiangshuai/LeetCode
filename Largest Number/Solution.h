#include <string>
#include <vector>
#include <strstream>
#include <algorithm>
using namespace std;

bool myCompare(int x, int y)
{
	string sx = to_string(static_cast<long long>(x));
	string sy = to_string(static_cast<long long>(y));
	long a = stol(string(sx+sy));
	long b = stol(string(sy+sx));
	return a > b;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), myCompare);
		
		if (nums.size()<1 || nums[0]==0)
		{
			return "0";
		}

		string ret;
		for (int i=0; i<nums.size(); i++)
		{
			ret += to_string(static_cast<long long>(nums[i]));
		}
		return ret;
	}
};