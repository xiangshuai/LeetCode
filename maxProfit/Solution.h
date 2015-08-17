#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int mxpt = 0;
		if (prices.size()<2)
		{
			return 0;
		}
		int low = prices[0];

		for (int i=1; i<prices.size(); i++)
		{
			if (prices[i]<low)
			{
				low = prices[i];
			}
			else
			{
				int pt = prices[i]-low;
				if (pt>mxpt)
				{
					mxpt = pt;
				}
			}
		}
		return mxpt;
	}
};

class Solution2 {
public:
	int maxProfit(vector<int> &prices) {
		int pts = 0;
		if (prices.size()<2)
		{
			return 0;
		}

		for (int i=1; i<prices.size(); i++)
		{
			int pt = prices[i]-prices[i-1];
			if (pt>0)
			{
				pts+ = pt;
			}
		}
		return pts;
	}
};

class Solution3
{
public:
	int maxProfit(vector<int> &prices) {
		int maxpt = 0;
		if (prices.size()<3)
		{
			return maxpt;
		}
		for (int i=1; i<prices.size()-2; i++)
		{
			int left = subMaxProfit(prices, 0, i);
			int right = subMaxProfit(prices, i, prices.size()-1);
			if (left+right>maxpt)
			{
				maxpt = left+right;
			}
		}
		return maxpt;
	}

	int subMaxProfit(vector<int> &prices, int k1, int k2)
	{
		int smxpt = 0;
		if (k2-k1<2)
		{
			return smxpt;
		}
		int low = prices[k1];

		for (int i=k1+1; i<=k2; i++)
		{
			if (prices[i]<low)
			{
				low = prices[i];
			}
			else
			{
				int pt = prices[i]-low;
				if (pt>smxpt)
				{
					smxpt = pt;
				}
			}
		}
		return smxpt;
	}
};

class Solution4
{
public:
	int maxProfit(vector<int> &prices)
	{
		int mxret = 0;
		if (prices.size()<2)
		{
			return mxret;
		}
		int n = prices.size();
		int leftmin = prices[0];
		vector<int> head(n, 0); // 0~i
		for (int i=1; i<n; i++)
		{
			leftmin = min(leftmin, prices[i]);
			head[i] = max(head[i-1], prices[i]-leftmin);
		}

		int rightmax = prices[n-1];
		vector<int> tail(n, 0);	// i~n-1
		for (int i=n-2; i>=0; i--)
		{
			tail[i] = max(tail[i+1], rightmax-prices[i]);
			rightmax = max(rightmax, prices[i]);
		}

		for (int i=0; i<n; i++)
		{
			mxret = max(maxret, head[i]+tail[i]);
		}
		return mxret;
	}
};