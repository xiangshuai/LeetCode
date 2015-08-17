#include "Solution.h"

int main()
{
	Solution sl;
	vector<int> candidates;
	int target = 7;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	vector<vector<int> > result = sl.combinationSum(candidates, target);

}