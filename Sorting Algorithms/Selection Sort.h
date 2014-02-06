#include <iostream>
#include <vector>
using namespace std;

//Worst case: O(n^2)
//Best case: O(n^2)

class SelectionSort
{
public:
	vector<int> Sort(vector<int> nums)
	{
		int n = nums.size();
		for(int i=0; i < n; i++)
		{
			int smallest = i;
			for(int j= i+1; j < n; j++)
				if(nums[i] < nums[smallest])
					smallest = j;
			if(smallest != i)
			{
				int temp = nums[i];
				nums[i] = nums[smallest];
				nums[smallest] = temp;
			}
		}
	}
};