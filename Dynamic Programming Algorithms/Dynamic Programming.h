
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
/*
Implement a function that finds the edit distance of two input strings. There are three types of 
edit operations: insertion, deletion, and substitution. Edit distance is the minimal number of edit operations to 
modify a string from one state to the other. 
For example, the edit distance between “Saturday” and “Sunday” is 3 since the following three edit operations are 
required to modify one into another: 
(1) Saturday → Sturday (deletion of ‘a’) 
(2) Sturday → Surday (deletion of ‘t’) 
(3) Surday → Sunday (substitution of ‘n’ for ‘r’) 
There is no way to achieve it with fewer than three operations. 
*/

int EditDistance(string str1, string str2)
{
	int arr[100][100];
	memset(arr,0,10000);
	int n= str1.size();
	int m= str2.size();

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(i == 0)
				arr[i][j] = j;
			else if(j == 0)
				arr[i][j] = i;
			else if(str1[i-1] == str2[j-1])
				arr[i][j] = arr[i-1][j-1];
			else
			{
				arr[i][j] = min(arr[i-1][j], arr[i][j-1], arr[i-1][j-1]) +1;
			}
		}

	return arr[n][m];
}

/*
Implement a function that gets the minimal number of coins with values v1, v2, …, vn, to 
make change for an amount of money with value t. There are an infinite number of coins for each value vi. 
For example, the minimum number of coins to make change for 15 out of a set of coins with values 1, 3, 9, 10 is 
3. We can choose two coins with value 3 and a coin with value 9. The number of coins for other choices should be 
greater than 3. 
*/

int GetMinCount(int total, int coins[],int len)
{
	int* counts = new int[total+1];
	counts[0] = 0;
	for(int i=1; i <= total; i++)
	{
		int count = INT_MAX;
		for(int j=0; j < len; j++)
		{
			if(i - coins[j] >= 0 && count > counts[i-coins[j]])
			{
				count = counts[i - coins[j]];
			}
		}
		if(count < INT_MAX)
			counts[i] = count +1;
		else
			counts[i] = INT_MAX;
	}
	return counts[total];
}

/*Longest Common subsequence problem*/
int LCS(string A, string B)
{
	int N = A.size();
	int M = B.size();
	vector<vector<int>> dp(N+1,vector<int>(M+1,0));

	for(int i = 1 ; i <= N ; i++)
		for(int j =1; j<= M; j++)
		{
			dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
			if(A[i-1]==B[j-1])
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
		}

	return dp[N][M];
}

/*
Please design an efficient algorithm to lay out cells on phone keyboards in order to minimize 
key presses. 
*/

int MinPress(int keys, vector<int> frequencies)
{
	sort(frequencies.begin(), frequencies.end());
	int letters = frequencies.size();
	int presses = 0;
	for(int i = letters-1; i>=0; i--)
	{
		int j = letters -1 -i;
		presses += frequencies[i] * (j/keys+1);
	}
	return presses;
}