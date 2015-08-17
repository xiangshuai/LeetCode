#define INT_MAX 2147483647
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int ret=0;
		int idx = 1 << 30;
		int mflg = idx & m;
		int nflg = idx & n;
		while(mflg==nflg && idx)
		{
			ret |= mflg;
			idx >>= 1;
			mflg = idx & m;
			nflg = idx & n;
		}
		return ret;
	}
};

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int d = INT_MAX;
		while((m & d)!=(n & d))
		{
			d <<= 1;
		}
		return m & d;
	}
};


class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int i=0;
		while(m!=n)
		{
			m >>= 1;
			n >>= 1;
			i++;
		}
		return m<<i;
	}
};