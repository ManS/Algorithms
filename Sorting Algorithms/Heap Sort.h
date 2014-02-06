#include <iostream>
#include <string>
#include <vector>
using namespace std;


//worst case: O(N logN)
//Best case : O(N logN)
//Storage Complexity: O(N)

int Left(int i)
{
	if (i>0)
		return 2*i;
	else
		return 1;
	
}

int Right(int i)
{
		if (i>0)
		return 2*i +1;
	else
		return 2;
}

int Parent(int i)
{
	return i/2;
}

void Max_Heapify(int array[], int i, int heap_size)
{
	int l = Left(i);
	int r = Right(i);
	int largest;
	if (l < heap_size && array[l] > array[i])
	{
		largest = l;
	}
	else
		largest = i;

	if (r < heap_size && array[r] > array[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		int temp = array[largest];
		array[largest] = array[i];
		array[i] = temp;
		// call Max_Heapify for the switched node
		Max_Heapify(array, largest, heap_size);
	}
}

void Min_Heapify(int array[],int i, int heap_size)
{
	int l = Left(i);
	int r = Right(i);

	int smallest;
	if(l < heap_size && array[l] < array[i])
	{
		smallest = l;
	}
	else
		smallest = i;
	if( r < heap_size && array[r] < array[smallest])
		smallest=r;

	if(smallest != i)
	{
		int temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
		Min_Heapify(array, smallest, heap_size);
	}
}

void BuildMinOrMaxHeap(int array[], int heap_size, bool max_heap)
{
	for (int i = heap_size/2-1; i >= 0; i--)
	{
		if (!max_heap)
		{
			Min_Heapify(array, i, heap_size);
		}
		else
			Max_Heapify(array,i, heap_size);
		
	}
}

void HeapSort(int array[], int length, bool ascending)
{
	if (length <= 1)
	{
		return;
	}
	//Build a max or min heap
	BuildMinOrMaxHeap(array, length, ascending);

	int heap_size = length;
	for (int i = heap_size-1; i >= 0; i--)
	{
		//Swap A[0] with A[length-i+1]
		int temp = array[0];
		array[0] = array[heap_size-1];
		array[heap_size-1] = temp;
		//Decrement array size by 1.
		heap_size--;
		if (ascending)
		{		
			Max_Heapify(array,0, heap_size);
		}
		else
		{
			Min_Heapify(array,0, heap_size);
		}
	}
}