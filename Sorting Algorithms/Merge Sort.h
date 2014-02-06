#include <iostream>
#include <vector>

//Worst case: O(n log n)
//Best case: O(n log n)
//merge sort is most used with linked list.

using namespace std;
int RightArray[100];
int LeftArray[100];

void MERGE(int Array[], int start, int mid, int end)
{
	int arr1Length= mid - start + 1;
	int arr2Length= end - mid;
	
	for(int i =0; i < arr1Length; i++)
		LeftArray[i]= Array[start+i];

	for(int i =0; i < arr2Length; i++)
		RightArray[i]= Array[mid+1+i];

	int arr1Indexer = 0, arr2Indexer =0, index =0;
	while(arr1Indexer < arr1Length && arr2Indexer < arr2Length)
	{
		if(LeftArray[arr1Indexer] <= RightArray[arr2Indexer])
			Array[start+index] = LeftArray[arr1Indexer++];
		else
			Array[start+index] = RightArray[arr2Indexer++];
		index++;
	}
	if(arr1Indexer < arr1Length)
		for(int i=arr1Indexer; i < arr1Length; i++, index++)
			Array[start+index] = LeftArray[i];
	else if(arr2Indexer < arr2Length)
		for(int i= arr2Indexer; i< arr2Length; i++, index++)
			Array[start+index] = RightArray[i];
}	

void MERGE_SORT(int Array[], int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		MERGE_SORT(Array,p,q);
		MERGE_SORT(Array,q+1,r);
		MERGE(Array,p,q,r);
	}
}