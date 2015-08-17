class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t rbits = 0;
		for (int i=0; i<32; i++)
		{
			rbits <<= 1;
			rbits |= n & 0x1;
			n >>= 1;
		}
		return rbits;
	}
};