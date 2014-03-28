
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

unsigned int getNthUglyNo(unsigned int n)
{
	if (n==0)
	{
		return 0;
	}

	vector<unsigned int> ugly(n);
	unsigned int i2 = 0, i3 = 0, i5 = 0;
	unsigned int next_ugly_no = 1;
	unsigned int i;
	unsigned int next_multiple_of_2=2, next_multiple_of_3=3,next_multiple_of_5=5;
	ugly[0] =1;
	for (i=1; i < n; i++)
	{
		next_ugly_no = min(next_multiple_of_2,min(next_multiple_of_3,next_multiple_of_5));
		ugly[i] = next_ugly_no;
		if (next_ugly_no == next_multiple_of_2)
		{
			i2++;
			next_multiple_of_2 = ugly[i2] * 2; 
		}
		if (next_ugly_no == next_multiple_of_3)
		{
			i3++;
			next_multiple_of_3 = ugly[i3] * 3; 
		}
		if (next_ugly_no == next_multiple_of_5)
		{
			i5++;
			next_multiple_of_5 = ugly[i2] * 5; 
		}
	}
	return next_ugly_no;
}

