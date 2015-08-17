#include <string>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		if (beginWord==endWord)
		{
			return 1;
		}
		int step=INT_MAX;
		queue<string> qstr;
		qstr.push(beginWord);
		map<string, int> table;
		table[beginWord] = 1;
		while (!qstr.empty())
		{
			string str = qstr.front();
			qstr.pop();
			for (int i=0; i<str.length(); i++)
			{
				string tstr = str;
				for (char j='a'; j<='z'; j++)
				{
					if(tstr[i]!=j)
					{
						tstr[i]=j;
						if (tstr==endWord)
						{
							step = min(step, table[str]+1);
						}
						if (wordDict.find(tstr)!=wordDict.end() && table.find(tstr)==table.end())
						{
							qstr.push(tstr);
							table[tstr] = table[str]+1;
						}
					}
				}
			}
		}
		if (step==INT_MAX)
		{
			step=0;
		}
		return step;
	}
};

class Solution2 
{
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		if (beginWord==endWord)
		{
			return 1;
		}
		queue<string> current, next;
		map<string, bool> visited;

		current.push(beginWord);
		visited.insert(beginWord);
		int level = 0;
		bool found = false;

		while(!current.empty() && !found)
		{
			level++;
			while(!current.empty() && !found)
			{
				string cstr = current.front();
				current.pop();
				for (int i=0; i<cstr.size(); i++)
				{
					string tpstr = cstr;
					for (char c='a'; c<='z'; c++)
					{
						if (c==tpstr[i])
						{
							continue;
						}
						tpstr[i] = c;
						if (tpstr==endWord)
						{
							found = true;
							break;
						}
						if (wordDict.find(tpstr)!=wordDict.end() && visited.find(tpstr)==visited.end())
						{
							next.push(tpstr);
							visited.insert(tpstr);
						}
					}
					if (found)
					{
						break;
					}
				}
			}
			if (found)
			{
				break;
			}
			swap(current, next);
		}
		if (found)
		{
			return level+1;
		}
		else
		{
			return 0;
		}
	}
};