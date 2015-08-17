class Solution {
public:
	int reverse(int x) {
		int s = 1;
		if (x < 0)
		{
			s = -1;
		}

		int ux = x>0?x:-x;
		int y = 0;
		int py = 0;
		while(ux > 0)
		{
			py = y;
			y *= 10;
			y += ux % 10;
			ux = ux / 10;
		}

		if (y/10 < py)
		{
			y = 0;
		}
		return s*y;
	}
};