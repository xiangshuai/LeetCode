#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		int answer = 0;
		for (int i=0; i<height.size(); i++)
		{
			int minHeight = height[i];

			for (int j=0; j<height.size(); j++)
			{
				if (height[i]<minHeight)
				{
					minHeight = height[i];
				}
				int area = minHeight * (j-i+1);
				answer = max(answer, area);
			}
		}
		return answer;
	}
};

class Solution2
{
public:
	int largestRectangleArea(vector<int>& height) {
		int answer = 0;
		for (int i=0; i<height.size(); i++)
		{
			int j=i+1;
			while(j<height.size()  && height[j]>=height[i])
			{
				j++;
			}
			answer = max(answer, height[i]*(j-i));
			
			j=i-1;
			while(j>=0 && height[j]>=height[i])
			{
				j--;
			}
			answer = max(answer, height[i]*(i-j));
		}
		return answer;
	}
};

class Solution3
{
public:
	int largestRectangleArea(vector<int>& height) {
		int answer = 0;
		stack<int> hts;
		stack<int> ids;
		height.push_back(0);
		for (int i=0; i<height.size(); i++)
		{
			if (hts.empty() || height[i]>=hts.top())
			{
				hts.push(height[i]);
				ids.push(i);
			}
			else
			{
				int idx = 0;
				while(!hts.empty() && height[i]<hts.top())
				{
					int minHeight = hts.top();
					hts.pop();
					idx = ids.top();
					ids.pop();
					answer = max(answer, minHeight*(i-idx));
				}
				hts.push(height[i]);
				ids.push(idx);
			}
		}
		return answer;
	}
};


class Solution4
{
public:
	int largestRectangleArea(vector<int>& height) {
		int answer = 0;
		stack<int> ids;
		height.push_back(0);
		for (int i=0; i<height.size(); i++)
		{
			if (ids.empty() || height[i]>=height[ids.top()])
			{
				ids.push(i);
			}
			else
			{
				int idx = ids.top();
				ids.pop();
				answer = max(answer, height[idx]*(ids.empty() ? i : (i-ids.top()-1)));
				i--;
			}
		}
		return answer;
	}

};