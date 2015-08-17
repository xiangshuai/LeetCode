#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	TreeNode root(1);
	Solution2 sl2;
	vector<int> rest = sl2.inorderTraversal(&root);
	for (int i=0; i<rest.size(); i++)
	{
		cout << rest[i] << endl;
	}
}