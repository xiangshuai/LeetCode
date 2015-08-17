#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> num;
		for (int i=0; i<n; i++)
		{
			num.push_back(i+1);
		}
		for (int i=0; i<k-1; i++)
		{
			nextPermutation(num.begin(), num.end());
		}
		string s(n, '0');
		for (int i=0; i<n; i++)
		{
			s[i] += num[i];
		}
		return s;
	}

	bool nextPermutation(vector<int>::iterator begin, vector<int>::iterator end)
	{
		if (begin==end)
		{
			return false;
		}

		if (begin==end-1)
		{
			return false;
		}

		vector<int>::iterator it = end-1;

		for (;;)
		{
			vector<int>::iterator iit = it;
			it--;
			if (*it < *iit)
			{
				vector<int>::iterator jt = end;
				while(*it >= *--jt);
				swap(*it, *jt);
				reverse(iit, end);
				return true;
			}
			if (it==begin)
			{
				reverse(begin, end);
				return false;
			}
		}
	}
};

class Solution2 {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		for (int i=0; i<n; i++)
		{
			s[i] += i+1;
		}
		return kth_permutation(s, n, k);
	}

	int factorial(int n)
	{
		int result = 1;
		for (int i=1; i<=n; i++)
		{
			result *= i;
		}
		return result;
	}

	string kth_permutation(string &s, int n, int k)
	{
		string result;
		k--;
		for (int i=n-1; i>0; i--)
		{
			auto a = next(s.begin(), k/factorial(i)+1);
			result.push_back(*a);
			s.erase(a);
			k = k%factorial(i);
		}
		result.push_back(s[0]);
		return result;
	}
};