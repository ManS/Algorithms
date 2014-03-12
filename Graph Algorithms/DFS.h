//Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.

#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;//no of vertices
	list<int> *adj;//pointer to an array contaning adjacency lists
	void DFSUtil(int v, bool visited[]);  // A function used by DFS
	bool isCyclicUtil(int v, bool visited[], bool* recStack);//used by isCyclic

public:
	Graph(int V);//constructor
	void addEdge(int v, int w);//function to add edge to the graph
	void DFS(int V);//DFS Traversal of the vertices reachable from V.
	bool isCyclic();//returns true if there is a cycle in this graph.
	int CountConnectedComponents();//counts number of connected components in the graph
};

Graph::Graph(int p_V)
{
	this->V = p_V;
	adj = new list<int>[p_V];
}

void Graph::addEdge(int p_v, int w)
{
	adj[p_v].push_back(w);
}

void Graph::DFSUtil(int v,  bool visited[])
{

	visited[v] = true;
	cout<<v<<" ";

	//recur for all the vertices adjacent to this vertex
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (!visited[*it])
		{
			DFSUtil(*it,visited);
		}
	}
}

//DFS traversal of the vertices reachable from v.
void Graph::DFS(int p_v)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	//Call the recursive helper function
	DFSUtil(p_v, visited);

	delete visited;
}

bool Graph::isCyclicUtil(int v, bool visited[], bool* recStack)
{
	if (!visited[v])
	{
		//mark the current node as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		//recur for all the vertices adjacent to this vertex
		list<int>::iterator it = adj[v].begin();
		for (;it!= adj[v].end(); it++)
		{
			if (!visited[*it] && isCyclicUtil(*it, visited, recStack))
			{
				return true;
			}
			else if (recStack[*it])
			{
				return true;
			}
		}
	}
	//remove the vertex from recursion stack
	recStack[v] = false;

	return false;
}


//returns true if the graph contains a cycle, else false.
//this function is a variation of DFS() function.
bool Graph::isCyclic()
{
	bool* visited = new bool[V];
	bool* recStack = new bool[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	//call the recursive helper function to detect cycles in different DFS Trees
	for (int i = 0; i < V; i++)
	{
		if (isCyclicUtil(i,visited,recStack))
		{
			delete visited;
			delete recStack;
			return true;
		}
	}
	delete visited;
	delete recStack;
	return false;
}

//returns the number of connected component in the graph counts 
int Graph::CountConnectedComponents()
{
	bool* visited = new bool[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	int count = 0;
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			DFSUtil(i,visited);
			count++;
		}
	}

	return count;
}