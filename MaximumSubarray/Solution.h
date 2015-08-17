#include <vector>
class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n<1)
		{
			return 0;
		}
		int max_end_here = A[0];
		int retVal = A[0];
		for (int i=1; i<n; i++)
		{
			max_end_here = max(max_end_here + A[i], A[i]);
			retVal = max(retVal, max_end_here);
		}
		return retVal;
	}
};