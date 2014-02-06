#include <iostream>
#include <vector>

using namespace std;
//Worst case: O(n^2)
//Best case: O(n log n)

int PARTITION(int Array[], int start, int end)
{
	int pivot = Array[end]; //pivot
	int Temp;
	int i = start;
	for(int j = start; j < end; j++)
	{
		if(Array[j] <= pivot) 
		{
			Temp = Array[j];
			Array[j] = Array[i];
			Array[i++] = Temp;
		}
	}

	Temp = Array[i];
	Array[i] = Array[end];
	Array[end] = Temp;
	return i;
}

void QUICK_SORT(int Array[], int p, int r)
{
	if(p<r)
	{
		int q= PARTITION(Array,p,r);
		QUICK_SORT(Array,p,q-1);
		QUICK_SORT(Array,q+1,r);
	}
}

