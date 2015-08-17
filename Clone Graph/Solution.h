#include <vector>
#include <map>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node)
		{
			return NULL;
		}
		
		map<int, UndirectedGraphNode*> tb;
		return clone(node, tb);
	}

	UndirectedGraphNode* clone(UndirectedGraphNode* node, map<int, UndirectedGraphNode*> &tb)
	{
		UndirectedGraphNode* cnode;
		if (tb.find(node->label)!=tb.end())
		{
			cnode = tb[node->label];
			return cnode;
		}
		cnode = new UndirectedGraphNode(node->label);
		tb[node->label] = cnode;

		for (int i=0; i<node->neighbors.size(); i++)
		{
			cnode->neighbors.push_back(clone(node->neighbors[i], tb));
		}
		return cnode;
	}
};

