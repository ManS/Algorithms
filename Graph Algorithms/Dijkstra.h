#include <stdio.h>
#include <limits.h>
//Time Complexity of the implementation is O(V^2).
//number of vertices
#define V 9

//A utility function to find the vertex with minimum distance value, from
//the set of vertices not yet included in shortest path tree

int minDistance(int dist[], bool sptSet[V])
{
	//initialize min value
	int minD = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	{

		if (!sptSet[v] && minD >= dist[v])
		{
			min_index = v;
			minD = dist[v];
		}
	}
	return min_index;
}

//A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
	 printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

//Function that implements Dijkstra's single source shortest path algorithm
//for a graph represented using adjacency matrix representation

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // the output array, dist[i] will hold the shortest path
				 //distance from src to i

	bool sptSet[V]; //sptSet[i] will be true if vertex i is included in shortest
					//path tree or shortest distance from src to i is finalized

	//Initialize all distances 
	for (int v = 0; v < V; v++)
	{
		dist[v] = INT_MAX;
		sptSet[v] = false;
	}

	//distance of source vertex from itself is always 0
	dist[src] = 0;

	//Find shortest path for all vertices
	for (int count = 0; count < V-1; count++)
	{
		//Pick the minimum distance vertex from the set of vertices not yet processed.
		//u is always equal to src in the first iteration
		int u = minDistance(dist, sptSet);

		//Mark the picked vertex as processed
		sptSet[u] = true;

		//Update dist value of the adjacent vertices of the picked vertex
		for (int v = 0; v < V; v++)
		{
			//Update dist[v] only if it's not in sptSet and there is an edge from
			// u to v, and total weight of path from src to v through u is smaller than
			//current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v])
			{
				dist[v] = graph[u][v] + dist[u];
			}
		}
	}

	printSolution(dist, V);
}