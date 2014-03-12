#include <iostream>
#include <string>

using namespace std;

// Number of vertices in the graph
#define V 5

void printSolution(int path[]);

/* A utility function to check if the vertex v can be added at index 'pos'
   in the Hamiltonian Cycle constructed so far (stored in 'path[]') */
bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
	//check if this vertex is an adjacent vertex of the previously added vertex.
	if (!graph[path[pos-1]][v])
	{
		return false;
	}

	//check if the vertex has already been included. 
	//this step can be optimized by creating an array of size V
	for (int i = 0; i < pos; i++)
	{
		if (path[i] == v)
		{
			return false;
		}
	}

	return true;
}

/* A recursive utility function to solve hamiltonian cycle problem */
bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
	/* base case: If all vertices are included in Hamiltonian Cycle */
	if (pos == V)
	{
		// And if there is an edge from the last included vertex to the
        // first vertex
		if (graph[path[pos-1]][path[0]])
		{
			return true;
		}
		else
			return false;
	}
	
	// Try different vertices as a next candidate in Hamiltonian Cycle.
    // We don't try for 0 as we included 0 as starting point in in hamCycle()

	for (int v = 1; v < V; v++)
	{
		 /* Check if this vertex can be added to Hamiltonian Cycle */
		if (isSafe(v,graph,path,pos))
		{
			path[pos] = v;

			//recur to construct rest of the path
			if (hamCycleUtil(graph,path,pos+1))
			{
				return true;
			}

			//if adding vertex v doesn't lead to a solution, then remove it
			path[pos] = -1;
		}

	}

	return false;
}

/*
  This function solves the Hamiltonian Cycle problem using Backtracking.
  It mainly uses hamCycleUtil() to solve the problem. It returns false
  if there is no Hamiltonian Cycle possible, otherwise return true and
  prints the path. Please note that there may be more than one solutions,
  this function prints one of the feasible solutions.
*/
bool hamCycle(bool graph[V][V])
{
	int* path = new int[V];
	for (int i = 0; i < V; i++)
	{
		path[i] =-1;
	}

	//let us put vertex 0 as the first vertex in the path. If there is a hamiltonian cycle, the
	//the path can be started from any point 
	path[0] =0;
	if (!hamCycleUtil(graph,path,1))
	{
		printf("\nSolution does not exist");
        return false;
	}
	printSolution(path);
    return true;
}

/* A utility function to print solution */
void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
 
    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}

//==================================================================================================================

/*
How do you implement a function to check whether there is a path for a string in a matrix of 
characters? It moves to left, right, up, and down in a matrix, and a cell for a step. The path can start from any cell 
in a matrix. If a cell is occupied by a character of a string on the path, it cannot be occupied by another character 
again. 
*/
bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited)
{
	if(str[pathLength] == '\0')//was able to reach the end of the str A.K.A found a path.
		return true;

	bool hasPath = false;
	if(row >=0 && row<rows && col>=0 && col<cols &&
		matrix[row*cols + col] == str[pathLength]&&
		!visited[row*cols + col])
	{
		++pathLength;
		visited[row*cols + col] = true;
		hasPath = hasPathCore(matrix,rows,cols, row+1, col, str, pathLength, visited) 
				||hasPathCore(matrix,rows,cols, row-1, col, str, pathLength, visited)
				||hasPathCore(matrix,rows,cols, row, col+1, str, pathLength, visited)
				||hasPathCore(matrix,rows,cols, row, col-1, str, pathLength, visited);
	}

	return hasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if(matrix == NULL || rows <1 || cols <1 || str == NULL)
		return false;
	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	int pathLength = 0;
	for(int row = 0; row < rows; row++)
		for(int col =0; col < cols; col++)
			if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				return true;
	delete visited;
	return false;
}

/*
A robot starts at cell (0, 0) of a grid with m rows and n columns. It can move to the left, right, 
up, and down, and moves one cell for a step. It cannot enter cells where the digit sum of the row index and 
column index are greater than a given k. 
For example, when k is 18, the robot can reach cell (35, 37) because 3+5+3+7=18. However, it cannot reach cell 
(35, 38) because 3+5+3+8=19 and that is greater than k. How many cells can the robot reach?
*/
int getDigitsSum(int num)
{
	int sum =0;
	while(num > 1)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}
bool check(int rows, int cols, int threshold, int row, int col, bool* visited)
{
	return (row< rows && row>=0 && col < cols && col >=0 && !visited[row*cols+col]
			&& getDigitsSum(row) + getDigitsSum(col) <=threshold);
}

int movingCountCore(int rows, int cols, int threshold, int row, int col, bool* visited)
{
	int count =0;
	if(check(rows,cols,threshold,row,col,visited))
	{
		visited[row*cols+col] = true;
		count = 1 + movingCountCore(rows,cols,threshold, row, col+1, visited)
				  + movingCountCore(rows,cols,threshold, row+1, col, visited)
				  + movingCountCore(rows,cols,threshold, row-1, col, visited)
				  + movingCountCore(rows,cols,threshold, row, col-1, visited);
	}
	return count;
}
int movingCount(int rows, int cols, int threshold)
{
	if(rows<1||cols<1||threshold<1)
		return 0;
	bool* visited = new bool[cols*rows];
	memset(visited,false,cols*rows);

	int count = movingCountCore(rows,cols,threshold,0,0,visited);

	return count;
}


