class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ret;
		if (n<1)
		{
			ret.push_back(0);
			return ret;
		}
		
		vector<string> arr;
		arr.push_back("0");
		arr.push_back("1");

		for (int i=2; i<=n; i++)
		{
			int bn = arr.size();
			for (int j=bn-1; j>=0; j--)
			{
				arr.push_back(arr[j]);
			}

			for (int j=0; j<bn; j++)
			{
				arr[j] = "0"+arr[j];
			}

			for (int j=bn; j<arr.size(); j++)
			{
				arr[j] = "1"+arr[j];
			}
		}

		for (int i=0; i<arr.size(); i++)
		{
			ret.push_back(decode(arr[i]));
		}
		return ret;
	}

	int decode(string str)
	{
		int ret = 0;
		for (int i=str.size()-1; i>=0; i--)
		{
			ret += pow(2, str.size()-1-i)*(str[i]-'0');
		}
		return ret;
	}
};