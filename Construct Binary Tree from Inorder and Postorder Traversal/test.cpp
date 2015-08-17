#include "Solution.h"

int main()
{
	vector<int> inorder, postorder;
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(2);
	postorder.push_back(3);
	postorder.push_back(2);
	postorder.push_back(1);
	Solution sl;
	sl.buildTree(inorder, postorder);
}