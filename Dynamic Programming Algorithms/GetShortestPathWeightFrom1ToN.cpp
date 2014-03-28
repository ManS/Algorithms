/*Given an undirected graph G having N (1<N<=1000) vertices and positive weights. 
Find the shortest path from vertex 1 to vertex N, or state that such path doesn't exist. */


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int GetShortestPathWeightFrom1ToN(const vector<vector<int>> weight)
{
	//weight here represents the adjacency matrix of the graph.
	//if there are no edge between nodes i and j, then
	//weight[i][j] = INF
	int n = weight.size();
	vector<int> dp(n,1000000);

	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i] = min(dp[j] + weight[i][j], dp[i]);
		}
	}
	if (dp[n-1]==1000000)
	{
		return -1;//means no path exist
	}
	return dp[n-1];
}