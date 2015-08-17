class Solution {
public:
	int reverse(int x) {
		int s = x < 0 ? -1 : 1;
		x = x < 0 ? -x : x;
		if (x<0)
		{
			return 0;
		}
		int rx = 0;
		while(x)
		{
			if (rx*10/10 < rx)
			{
				return 0;
			}
			rx *= 10;
			rx += x % 10;
			x /= 10;
		}

		return s * rx;
	}
};