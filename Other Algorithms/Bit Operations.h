#include <iostream>

using namespace std;

/*
Please implement a function to get the number of 1s in the binary representation of an integer. 
For example, the integer 9 is 1001 in binary, so it returns 2 since there are two bits of 1.
*/

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

int CountOnes_2(int num)
{
	int count = 0;
	while(num)
	{
		count++;
		num = (num-1) & num;
	}
	return count;
}

/*
Please check whether a number is a power product of 2 in only one C statement.
*/

bool CheckPowOf2(int num)
{
	return ((num!=0) && ((num-1)&num) == 0);
}


/*
Given two integers, m and n, please calculate the number of bits in binary that need to be 
modified to change m to n. For example, the number 10 is 1010 in binary, and 13 is 1101 in binary. We can 
modify 3 bits of 1010 to get 1101 in binary.
*/

int bitsToModify(int num1, int num2)
{
	//count nums of 1's in the num1 XOR num2
	return CountOnes_2(num1 ^ num2);
}


/*
Let’s assume all numbers except two occur twice in an array. How do you get those two 
numbers to occur only once in O(n) time and O(1) space? 
For example, only two numbers, 4 and 6, in the array {2, 4, 3, 6, 3, 2, 5, 5} occur once, and the others numbers 
occur twice. Therefore, the output should be 4 and 6.
*/
int findFirstBitsIs1(int num)
{
	int indexBit =0;
	while(((num-1)&num==0) && (indexBit < 32))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}
bool isBit1(int num, int index)
{
	num = num>>index;

	return (num & 1);
}

void GetOnce(int nums[], int len, int& num1, int& num2)
{
	if(len <2)
		return;
	int xorRes = 0;
	for(int i=0; i < len; i++)
	{
		xorRes = xorRes ^ nums[i];
	}
	int indexOf1 = findFirstBitsIs1(xorRes);

    num1 = num2 = 0;
	for(int i = 0; i < len; i++)
	{
		if(isBit1(nums[i], indexOf1))
			num1 ^= nums[i];
		else
			num2 ^= nums[i];
	}
}

int getIntegerComplement(int num)
{
	int limit = CountOnes(num);

	unsigned int flag  = 1;

	while(limit != 0)
	{
		if(num&flag)
		{
			num &= (flag^INT_MAX);
			limit--;
		}
		else
		{
			num |= flag;
		}
		
		flag = flag << 1;
	}
	return num;
}

/*
Two numbers out of n numbers from 1 to n are missing. The remaining n-2 numbers are 
restored in an array, not in any particular order. Please write a method (or a function) to find the missing two 
numbers.
*/

void findMissing(int nums[], int len, int& num1, int& num2)
{
	int extendedLen = len*2+2;
	int* extendedNums = new int[extendedLen];
	int i=0;
	for(; i < len; i++)
		extendedNums[i] = nums[i];
	for(; i< extendedLen; i++)
		extendedNums[i] = i-len;

	GetOnce(extendedNums,extendedLen, num1, num2);
	delete extendedNums;
}

/*reverse bits of an integer*/

unsigned int swapBits(unsigned int x, unsigned int i, unsigned int j)
{
	unsigned int lo = ((x >> i) & 1);
	unsigned int hi = ((x >> j) & 1); 
	if(hi ^ lo)
	{
		x^= ( (1U << i) | (1U << j) );
	}

	return x;
}

unsigned int reverseXor(int num)
{
	unsigned int n = sizeof(num)*8;
	for(short i =0; i < n/2; i++)
	{
		num = swapBits(num, i, n-i-1);
	}
	return num;
}