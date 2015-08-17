#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> tripples;
		for (int i=0; i<num.size()-2; i++)
		{
			for (int j=i+1; j<num.size()-1; j++)
			{
				for (int k=j+1; k<num.size(); k++)
				{
					if (num[i]+num[j]+num[k]==0)
					{
						vector<int> trip;
						trip.push_back(num[i]);
						trip.push_back(num[j]);
						trip.push_back(num[k]);
						sort(trip.begin(), trip.end());
						tripples.push_back(trip);
					}
				}
			}
		}
		return tripples;
	}
private:
	static bool sortASC(int a, int b)
	{
		return a<b;
	}
};

class Solution1 {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> tripples;
		if (num.size()<3)
		{
			return tripples;
		}
		sort(num.begin(), num.end());
		for (int i=0; i<num.size()-2; i++)
		{
			if (num[i]>0)
			{
				break;
			}
			if (i>0 && num[i]==num[i-1])
			{
				continue;
			}
			int j=i+1;
			int k=num.size()-1;
			while (j<k)
			{
				if ((j>i+1) && num[j]==num[j-1])
				{
					j++;
					continue;
				}
				if ((k<num.size()-1) && num[k]==num[k+1])
				{
					k--;
					continue;
				}
				if (num[j]+num[k]<-num[i])
				{
					j++;
					continue;
				}
				if (num[j]+num[k]>-num[i])
				{
					k--;
					continue;
				}
				else
				{
					vector<int> tripple;
					tripple.push_back(num[i]);
					tripple.push_back(num[j]);
					tripple.push_back(num[k]);
					tripples.push_back(tripple);
					j++;
					k--;
				}
			}
		}
		return tripples;
	}
};