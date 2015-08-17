#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n<1)
		{
			return false;
		}
		int m = matrix[0].size();

		int top = 0;
		int bottom = n-1;
		while(top<=bottom)
		{
			int mid = (top+bottom)/2;
			if (matrix[mid][0]==target)
			{
				return true;
			}
			else if (matrix[mid][0]>target)
			{
				bottom = mid-1;
			}
			else if(matrix[mid][0]<target)
			{
				top = mid+1;
			}
		}

		if (bottom<0)
		{
			return false;
		}

		int row = top-1;
		int left = 0;
		int right = m-1;
		while(left<=right)
		{
			int mid = (left+right)/2;
			if (matrix[row][mid]==target)
			{
				return true;
			}
			if (matrix[row][mid]<target)
			{
				left = mid+1;
			}
			else if (matrix[row][mid]>target)
			{
				right = mid-1;
			}
		}
		return false;
	}
};

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n<1)
		{
			return false;
		}
		int m = matrix[0].size();
		if (matrix[0][0]>target)
		{
			return false;
		}
		int top = 0;
		int bottom = n-1;
		while(top<=bottom)
		{
			int mid = (top+bottom)/2;
			if (matrix[mid][0]==target)
			{
				return true;
			}
			else if (matrix[mid][0]>target)
			{
				bottom = mid-1;
			}
			else if(matrix[mid][0]<target)
			{
				top = mid+1;
			}
		}

		int row = top-1;
		int left = 0;
		int right = m-1;
		while(left<=right)
		{
			int mid = (left+right)/2;
			if (matrix[row][mid]==target)
			{
				return true;
			}
			if (matrix[row][mid]<target)
			{
				left = mid+1;
			}
			else if (matrix[row][mid]>target)
			{
				right = mid-1;
			}
		}
		return false;
	}
};