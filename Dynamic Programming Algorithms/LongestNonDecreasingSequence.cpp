/*Given a sequence of N numbers - A[1] , A[2] , ..., A[N] . Find the length of the longest non-decreasing sequence. */



#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


int LongestNonDecreasingSequence(const vector<int>& sequence)
{
	int n = sequence.size();
	if (n==0)
	{
		return 0;
	}
	if (n==1)
	{
		return 1;
	}
	vector<int> dp(n,1);
	for (int i = 0; i < n; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (sequence[j]<=sequence[i] && dp[i]<dp[j]+1)
			{
				dp[i] = dp[j]+1;
			}
		}
	}

	return dp[n-1];
}