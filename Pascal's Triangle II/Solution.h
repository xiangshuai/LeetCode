#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret;
		ret.push_back(1);
		if (rowIndex==0)
		{
			return ret;
		}
		for (int i=1; i<=rowIndex; i++)
		{
			for (int j=ret.size()-2; j>=0; j--)
			{
				ret[j+1] += ret[j];
			}
			ret.push_back(1);
		}
		return ret;
	}
};