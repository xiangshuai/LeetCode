#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		int carry = 0;
		int i = a.size()-1;
		int j = b.size()-1;
		for (; j>=0 || i>=0; i--,j--)
		{
			int ca = i>=0 ? a[i] - '0' : 0;
			int cb = j>=0 ? b[j] - '0' : 0;
			int val = (ca + cb + carry) % 2;
			carry = (ca + cb + carry) / 2;
			result.insert(result.begin(), val+'0');
		}
		if (carry==1)
		{
			result.insert(result.begin(), '1');
		}
		return result;
	}
};
