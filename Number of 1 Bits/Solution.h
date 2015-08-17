class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while(n)
		{
			int bit = n & 1;
			n >>= 1;
			if (bit)
			{
				cnt++;
			}
		}
		return cnt;
	}
};