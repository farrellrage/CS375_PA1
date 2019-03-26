//------------------------------------------------------------------------------
//File Name:        LCS_RecursiveNoMemoization.h
//Associated file:  LCS_RecursiveNoMemoization.cpp
//Contains:
//      InitializeLCSLenTable
//		LCSRecursiveNoMemoization
//------------------------------------------------------------------------------
#ifndef LCS_RecursiveNoMemoization
#define LCS_RecursiveNoMemoization

#include "Main.h"
#include "HelperFunctions.h"

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
int LCSRecursiveNoMemoization(const char *X, const char *Y, int tableX,
	int tableY);

#endif // !LCS_RecursiveNoMemoization
