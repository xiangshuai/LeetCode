#include <algorithm>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int s = (C-A)*(D-B);
		int m = (G-E)*(H-F);
		int sAm = max(min(C, G)-max(E,A), 0)*max(min(D, H)-max(B, F), 0);
		return s+m-sAm;
	}
};