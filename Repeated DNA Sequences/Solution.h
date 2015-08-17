#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ret;
		int n = s.length();
		if (n<10)
		{
			return ret;			
		}
		map<string, int> tb;
		for (int i=0; i<n-10; i++)
		{
			string seq = s.substr(i, 10);
			if (tb.find(seq)!=tb.end())
			{
				tb[seq]++;
			}
			else
			{
				tb[seq] = 1;
			}
		}
		for (auto it = tb.begin(); it!=tb.end(); it++)
		{
			if (it->second>1)
			{
				ret.push_back(it->first);
			}
		}
		return ret;
    }
};

// TLE
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ret;
		int n = s.length();
		if (n<10)
		{
			return ret;			
		}
		set<string> sq_set;
		bool is_sure = false;
		for (int i=0; i<n-9; i++)
		{
			string seq = s.substr(i, 10);
			if (sq_set.find(seq)!=sq_set.end())
			{
				continue;
			}
			for (int j=i+1; j<n-9; j++)
			{
				int k=0;
				for (; k<10; k++)
				{
					if (s[i]!=s[j])
					{
						break;
					}
				}
				if (k==10)
				{
					is_sure = true;
				}
			}
			if (is_sure)
			{
				sq_set.insert(seq);
			}
		}

		for (auto it = sq_set.begin(); it!=sq_set.end(); it++)
		{
			ret.push_back(*it);
		}
		
		return ret;
	}
};


class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ret;
		int n = s.length();
		if (n<10)
		{
			return ret;			
		}
		map<int, int> tb;
		set<string> seq_set;
		for (int i=0; i<n-9; i++)
		{
			string seq = s.substr(i, 10);
			int eq = encode(seq);
			if (tb.find(eq)!=tb.end())
			{
				tb[eq]++;
			}
			else
			{
				tb[eq] = 1;
			}
		}
		for (auto it = tb.begin(); it!=tb.end(); it++)
		{
			if (it->second>1)
			{
				ret.push_back(decode(it->first));
			}
		}
		return ret;
	}

	int encode(string seq)
	{
		int eq = 0;
		for (int i=0; i<seq.size(); i++)
		{
			eq <<= 3;
			if (seq[i]=='A')
			{
				eq |= 1;
			}
			else if (seq[i]=='T')
			{
				eq |= 2;
			}
			else if (seq[i]=='C')
			{
				eq |= 3;
			}
			else if (seq[i]=='G')
			{
				eq |= 4;
			}
		}
		return eq;
	}

	string decode(int seq)
	{
		string str = "";
		for (int i=0; i<10; i++)
		{
			int c = seq & 7;
			switch(c)
			{
			case 1:
				str += 'A';
				break;
			case 2:
				str += 'T';
				break;
			case 3:
				str += 'C';
				break;
			case 4:
				str += 'G';
				break;
			default:
				break;
			}
			seq <<= 3;
		}
		reverse(str.begin(), str.end());
		return str;
	}

};