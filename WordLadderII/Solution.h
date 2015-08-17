#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> > ret;
		if (start==end)
		{
			vector<string> it;
			it.push_back(start);
			ret.push_back(it);
			return ret;
		}
		queue<string> qstr;
		qstr.push(start);
		map<string, int> stptb;
		stptb[start] = 1;
		multimap<string, string> pretb;
		map<string, bool> pattb;
		int step = INT_MAX;
		while(!qstr.empty())
		{
			string curstr = qstr.front();
			qstr.pop();
			
			for (int i=0; i<curstr.length(); i++)
			{
				string tstr = curstr;
				for (char j='a'; j<='z'; j++)
				{
					if (j!=tstr[i])
					{
						tstr[i] = j;
						if (tstr==end)
						{
							step = min(step, stptb[curstr] + 1);
							pattb[curstr] = true;
						}
						// ШЅжи
						if (dict.find(tstr)!=dict.end())
						{
							if (stptb.find(tstr)==stptb.end())
							{
								stptb[tstr] = stptb[curstr] + 1;
								pretb.insert(pair<string, string>(tstr, curstr));
								qstr.push(tstr);
							}
							pair<multimap<string, string>::iterator, multimap<string, string>::iterator> ret;
							ret = pretb.equal_range(tstr);
							bool flag = false;
							for (multimap<string, string>::iterator it = ret.first; it!=ret.second; ++it)
							{
								if (it->second==curstr)
								{
									flag = true;
								}
							}
							if (!flag)
							{
								pretb.insert(pair<string, string>(tstr, curstr));
							}
						}
					}
				}
			}
		}
		for (map<string, int>::iterator itr = stptb.begin(); itr!=stptb.end(); itr++)
		{
			if (itr->second==step-1 && pattb[itr->first])
			{
				vector<string> item;
				item.push_back(end);
				string lkstr = itr->first;
				dfs(pretb, lkstr, item);
				item.push_back(start);
				reverse(item.begin(), item.end());
				ret.push_back(item);
			}
		}
		return ret;
	}

	void dfs(multimap<string, string> &pretb, string lkstr, vector<string> &item)
	{
		if (pretb.find(lkstr)==pretb.end())
		{
			return ;
		}

		item.push_back(lkstr);
		pair<multimap<string, string>::iterator, multimap<string, string>::iterator> pts;
		pts = pretb.equal_range(lkstr);
		for (multimap<string, string>::iterator it = pts.first; it!=pts.second; ++it)
		{
			dfs(pretb, it->second, item);
		}
	}
};

class Solution2 {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> ret;
		vector<string> item;
		if (start==end)
		{
			item.push_back(start);
			ret.push_back(item);
			return ret;
		}

		unordered_set<string> current, next;
		unordered_set<string> visited;
		map<string, vector<string>> fathers_tb;

		current.insert(start);
		bool found = false;

		while(!current.empty() && !found)
		{
			for (unordered_set<string>::iterator it = current.begin(); it!=current.end(); it++)
			{
				visited.insert(*it);
			}

			for (unordered_set<string>::iterator it = current.begin(); it!=current.end(); it++)
			{
				string curstr = *it;
				for (int j=0; j<curstr.size(); j++)
				{
					string tpstr = curstr;
					for (char c='a'; c<='z'; c++)
					{
						if (c==tpstr[j])
						{
							continue;
						}
						tpstr[j] = c;
						if (tpstr==end)
						{
							found = true;
							fathers_tb[tpstr].push_back(curstr);
						}
						if (dict.find(tpstr)!=dict.end() && visited.find(tpstr)==visited.end())
						{
							next.insert(tpstr);
							if (tpstr!=end)
							{
								fathers_tb[tpstr].push_back(curstr);
							}
						}
					}
				}
			}
			current.clear();
			swap(current, next);
		}

		if (found)
		{
			item.push_back(end);
			dfs(fathers_tb, end, item, ret);
		}
		return ret;
	}

	void dfs(map<string, vector<string>> &fathers_tb, string curstr, vector<string> &item, vector<vector<string>> &ret)
	{

		if (fathers_tb.find(curstr)==fathers_tb.end())
		{
			ret.push_back(item);
			reverse(ret.back().begin(), ret.back().end());
		}
		else
		{
			vector<string> &fathers = fathers_tb[curstr];

			for (int i=0; i<fathers.size(); i++)
			{
				item.push_back(fathers[i]);
				dfs(fathers_tb, fathers[i], item, ret);
				item.pop_back();
			}
		}
	}
};