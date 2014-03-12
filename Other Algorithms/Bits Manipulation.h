#include <vector>
#include <string>
#include <iostream>

using namespace std;
//5.1 You are given two 32-bit numbers, N and M, and two bit positions, i and j Write a 
//method to set all bits between i and j in N equal to M (e.g. , M becomes a substring of 
//N located at i and starting at j).

int ReplaceBits(int N, int M, int i, int j)
{
	int max = ~0; //All 1’s

	//1’s through position j, then 0
	int left = max - ((1 << i) - 1);	

	//1’s after position i
	int right =((1<<i )- 1);

	//1’s, with 0s between i and j
	int mask = left | right;
	
	return (N & mask) | (M << i);
}

///////////////////////////////////////////////////////////////////////////////////////
//5.3Given an integer, print the next smallest and next largest number that have the same 
//number of 1 bits in their binary representation
int CountOnes(int num)
{
	unsigned int flag  = 1;
	int count = 0;
	while(flag)
	{
		if(num&flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

void PrintSmallestAndLargest(int num)
{
	int numOf1Bits =  CountOnes(num);
	cout<<"Smallest: "<< ((1<<numOf1Bits+1)-1)<<endl;
	cout<<"Largest: "<<(~0 - ((1<<numOf1Bits+1)-1))<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////
//5.5 Write a function to determine the number of bits required to convert integer A to 
//integer B
//Input: 31, 14
//Output: 2

int numOfDiffBits(int numA, int numB)
{
	return CountOnes(numA ^ numB);
}
///////////////////////////////////////////////////////////////////////////////////////
//5.6  Write a program to swap odd and even bits in an integer with as few instructions as 
//possible (e g , bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc)

//Mask all odd bits with 10101010 in binary (which is 0xAA), then shift them left to put them in 
//the even bits Then, perform a similar operation for even bits This takes a total 5 instructions.

int swapOddEvenBits(int num)
{
	return (((num & 0xaaaaaaaa)>>1) | ((num & 0x55555555)<<1));
}