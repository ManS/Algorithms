//Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.


#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph
{
	int V;//no of vertices
	list<int> *adj;//pointer to an array contaning adjacency lists
public:
	Graph(int V);//constructor
	void addEdge(int v, int w);//function to add edge to the graph
	void BFS(int s);//BFS Traversal of the vertices reachable from V.
	bool isReachable(int s, int d);  // returns true if there is a path from s to d
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

void Graph::BFS(int s)
{
	bool *visited = new bool[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty())
	{
		s =q.front();
		cout<<s<< " ";
		q.pop();

		//get all adjacent vertices of the dequeued vertex s
		//If an adjacent hasn't visited, then mark it as visited and enqueue it.
		for (list<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}
	}

	delete visited;

}

//A BFS based function to check whether d is reachable from s or not.
bool Graph::isReachable(int s, int d)
{
	//Base case
	if (s==d)
	{
		return true;
	}

	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	queue<int> q;
	q.push(s);
	visited[s] = true;
	list<int>::iterator it;
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		it = adj[s].begin();
		for (; it !=adj[s].end(); it++)
		{
			if (*it == d)
			{
				delete visited;
				return true;
			}
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	delete visited;

	return false;//not reachable
}