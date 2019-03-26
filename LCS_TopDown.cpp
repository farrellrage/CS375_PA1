#include "LCS_TopDown.h"


void LCSTopDownMemoization(const char *X, const char *Y, int xLength,
	int yLength, vector<vector<int>>& lengthTable)
{
	if ((xLength == 0) || (yLength == 0))
	{
		lengthTable[xLength][yLength] = 0;
	} // !if
	else if (X[xLength - 1] == Y[yLength - 1])
	{
		LCSTopDownMemoization(X, Y, (xLength - 1), (yLength - 1), lengthTable);
		
		lengthTable[xLength][yLength] =
			(lengthTable[xLength - 1][yLength - 1] + 1);
	} // !else if
	else
	{
		LCSTopDownMemoization(X, Y, (xLength - 1), yLength, lengthTable);
		
		LCSTopDownMemoization(X, Y, xLength, (yLength - 1), lengthTable);
		
		lengthTable[xLength][yLength] = max(
			lengthTable[xLength - 1][yLength],
			lengthTable[xLength][yLength - 1]);
	} // !else
} // !LCSTopDownMemoization
