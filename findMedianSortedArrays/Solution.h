#ifndef SOLUTION_H
#define SOLUTION_H
#include <windows.h>

double findkth(int A[], int m, int B[], int n, int k) {
	if (m>n)
	{
		return findkth(B, n, A, m, k);
	}

	if(m==0)
	{
		return B[k-1];
	}

	if(k==1)
	{
		return min(A[0], B[0]);
	}
	int pa = min(k/2, m), pb = k-pa;
	if (A[pa-1]<B[pb-1])
	{
		return findkth(A+pa, m-pa, B, n, k-pa);
	}
	else if(A[pa-1]>B[pb-1])
	{
		return findkth(A, m, B+pb, n-pb, k-pb);
	}
	else
	{
		return A[pa-1];
	}
}

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int sum = m + n;
		if (sum%2==0)
		{
			int kl = sum/2;
			int kr = sum/2+1;
			return (findkth(A, m, B, n, kl) + findkth(A, m, B, n, kr))/2;
		}
		return findkth(A, m, B, n, sum/2+1);
	}
};


#endif