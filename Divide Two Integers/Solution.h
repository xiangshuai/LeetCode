#include <limits>
#include <stdlib.h>
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor==0)
		{
			return INT_MAX;
		}
		int adivid = dividend > 0 ? dividend : -dividend;
		int adivis = divisor > 0 ? divisor : -divisor;
		int ret = 0;
		if (adivis<adivid)
		{
			return ret;
		}
		int sum = 0;
		for (int i=0; i<adivis; i++)
		{
			sum += adivid;
			if (adivis-sum<adivid)
			{
				ret = i+1;
				break;
			}
		}
		if ((dividend ^ divisor) < 0)
		{
			ret = -ret;
		}
		return ret;
	}
	int divide2(int dividend, int divisor)
	{
		if (divisor==0)
		{
			return INT_MAX;
		}
		long long adivid = abs(static_cast<long long>(dividend));
		long long adivis = abs(static_cast<long long>(divisor));
		long long ret = 0;
		while(adivid >= adivis)
		{
			long long base = adivis;
			for (int i=0; adivid >= base; i++)
			{
				adivid -= base;
				base <<= 1;
				ret += 1 << i;
			}
		}
		if ((dividend ^ divisor) < 0)
		{
			ret = -ret;
		}
		int res = static_cast<int>(ret);
		if (ret != res)
		{
			return INT_MAX;
		}
		return ret;
	}
};