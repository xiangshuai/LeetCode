#include <set>
using namespace std;
class Solution {
public:
	bool isHappy(int n) {
		if (n==1)
		{
			return true;
		}
		
		if (hset.count(n))
		{
			return false;
		}

		hset.insert(n);
		int total = 0;
		while(n!=0)
		{
			total += (n%10) * (n%10);
			n /= 10;
		}
		return isHappy(total);
	}

private:
	 set<int> hset;
};

class Solution {
public:
	bool isHappy(int n) {
		set<int> hset;
		while(1)
		{
			if (n==1)
			{
				return true;
			}
			if (hset.count(n))
			{
				return false;
			}
			hset.insert(n);
			int total = 0;
			while(n!=0)
			{
				total += (n%10) * (n%10);
				n /= 10;
			}
			n = total;
		}
	}
};