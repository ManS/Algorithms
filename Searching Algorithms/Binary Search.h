#include <iostream>

using namespace std;

/*
When some elements at the beginning of an array are moved to the end, it becomes a rotation of 
the original array. Please implement a function to get the minimum number in a rotation of 
an increasingly sorted array.
*/

int GetMinInRotationSortedArray(int arr[], int mid, int start, int end)
{
	if(start> end)
		return -1;
	if(abs(start-end)<=1)
		return arr[end];
	if(arr[mid] <= arr[end])//mid in the second sorted sub-array
		return GetMinInRotationSortedArray(arr, ((start + mid)/2), start, mid);
	else if(arr[mid] >= arr[start])//mid in the first sorted sub-array
		return GetMinInRotationSortedArray(arr, ((end+mid)/2), mid, end);
}

int GetMinInRotationSortedArray(int arr[], int len)
{
	if(arr == NULL || len <=0)
		return -1;
	return GetMinInRotationSortedArray(arr,len/2 , 0,len-1);
}


/*
A turning number is the maximum number in a unimodal array that increases and then 
decreases. Please write a function (or a method) that finds the index of the turning number in a unimodal array. 
For example, the turning number in the array {1, 2, 3, 4, 5, 10, 9, 8, 7, 6} is 10, so its index 5 is the expected 
output.
*/

int GetTurningNumber(int arr[], int mid, int start, int end, int len)
{
	if(start>end)
		return -1;
	if(mid == 0 || mid == len)
		return -1;
	if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1])//means that this is the turning point
	{
		return arr[mid];
	}
	if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])//means that the turning point is after mid. 
	{
		return GetTurningNumber(arr, (mid+end)/2, mid, end, len);
	}
	else//(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])//means that the turning point is before mid.
	{
		return GetTurningNumber(arr, (mid+start)/2, start, mid, len);
	}
}

int GetTurningNumber(int arr[], int len)
{
	if(arr == NULL || len <= 0)
		return -1;
	return GetTurningNumber(arr,((len-1)/2),0, len-1, len);
}

/*
How do you find the majority element in an array when it exists? The majority is an element 
that occurs for more than half of the size of the array. 
For example, the number 2 in the array {1, 2, 3, 2, 2, 2, 5, 4, 2} is the majority element because it appears five 
times and the size of the array is 9.
*/

//Based on the Partition Method

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int i = start;
	int temp;
	int j;
	for(j = start; j< end; j++)
	{
		if(arr[j]<pivot)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i++] =temp;
		}
	}
	temp = arr[i];
	arr[i] = pivot;
	arr[end] = temp;
	return i;
}

bool checkMajorityExistence(int arr[],int num,int len)
{
	int times =0;
	for(int i=0; i < len; i++)
		if(arr[i]==num)
			times++;
	return(times*2>len);
}

int GetMajorityElement(int arr[], int len)
{
	int mid = len>>1;//means len/2;
	int start = 0, end = len-1;
	int index = partition(arr,start,end);
	while(index != mid)
	{
		if(index > mid)//means that the median is in the left side
		{
			end = index -1;
			index = partition(arr, start,end);
		}else //means that the median is in the left side
		{
			start = index +1;
			index = partition(arr, start, end);
		}
	}
	int res = arr[mid];
	if(checkMajorityExistence(arr,res,len))
		return res;
	else
		return -1;
}

/*According to the definition of the majority, the occurrence of a majority element is greater than the total 
occurrences of all other elements. Therefore, this problem can be solved with a new strategy. It scans the 
array from the beginning to the end, and saves and updates an element of the array as well as a number 
for occurrences. When an element is visited, the occurrence number is incremented if the currently 
visited element is the same as the saved one. Otherwise, it decreases the occurrence number when the 
visited element is different from the saved one. When the occurrence number becomes 0, it saves the 
currently visited element and sets the occurrence number as 1. The last element that sets the occurrence 
number to 1 is the majority element*/
int GetMajorityElement_2(int arr[], int len)
{
	int res = arr[0];
	int times =1;
	for(int i =1;i< len; i++)
	{
		if(times==0)
			res=arr[i];

		if(arr[i]==res)
			times++;
		else
			times--;
	}

	if(checkMajorityExistence(arr,res,len))
		return res;
	return -1;
}

/*
Please implement a function to find how many times a number occurs in a sorted array. 
For instance, the output is 4 when the inputs are an array {1, 2, 3, 3, 3, 3, 4, 5} and the number 3 because 3 
occurs 4 times in the given array.
*/

int getLastOccurrence(int arr[], int start, int end, int k, int len)
{
	if(start>end)
		return -1;

	int middle = start+ (end-start)/2;
	if(arr[middle]==k)
	{
		if((middle<len && arr[middle+1]!=k) || (middle==len-1))
			return middle;
		start =middle+1;
	}
	else if (arr[middle]>k)
	{
		end = middle-1;
	}
	else
		start = middle+1;
	return getLastOccurrence(arr,start,end,k,len);
}

int getFirstOccurrence(int arr[], int start, int end, int k)
{
	if(start>end)
		return -1;
	int middle = start+ (end-start)/2;
	if(arr[middle]==k)
	{
		if((middle>0 && arr[middle-1]!=k) || middle ==0)
			return middle;
		end = middle-1;
	}
	else if(arr[middle]>k)
		end = middle -1;
	else
		start = middle+1;

	return getFirstOccurrence(arr, start,end, k);
}

int countOccurrences(int arr[], int len, int k)
{
	int first = getFirstOccurrence(arr,0,len-1,k);
	int last  = getLastOccurrence(arr,0,len-1,k,len);

	if(first>0&&last>0)
		return last-first+1;
	else
		return 0;
}