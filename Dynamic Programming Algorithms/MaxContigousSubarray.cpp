
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


int Max_Contigous_SubArray(const vector<int>& myarr)
{
	int n = myarr.size();
	if (n<1)
	{
		return 0;
	}
	if (n==1)
	{
		return myarr[0];
	}

	int curr_max = myarr[0];
	int max_so_far = myarr[0];
	int i;
	for (i = 0; i< n; i++)
	{
		curr_max = max(myarr[i],curr_max + myarr[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}
