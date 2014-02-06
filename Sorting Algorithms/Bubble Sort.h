#include <iostream>
#include <vector>
using namespace std;

//Worst case: O(n^2)
//Best case: O(n^2)

class BubbleSort
{
public:
	vector<int> Sort(vector<int> nums)
	{
		int n = nums.size();
		bool sorted;
		for(int i=0; i < n; i++)
		{
			sorted = true;
			for(int j= n-1; j >i; j--)
			{
				if(nums[j] < nums[j-1])
				{
					int temp = nums[j-1];
					nums[j-1] = nums[j];
					nums[j] = temp;
					sorted = false;
				}
			}
			if (sorted)
			{
				break;	
			}
		}
	}
};