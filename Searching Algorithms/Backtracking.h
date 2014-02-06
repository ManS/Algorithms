#include <iostream>
#include <string>

using namespace std;

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