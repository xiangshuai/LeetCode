#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
private:
	map<char, vector<char>> table;
	vector<string> ret;
	
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size()==0)
		{
			return ret;
		}
		initMap();
		traverse(digits, 0, "");
		return ret;
	}

	void traverse(string &digits, int level, string letter)
	{
		if (level==digits.size())
		{
			ret.push_back(letter);
			return;
		}

		for (int i=0; i<table[digits[level]].size(); i++)
		{
			traverse(digits, level+1, letter+table[digits[level]][i]);
		}
	}

	void initMap()
	{
		table['2'].push_back('a');
		table['2'].push_back('b');
		table['2'].push_back('c');
		table['3'].push_back('d');
		table['3'].push_back('e');
		table['3'].push_back('f');
		table['4'].push_back('g');
		table['4'].push_back('h');
		table['4'].push_back('i');
		table['5'].push_back('j');
		table['5'].push_back('k');
		table['5'].push_back('l');
		table['6'].push_back('m');
		table['6'].push_back('n');
		table['6'].push_back('o');
		table['7'].push_back('p');
		table['7'].push_back('q');
		table['7'].push_back('r');
		table['7'].push_back('s');
		table['8'].push_back('t');
		table['8'].push_back('u');
		table['8'].push_back('v');
		table['9'].push_back('w');
		table['9'].push_back('x');
		table['9'].push_back('y');
		table['9'].push_back('z');
	}
	
};