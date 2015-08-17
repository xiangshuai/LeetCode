#include <queue>
using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		if (!q1.empty())
		{
			q1.push(x);
		}
		else
		{
			q2.push(x);
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (empty())
		{
			return ;
		}
		
		if (!q1.empty())
		{
			while (q1.size()!=1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
		else 
		{
			while (q2.size()!=1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
	}

	// Get the top element.
	int top() {
		if (empty())
		{
			return 0;
		}

		if (!q1.empty())
		{
			while (q1.size()!=1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			int x = q1.front();
			q2.push(x);
			q1.pop();
			return x;
		}
		else 
		{
			while (q2.size()!=1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			int x = q2.front();
			q1.push(x);
			q2.pop();
			return x;
		}
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty() && q2.empty();
	}

private:
	queue<int> q1;
	queue<int> q2;
};