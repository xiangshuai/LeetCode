#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ret;
		if(s.size()<1 || words.size()<1) return ret;
		map<string, int> tb;
		for(int i=0; i<words.size(); i++) {
			if(tb.count(words[i])) tb[words[i]]++;
			else tb[words[i]] = 1;
		}

		int l = words[0].size();
		if(s.size()<l) return ret;

		for(int i=0; i<l; i++) {
			map<string, int> ctb;
			int count = 0;
			int left = i;
			for(int j=i; j<s.size()-l; j+=l) {
				string w = s.substr(j, l);
				if(tb.count(w)) {
					if(ctb.count(w)) ctb[w]++;
					else ctb[w] = 1;
					count++;
					while(ctb[w]>tb[w]) {
						string tmp = s.substr(left, l);
						ctb[tmp]--;
						count--;
						left += l;
					}
					if(count==words.size()) {
						ret.push_back(left);
						string tmp = s.substr(left, l);
						ctb[tmp]--;
						count--;
						left += l;
					}
				}
				else {
					ctb.clear();
					count = 0;
					left = j+l;
				}
			}
		}
		return ret;
	}
};