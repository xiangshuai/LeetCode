
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if(*p==0) return *s==0;

		if(*s==0) return *p==0;

		if (*s!=0 && (*s==*p || *p=='.'))
		{
			return isMatch(s+1, p+1);
		}

		if (*p=='*')
		{
			if (*s!=0 && *(p+1)==*(s+1))
			{
				int i=0;
				bool flag = false;
				while(*(s+i))
				{
					flag = flag || isMatch(s+i+1, p+1);
					i++;
				}
				return flag;
			}
			if (*s!=0 && *(p+1)==*s)
			{
				return isMatch(s, p+1);
			}
			else
			{
				int i=0;
				bool flag = false;
				while(*(s+i))
				{
					flag = flag || isMatch(s+i+1, p);
					i++;
				}
				return flag;
			}
		}

		while(*(p+1)!='*'||*(p+1)!='.')
		{
			return isMatch(s, p+1);
		}

		if (*s!=0 && (*s==*p || *p=='.'))
		{
		}
				
	}
};

class Solution1
{
public:
	bool isMatch(const char *s, const char *p) {
		if (*s==0) return *p==0;

		if(*(p+1)=='*')
		{

		}
	}
};