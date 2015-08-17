#include <string>
using namespace std;

class TrieNode
{
public:
	TrieNode()
	{
		leaf = false;
		for (int i=0; i<26; i++)
		{
			childrens[i] = NULL;
		}
	}
public:
	bool leaf;
	TrieNode* childrens[26];
};

class TrieTree
{
public:
	TrieTree()
	{
		root = new TrieNode();
	}

	void insert(string s)
	{
		TrieNode* p = root;
		for (int i=0; i<s.size(); i++)
		{
			int idx = s[i]-'a';
			if (p->childrens[idx]==NULL)
			{
				p->childrens[idx] = new TrieNode();
			}
			p = p->childrens[idx];
		}
		p->leaf = true;
	}

	bool search(TrieNode* node, string key)
	{
		if (node==NULL)
		{
			return false;
		}
		if (key.size()==0)
		{
			return node->leaf;
		}

		TrieNode* p = node;
		int len = key.size();
		if (key[0]=='.')
		{
			for (int i=0; i<26; i++)
			{
				if (search(p->childrens[i], key.substr(1, len-1)))
				{
					return true;
				}
			}
			return false;
		}
		else
		{
			int idx = key[0]-'a';
			if (p->childrens[idx]==NULL)
			{
				return false;
			}
			return search(node->childrens[idx], key.substr(1, len-1));
		}
	}

public:
	TrieNode* root;
};

class WordDictionary {
public:

	WordDictionary()
	{
		root = new TrieTree();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		root->insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return root->search(root->root, word);
	}
private:
	TrieTree* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");