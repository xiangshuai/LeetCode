#include "Solution.h"

int main()
{
	Solution2 sl;
	vector<Point> points;
	points.push_back(Point(84,250));
	points.push_back(Point(0,0));
	points.push_back(Point(1,0));
	points.push_back(Point(0,-70));
	points.push_back(Point(0,-70));
	points.push_back(Point(1,-1));
	points.push_back(Point(21,10));
	points.push_back(Point(42,90));
	points.push_back(Point(-42,-230));
	int ret = sl.maxPoints(points);
}