#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>
#include <strstream>
#include <map>
#include <unordered_map>
using namespace std;

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
		seq >>= 3;
	}
	return str;
}

void dnaSeq()
{
	string seq = "ACG";
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
	cout << eq << endl;
	string stt = decode(92);
}

void dfs(vector<int> &nums, int level, int sum, vector<int> item, vector<vector<int>> &ret)
{
	if (level==3)
	{
		if (sum==30)
		{
			ret.push_back(item);
		}
		return ;
	}

	if (sum>=30)
	{
		return ;
	}

	for (int i=0; i<nums.size(); i++)
	{
		item.push_back(nums[i]);
		dfs(nums, level+1, sum+nums[i], item, ret);
		item.pop_back();
	}
}


//int main () {
//
//	//vector<vector<int> > theta;
//	//theta.resize(1, vector<int>(2, 1));
//	//theta.resize(2, vector<int>(3, 2));
//	//for(int i = 0; i < theta.size(); i ++)
//	//{
//	//	for(int j = 0; j < theta[i].size(); j ++)
//	//		cout << theta[i][j] << " ";
//	//	cout << endl;
//	//}
//
//	//int a=10, b=24;
//	//strstream ss;
//	//ss << b << a;
//	//string s = ss.str();
//
//	//int c = atoi(ss.str());
//	//string st;
//	//st.push_back('0'+10);
//	//st.push_back('0'+24);
//
//	//dnaSeq();
//
//	//map<int, int> tb;
//	//if (tb[4]==1)
//	//{
//	//}
//
//	//unordered_map<int, int> ttb;
//	//if (tb[4]==1)
//	//{
//	//}
//
//
//	//int x = INT_MIN;
//
//	//cout << abs(x) << endl;
//
//	vector<int> nums;
//	nums.push_back(1);
//	nums.push_back(3);
//	nums.push_back(5);
//	nums.push_back(7);
//	nums.push_back(9);
//	nums.push_back(11);
//	nums.push_back(13);
//	nums.push_back(15);
//	vector<int> item;
//	vector<vector<int>> ret;
//	dfs(nums, 0, 0, item, ret);
//	return 0;
//}


class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string item = "";
		generate(n, n, item, ret);
		return ret;
	}

	void generate(int ln, int rn, string item, vector<string>& ret) {
		if(ln==0 && rn==0) {
			ret.push_back(item);
			return ;
		}

		if(ln>0) 
			generate(ln--, rn, item+"(", ret);
		if(rn>ln)
			generate(ln, rn--, item+")", ret);
	}
};

int main()
{
	string s = "au";
	int mx = 0;
	int n = s.size();
	if(n<2) return n;
	int tb[256] = {-1};
	for(int i=0; i<n; i++) {
		mx = max(mx, i-tb[s[i]]);
		tb[s[i]] = i;
	}
	return mx;
}