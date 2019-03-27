#ifndef LCS_TopDown
#define LCS_TopDown

#include "Main.h"
#include "HelperFunctions.h"

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
	int yLength, vector<vector<int>>& lengthTable);

#endif // !LCS_TopDown
