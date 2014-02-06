#include <iostream>
#include <string>
#include <vector>
using namespace std;


//worst case: O(N logN)
//Best case : O(N logN)
//Storage Complexity: O(N)

int Left(int i)
{
	return 2*i;
}

int Right(int i)
{
	return 2*i +1;
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
void BuildMaxHeap(int array[], int heap_size)
{
	for (int i = heap_size/2-1; i >= 0; i--)
	{
		
		Max_Heapify(array,i, heap_size);
		
	}
}
void HeapSort(int array[], int length)
{

	if (length <= 1)
	{
		return;
	}
	//Build a max heap
	BuildMaxHeap(array, length);
	int heap_size = length;
	for (int i = heap_size-1; i >= 0; i--)
	{
		//Swap A[0] with A[length-i+1]
		int temp = array[0];
		array[0] = array[heap_size-1];
		array[heap_size-1] = temp;
		//Decrement array size by 1.
		heap_size--;

		Max_Heapify(array,0, heap_size);
	}
}