#include <string>
using namespace std;

class Solution {
public:
	int atoi(string str) {
		int s = 1;
		int y = 0;
		int py = 0;
		bool vflag = false;
		bool oflag = false;
		int h = 0;

		while(str[h]==' ')
		{
			h++;
		}

		for (int i=h; i<str.size(); i++)
		{

			if (str[i]=='-' && i==h)
			{
				s = -1;
				continue;
			}

			if (str[i]=='+' && i==h)
			{
				s = 1;
				continue;
			}
			
			if (s*y/10 < s*py)
			{
				oflag = true;
				break;
			}
			py = y;
			y *= 10;
			if (str[i]<48||str[i]>57)
			{
				vflag = true;
				break;
			}
			y+=s*(str[i]-48);
		}

		if (s*y/10 < s*py || oflag)
		{
			if (s>0)
			{
				y = INT_MAX;
			}
			else
			{
				y = INT_MIN;
			}
		}

		if (vflag)
		{
			y = y/10;
		}

		return y;
	}
};