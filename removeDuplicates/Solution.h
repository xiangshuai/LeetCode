class Solution {
public:
	int removeDuplicates(int A[], int n) {
		for (int i=0; i<n; i++)
		{
			int j=i+1;
			while (A[i]==A[j])
			{
				j++;
			}
			int c = j-i-1;//ÖØ¸´ÔªËØ
			if (c>0)
			{
				int k=i+1;
				while(j<n)
				{
					A[k++] = A[j++];
				}
				n -= c;
			}
		}
		return n;
	}
};

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int length = 0;
		int i=1;
		while(i<n)
		{
			int j=i;
			if (A[i-1]==A[j])
			{
				i++;
				continue;
			}
			A[i+1] = A[j]; 
			i++;
		}
		return n;
	}
};