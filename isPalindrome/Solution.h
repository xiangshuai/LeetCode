
class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
		{
			return false;
		}

		if (x==0)
		{
			return true;
		}

		int base = 1;
		while(x/base > 10)
			base *= 10;

		while(x)
		{
			int r = x % 10;
			int l = x / base;
			
			if (r!=l)
			{
				return false;
			}

			x -= base * l;
			x /= 10;
			base /= 100;
		}
		return true;
	}
};