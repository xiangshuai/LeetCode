#include <vector>
#include <map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int n = points.size();
		if (n<2)
		{
			return points.empty() ? 0:1;
		}
		int mxcnt = 0;
		int count = 0;
		//vector<bool> vistied(n, false);
		for (int i=0; i<n; i++)
		{
			count=1;
			for (int j=0; j<n; j++)
			{
				if (points[j].y==points[i].y && points[j].x==points[i].x)
				{
					continue;
				}
				if (points[j].x==points[i].x)
				{
					count=2;
					for (int k=0; k<n; k++)
					{
						if ((points[k].y==points[i].y && points[k].x==points[i].x)
							|| (points[k].y==points[j].y && points[k].x==points[j].x))
						{
							continue;
						}
						if (points[k].x==points[i].x)
						{
							count++;
						}
					}
					mxcnt = max(mxcnt, count);
				}
				else
				{
					int p=(points[j].y-points[i].y)/(points[j].x-points[i].x);
					count=2;
					for (int k=0; k<n; k++)
					{
						if ((points[k].y==points[i].y && points[k].x==points[i].x)
							|| (points[k].y==points[j].y && points[k].x==points[j].x))
						{
							continue;
						}
						if (points[k].x==points[i].x)
						{
							continue;
						}

						if (p==(points[k].y-points[i].y)/(points[k].x-points[i].x))
						{
							count++;
						}
					}
					mxcnt = max(mxcnt, count);
				}
			}
		}
		return mxcnt;
	}
};


class Solution2 {
public:
	int maxPoints(vector<Point>& points) {
		int n = points.size();
		if (n<2)
		{
			return points.empty() ? 0:1;
		}
		int mxcnt = 0;
		for (int i=0; i<n; i++)
		{
			map<float, int> tb;
			int count = 1;
			int same = 0;
			for (int j=0; j<n; j++)
			{
				if (i==j)
				{
					continue;
				}
				if (points[j].y==points[i].y && points[j].x==points[i].x)
				{
					same++;
					continue;
				}
				float k = 1000000000.0f;
				if (points[j].x!=points[i].x)
				{
					k =(float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
				}
				if (tb.find(k)!=tb.end())
				{
					tb[k]++;
				}
				else
				{
					tb[k]=2;
				}
				count = max(count, tb[k]);
			}
			mxcnt = max(mxcnt, count+same);
		}
		return mxcnt;
	}
};