#include <list>
#include <map>
using namespace std;

struct CacheNode
{
	int key;
	int value;
};

class LRUCache{
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		dummy = new CacheNode(-1, -1);
		dummy->next = dummy;
		dummy->prev = dummy;
		size = 0;
	}

	int get(int key) {
		CacheNode *node = access(key);
		if (node)
		{
			updatePos(node);
			return node->value;
		}
		return -1;
	}

	void set(int key, int value) {
		CacheNode *node = access(key);
		if (node)
		{
			node->value = value;
			updatePos(node);
		}
		else
		{
			if (size == capacity)
			{
				auto it = tables.find(dummy->prev->key);
				it->second->prev->next = dummy;
				dummy->prev = it->second->prev;
				delete it->second;
				tables.erase(it);
				size--;
			}

			CacheNode *newNode = new CacheNode(key, value);
			tables[key] = newNode;
			newNode->next = dummy->next;
			newNode->prev = dummy;
			dummy->next->prev = newNode;
			dummy->next = newNode;
			size++;
		}
	}
	void updatePos(CacheNode* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;

		node->prev = dummy;
		node->next = dummy->next;
		dummy->next->prev = node;
		dummy->next = node;
	}

	CacheNode* access(int key)
	{
		auto it = tables.find(key);
		if (it!=tables.end())
		{
			return tables[key];
		}
		return nullptr;
	}

public:
	list<CacheNode> *dummy;
	int capacity;
	int size;
	map<int, CacheNode*> tables;
};