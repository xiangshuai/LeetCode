#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
		int sumRemaining = 0;
		int curRemaining = 0;
		int start = 0;
		int total = 0;
		for (int i=0; i<n; i++)
		{
			curRemaining = gas[i]-cost[i];

			if (sumRemaining>=0)
			{
				sumRemaining += curRemaining;
			}
			else
			{
				sumRemaining = curRemaining;
				start = i;
			}
			total += curRemaining;
		}
		if (total>=0)
		{
			return start;
		}
		else
		{
			return -1;
		}
    }
};