#include <iostream>
#include "Solution.h"
using namespace std;

int main()
{
	TreeNode root(1);
	Solution1 s2;
	vector<vector<int>> rs = sl.levelOrder(&root);

	for (int i=0; i<rs.size(); i++)
	{
		for (int j=0; j<rs[i].size(); j++)
		{
			cout << rs[i][j] << endl;
		}
	}
}