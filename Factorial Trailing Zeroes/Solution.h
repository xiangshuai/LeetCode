
class Solution {
public:
	int trailingZeroes(int n) {
		int ret = 0;
		for (int i=5; n/i>=1; i*=5)
		{
			ret += n/i;
		}
		return ret;
	}
};