#include <iostream>
#include <vector>
using namespace std;

//Worst case: O(n^2)
//Best case: O(n)
//Insertion sort is most used with nearly sorted arrays.

class InsertionSort
{
public:
	vector<int> Sort(vector<int> nums)
	{
		for(int i =1; i < nums.size(); i++)
		{
			int key = nums[i];
			int j= i-1;
			while(j>=0 && nums[j] > key)
			{
				nums[j+1] = nums[j--];
			}
			nums[j+1] = key;
		}
		return nums;
	}
};