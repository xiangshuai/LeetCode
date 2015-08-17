class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int ai = m-1, bi = n-1, cur = m+n-1;
		while(ai >=0 && bi>=0)
		{
			A[cur--] = A[ai] >= B[bi] ? A[ai--] : B[bi--];
		}
		while(bi>=0)
		{
			A[cur--] = B[bi--];
		}
	}
};