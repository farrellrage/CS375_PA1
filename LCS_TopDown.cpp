#include "LCS_TopDown.h"

//------------------------------------------------------------------------------
//LCSTopDownMemoization: 
//--------------------------------------
//	X:
//		Pointer to a char array holding the first sequence that will be
//		processed for subsequences
//	Y:
//		Pointer to a char array holding the second sequence that will be
//		processed for subsequences
//	xLength:
//		Integer current length of the first sequence, changes as different
//		prefixes of the sequence are considered
//	yLength:
//		Integer current length of the second sequence, changes as different
//		prefixes of the sequence are considered
//	lengthTable:
//		2-dimensional vector of integers that holds the lengths of longest
//		common subsequences between two sequences
//------------------------------------------------------------------------------
void LCSTopDownMemoization(const char *X, const char *Y, int xLength,
	int yLength, vector<vector<int>>& lengthTable)
{
	//Determine whether the recursion has reached the first row or column
	if ((xLength == 0) || (yLength == 0))
	{
		//Set the value in the table in the first row or column to 0
		lengthTable[xLength][yLength] = 0;
	} // !if
	//Determine whether the current characters in the character sequences match
	else if (X[xLength - 1] == Y[yLength - 1])
	{
		//Solve the subproblem at the top-left diagonal table position
		LCSTopDownMemoization(X, Y, (xLength - 1), (yLength - 1), lengthTable);
		
		//The value at the current position in the table is the length of the
		//LCS at the top-left diagonal to the current position plus 1
		lengthTable[xLength][yLength] =
			(lengthTable[xLength - 1][yLength - 1] + 1);
	} // !else if
	else
	{
		//Solve the subproblem in the previous row and same column of the table
		LCSTopDownMemoization(X, Y, (xLength - 1), yLength, lengthTable);
		
		//Solve the subproblem in the same row and previous column of the table
		LCSTopDownMemoization(X, Y, xLength, (yLength - 1), lengthTable);
		
		//The value at the current position in the table is the max between the
		//LCS at the previous row and same column and at the same row and
		//previous column
		lengthTable[xLength][yLength] = max(
			lengthTable[xLength - 1][yLength],
			lengthTable[xLength][yLength - 1]);
	} // !else
} // !LCSTopDownMemoization
