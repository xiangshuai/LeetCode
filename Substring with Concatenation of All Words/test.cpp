#include "Solution.h"

int main() {
	Solution sl;
	string s = "wordgoodgoodgoodbestword";
	vector<string> words;
	words.push_back("best");
	words.push_back("word");
	words.push_back("good");
	words.push_back("good");

	vector<int> ret = sl.findSubstring(s, words);

}