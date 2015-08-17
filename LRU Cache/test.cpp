#include "Solution.h"

int main()
{
	LRUCache lc(1);
	lc.set(2, 1);
	lc.get(2);
	lc.set(3,2);
	lc.get(2);
	lc.get(3);
	return 0;
}