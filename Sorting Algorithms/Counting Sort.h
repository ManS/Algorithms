#include <iostream>
using namespace std;

//Worst case: O(N+K)
//Best case: O(N+K)
int ArrayAux[100000];

void CountingSort(int arr[], int arrLen, int SortedArr[], int max)
{
	for(int i=0; i <= max; i++)
		ArrayAux[i]=0;

	for(int i=0; i< arrLen; i++)
		ArrayAux[arr[i]]++;
	for(int i = 1; i<= max; i++)
		ArrayAux[i] +=ArrayAux[i-1];

	for(int i = arrLen -1; i>=0; i--)
	{
		SortedArr[ArrayAux[arr[i]]-1] = arr[i];
		ArrayAux[arr[i]]--;
	}
}