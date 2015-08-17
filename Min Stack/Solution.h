#include <vector>
#include <stack>
using namespace std;

class MinStack {
public:
	void push(int x) {
		nums.push_back(x);
		if (mins.empty())
		{
			mins.push_back(x);
		}
		else
		{
			int minN = x < mins.back()? x : mins.back();
			mins.push_back(minN);
		}
	}

	void pop() {
		if (!nums.empty())
		{
			nums.pop_back();
			mins.pop_back();
		}
	}

	int top() {
		if (!nums.empty())
		{
			return nums.back();
		}
	}

	int getMin() {
		if (!mins.empty())
		{
			return mins.back();
		}
		return INT_MIN;
	}
private:
	vector<int> nums;
	vector<int> mins;
};