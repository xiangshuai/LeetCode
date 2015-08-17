#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPrime(int digit)
	{
		int i;
		for (i=2; i*i<digit; i++)
		{
			if (digit%i==0)
			{
				return false;
			}
		}
		return true;
	}

	int countPrimes(int n) {
		int count = 0;
		for (int i=1; i<=n; i++)
		{
			if (isPrime(i))
			{
				count++;
			}
		}
		return count;
	}
};


class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		map<int, bool> table;
		for (int i=2; i<n; i++)
		{
			table[i] = true;
		}

		for (int i=2; i*i<n; i++)
		{
			if (!table[i])
			{
				continue;
			}
			for (int j=i; j*i<n; j++)
			{
				table[j*i] = false;
			}
		}

		for (auto it=table.begin(); it!=table.end(); it++)
		{
			if (it->second)
			{
				count++;
			}
		}
		return count;
	}
};

class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		vector<bool> table(n, true);

		for (int i=2; i*i<n; i++)
		{
			if (!table[i])
			{
				continue;
			}
			for (int j=i; j*i<n; j++)
			{
				table[j*i] = false;
			}
		}

		for (int i=2; i<n; i++)
		{
			if (table[i])
			{
				count++;
			}
		}
		return count;
	}
};