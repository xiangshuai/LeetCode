#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height) {
		int mArea = 0;
		for (int i=0; i<height.size()-1; i++)
		{
			int curArea;
			for (int j=i+1; j<height.size(); j++)
			{
				curArea = min(height[i], height[j]) * (j-i);
			}
			if (curArea>mArea)
			{
				mArea = curArea;
			}
		}
		return mArea;
	}
};

class Solution1
{
	int maxArea(vector<int> &height) {
		int mArea = 0;
		
		int left = 0, right = height.size()-1;
		while(left < right)
		{
			int cArea = min(height[left], height[right])*(right-left);
			if (cArea>mArea)
			{
				mArea = cArea;
			}
			if (height[left]<height[right])
			{
				int k=left;
				while(height[left]<=height[k])
				{
					left++;
				}
			}
			else
			{
				int k=right;
				while(height[right]<=height[k])
				{
					right--;
				}
			}
		}
		return mArea;
	}
};