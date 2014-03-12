//This algorithm suitable for adjacency matrix representation of the graph
//Time Complexity of this implementation is O(V^2)
#include <stdio.h>
#include <limits.h>

//number of vertices
#define V 5

//A utility function to find the vertex with the minimum key value, from
//the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
	//Initialize min value
	int minv = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	{
		if (!mstSet[v] && key[v] < minv)
		{
			minv =key[v];
			min_index = v;
		}
	}

	return min_index;
}

//A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int n, int graph[V][V])
{
	printf("Edge    weight\n");
	for (int i = 1; i < V; i++)
	{
		printf("%d - %d      %d \n", parent[i], i, graph[i][parent[i]]);
	}

}

//Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V])
{
	int parent[V];//Array to store constructed MST
	int key[V];//Key values used to pick minimum weight edge in cut
	bool mstSet[V];//To represent set of vertices not yet included in MST

	//Initialize all keys as INFINITY
	for (int v = 0; v < V; v++)
	{
		key[v] = INT_MAX;
		mstSet[v] = false;
	}

	//Always include first list 1st vertex in MST.
	key[0] = 0;
	parent[0] = -1;

	//The MST will have V vertices
	for (int count = 0; count < V-1; count++)
	{
		//Pick the minimum key vertex from the set of vertices
		//not yet included in MST
		int u = minKey(key,mstSet);

		//Add the picked vertex to the MST set
		mstSet[u] = true;

		//Update key value and parent index of the adjacent vertices of
		//the picked vertex. Consider only those vertices which are not yet
		//included in MST
		for (int v = 0; v < V; v++)
		{
			//graph[u][v] is not zero only for adjacent vertices of u
			//mstSet[v] is false for vertices not yet included in MST
			//Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] != 0 && !mstSet[v] && key[v] > graph[u][v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

	printMST(parent,V, graph);
}
