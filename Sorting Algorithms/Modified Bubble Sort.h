#include <iostream>
#include <vector>
using namespace std;

//Worst case: O(n^2)
//Best case: O(n)

class ModifiedBubbleSort
{
public:
	vector<int> Sort(vector<int> nums)
	{
		int n = nums.size();
		for(int i=0; i < n; i++)
		{
			bool sorted = true;
			for(int j= n-1; j >i; j--)
			{
				if(nums[j] < nums[j-1])
				{
					sorted = false;
					int temp = nums[j-1];
					nums[j-1] = nums[j];
					nums[j] = temp;
				}
				if(sorted)
					break;
			}
		}
	}
};