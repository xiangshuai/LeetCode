#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution sl;
	string s1 = "ac";
	string s2 = "dbbca";
	string s3 = "adbbcac";

	cout << sl.isInterleave(s1, s2, s3) << endl;
}