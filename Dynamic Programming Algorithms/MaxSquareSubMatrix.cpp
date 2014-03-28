//Given a binary matrix, find out the maximum size square sub-matrix with all 1s.


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int MaxSubSquare(vector<vector<bool>> matrix)
{
	int R = matrix.size();
	if (R==0)
	{
		return 0;
	}
	int C = matrix[0].size();
	if (C == 0)
	{
		return 0;
	}

	vector<vector<int>> matrixS(R,vector<int>(C,0));
	//copy first column and first row from matrix to matrixS
	for (int i = 0; i < R; i++)
	{
		matrixS[i][0] = matrix[i][0];
	}
	for (int i = 0; i < C; i++)
	{
		matrixS[0][i] = matrix[0][i];
	}
	
	//fill the rest part of the matrixS
	int maxSize = 0;
	for (int i = 1; i < R; i++)
	{
		for (int j = 1; j < C; j++)
		{
			if (matrix[i][j])
			{
				matrixS[i][j] = min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1]))+1;
			}
			else
			{
				matrixS[i][j] = 0;
			}
			maxSize = max(maxSize,matrixS[i][j]);
		}
	}

	return maxSize;
}