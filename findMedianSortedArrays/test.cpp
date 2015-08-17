#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	int a[3] = {1, 4, 7};
	int b[3] = {2, 3, 5};
	Solution sl;
	double res = sl.findMedianSortedArrays(a, 3, b, 3);
	cout << res << endl;
}