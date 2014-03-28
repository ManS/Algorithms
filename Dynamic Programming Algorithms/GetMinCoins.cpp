/*Given a list of N coins, their values (V1, V2, ... , VN), and the total sum S. 
Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want), 
or report that it's not possible to select coins in such a way that they sum up to S. */


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int GetMinCoins(const vector<int>& coins, int sum)
{
	if (sum==0)
	{
		return 0;
	}
	int n = coins.size();
	if (n == 0)
	{
		return 0;
	}

	vector<int> minCoins(sum+1,INT_MAX - 1);
	minCoins[0] = 0;
	for (int i = 1; i <= sum; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (coins[j]<=i && minCoins[i-coins[j]]+1 < minCoins[i])
			{
				minCoins[i]= minCoins[i-coins[j]]+1;
			}
		}
	}
	
	if (minCoins[sum] == INT_MAX -1)
	{
		return -1;//means not possible
	}

	return minCoins[sum];
}