#include <iostream>
using namespace std;

/*
You are given two sorted arrays, A and B, and A has a large enough buffer at the end 
to hold B  Write a method to merge B into A in sorted order.
*/
void MergeAndSort(int a[], int b[], int n, int m)
{
	if(a==NULL || b==NULL||n<=0||m<=0)
		return;

	int k = m+n -1; //last index of b
	int i = n-1;// last element of array b
	int j= m-1; //last element of array a

	while(i>=0 && j>=0)
	{
		if(a[i]>b[j])
		{
			a[k--] = a[i--];
		}
		else
		{
			a[k--] = b[j--];
		}
	}

	while(j>=0)
	{
		a[k--] = b[j--];
	}
}

/*
Write a method to sort an array of strings so that all the anagrams are next to each 
other.
*/
bool areEqual(char* str1, char* str2)
{
	if(str1 == NULL || str2 == NULL)
		return false;
	char* iter1 = str1;
	char* iter2 = str2;

	while(iter1 != NULL && iter2 != NULL)
	{
		
	}
}
void SortStrings(char** arrOfStr, int n)
{

}

/*
Given a positive value s, print all sequences with continuous numbers (with two numbers at 
least) whose sum is s. 
Take the input s=15 as an example. Because 1+2+3+4+5=4+5+6=7+8=15, three continuous sequences should 
be printed: 1~5, 4~6, and 7~8. 
*/

void printContinuousSequence(int small, int big)
{
	for(int i = small; i<= big; i++)
		cout<<i<<" ";
	cout<<endl;
}

void findContinuousSequence(int sum)
{
	if(sum<3)
		return;
	int small =1;
	int big = 2;
	int middle = (1+sum)/2;
	int curSum = small + big;

	while(small<middle)
	{
		if(curSum == sum)
		{
			printContinuousSequence(small, big);
		}
		while(curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if(curSum == sum)
				printContinuousSequence(small,big);
		}
		big++;
		curSum += big;
	}
}