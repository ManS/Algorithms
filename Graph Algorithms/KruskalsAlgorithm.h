// Kruskal's algortihm to find Minimum Spanning Tree of a given connected,
// undirected and weighted graph

/* O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. 
After sorting, we iterate through all edges and apply find-union algorithm. 
The find and union operations can take atmost O(LogV) time. 
So overall complexity is O(ELogE + ELogV) time. The value of E can be atmost V^2, 
so O(LogV) are O(LogE) same. Therefore, overall time complexity is O(ElogE) or O(ElogV)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Union-Find.h"


//Compare two edges according to their weights
//Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*) a;
	struct Edge* b1 = (struct Edge*) b;

	return a1->weight > b1->weight;
}


//The main function to construct MST using Kruskal's algorithm
void KruskalsMST(struct Graph* graph)
{

	int V = graph->V;
	struct Edge* result = new Edge[V];//This will store the resultant MST
	int e =0;//index variable used for result[]
	int i =0;//index variable used for sorted edges

	//Step 1: Sort all edges in non-decreasing order of their weight
	//IF we are not allowed to change the given graph, we can create a copy of array of edges

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

	//Allocate memory for creating V subsets
	struct subset* subsets = new subset[V];

	//Create V subsets with single elements
	for (int i = 0; i < V; i++)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}

	//Number of edges to be taken is equal to V-1
	while (e < V-1)
	{
		//Step 2: Pick the smallest edge. And increment the index i
		//for the next iteration
		struct Edge next_edge  = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);


		//If including this edge doesn't cause cycle, include it
		//in  result[] and increment the index e for the next edge
		if (x!=y)
		{
			result[e++] = next_edge;
			Union(subsets,x,y);
		}
		//Else discard the next_Edge

	}

	 // print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
   

	delete subsets;
	delete result;
	return;
}