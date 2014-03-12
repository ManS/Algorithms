#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//Bellman-ford algorithm
struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	//V-> number of vertices
	//E-> number of edges
	int V,E;
	//array of edges
	struct Edge* edge;
};

//Create graph with V verticies and E edges.
struct Graph* CreateGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
	graph->E = E;
	graph->V = V;


	graph->edge = (struct Edge*) malloc( graph->E * sizeof(struct Edge));

	return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
	printf("Vertex distance from source\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d \t\t %d\n",i,dist[i]);
	}
}

//main function that finds shortest distances from src to all other
//vertices using bellman-ford algorithm. the function also detects negative
//weight cycles

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;

	int* dist = (int*) malloc(sizeof(int));

	//Step 1: Initailization
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[src] = 0;

	//Step 2: Relax all edges |V|-1 times. A simple shortest path from src to any
	// other vertex can at-most |V|-1 edges.
	for (int i = 0; i <= V-1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] + weight < dist[v])
			{
				dist[v] = weight + dist[u];
			}
		}
	}

	//Step 3: check for negative-weight cycles. the above step guarantees shortest distances
	// if graph doesn't contain negative weight cycles.
	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] + weight < dist[v])
		{
			printf("Graph contains negative weight cycles");
		}
	}

	printArr(dist,V);

	return;
}


