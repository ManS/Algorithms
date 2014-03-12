//Union-Find Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//a structure to represent a subset
struct subset
{
    int parent;
    int rank;
};

//a structure to represent an edge
struct Edge
{
	int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
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

//O(n) time
//A utility function to find the subset of an element i.
int find(int parent[], int i)
{
	if (parent[i] == -1)
	{
		return i;
	}
	return find(parent,parent[i]);
}

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
	//find root and make root as parent of i (path compression).
	if (subsets[i].parent != i)
	{
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	//Attach smaller rank tree under root of high rank tree
	//(Union by Rank)
	if (subsets[xroot].rank < subsets[yroot].rank)
	{
		subsets[xroot].parent = yroot;
	}
	else if (subsets[xroot].rank > subsets[yroot].rank)
	{
		subsets[yroot].parent = xroot;
	}
	else //if ranks are equal, then make one as root and increment its rank by one
	{
		subsets[yroot].parent =xroot;
		subsets[xroot].rank++;
	}
}

//O(n) time
//A utility function to do union of two subsets.
void Union(int parent[], int x, int y)
{
	int xset = find(parent,x);
	int yset = find(parent,y);

	parent[xset] = yset;
}

//the main function to check whether a given graph contains cycle or not
int isCycle(struct Graph* graph)
{
	//Allocate memory for creating V subsets
	int* parent = (int*) malloc(graph->V * sizeof(int));

	//Initialize all subsets as single element set
	memset(parent,-1,sizeof(int)* graph->V);

	//Iterate through all edges of graph, find subset ov both
	//vertices of every edge, if both subsets are the same, then there is a cycle in the graph.
	for (int i = 0; i < graph->E; i++)
	{
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if (x==y)
		{
			free(parent);
			return 1;
		}

		Union(parent,x,y);
	}
	free(parent);
	return 0;
}

int isCycleByRankAndCompression(struct Graph* graph)
{
	int V = graph->V;
	int E = graph->E;

	//Allocate memory for creating V sets
	struct subset* subsets = (struct subset*) malloc(sizeof(struct subset)*V);

	for (int v = 0; v < V; v++)
	{
		subsets[v].rank = 0;
		subsets[v].parent = v;
	}

	//Iterate through all edges of graph, find sets of both vertices of every 
	//edge, if sets are the same, then there is cycle in graph.

	for (int e = 0; e < E; e++)
	{
		int x = find(subsets,graph->edge[e].src);
		int y = find(subsets,graph->edge[e].dest);

		if (x==y)
		{
			free(subsets);
			return 1;
		}
		Union(subsets,x,y);
	}
	free(subsets);
	return 0;
}