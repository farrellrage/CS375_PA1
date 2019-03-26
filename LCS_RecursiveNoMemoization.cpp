//------------------------------------------------------------------------------
//File Name:        LCS_RecursiveNoMemoization.cpp
//Associated file:  LCS_RecursiveNoMemoization.h
//Contains:
//      InitializeLCSLenTable
//		LCSRecursiveNoMemoization
//------------------------------------------------------------------------------

#include "LCS_RecursiveNoMemoization.h"

//------------------------------------------------------------------------------
//LCSRecursiveNoMemoization: 
//--------------------------------------
//	X:
//		Pointer to a char array holding the first sequence that will be
//		processed for subsequences
//	Y:
//		Pointer to a char array holding the second sequence that will be
//		processed for subsequences
//	tableX:
//		Integer current length of the first sequence, changes as different
//		prefixes of the sequence are considered
//	tableY:
//		Integer current length of the second sequence, changes as different
//		prefixes of the sequence are considered
//------------------------------------------------------------------------------
int LCSRecursiveNoMemoization(const char *X, const char *Y, int xLength, int yLength)
{
	//Determine whether either the x or y length is 0
	if ((xLength == 0) || (yLength == 0))
	{
		//The length of the LCS is 0
		return 0;
	} // !if
	//Determine whether the characters at the given locations in the sequence
	//are the same
	else if (X[xLength - 1] == Y[yLength - 1])
	{
		//The length of the LCS is the length of both sequences with the last
		//character in both removed
		return (LCSRecursiveNoMemoization(X, Y, (xLength - 1), (yLength - 1)) + 1);
	} // !else if
	else
	{
		//The length of the LCS is the max between the LCS length of the first
		//sequence with the last character removed and the second sequence,
		//or the first sequence and the second sequence with the last character
		//removed
		return max(LCSRecursiveNoMemoization(X, Y, (xLength - 1), yLength),
			LCSRecursiveNoMemoization(X, Y, xLength, (yLength - 1)));
	} // !else
} // !LCSRecursiveNoMemoization
