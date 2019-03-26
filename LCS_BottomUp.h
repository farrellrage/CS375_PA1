//------------------------------------------------------------------------------
//File Name:        LCS_BottomUp.h
//Associated file:  LCS_BottomUp.cpp
//Contains:
//      InitializeLCSLenTable
//      PrintLCS
//		LCSBottomUpCase1
//		LCSBottomUpCase2
//------------------------------------------------------------------------------
#ifndef LCS_BottomUp_h
#define LCS_BottomUp_h

#include "Main.h"
#include "HelperFunctions.h"

//------------------------------------------------------------------------------
//PrintLCS: Prints to the output file a matrix containing the lengths of longest
//	common subsequences, with the two sequences printed above and to the left
//	of the matrix
//--------------------------------------
//	X:
//		Pointer to a char array holding the first sequence that will be
//		processed for subsequences
//	Y:
//		Pointer to a char array holding the second sequence that will be
//		processed for subsequences
//	xLength:
//		Integer length of the first character sequence
//	yLength:
//		Integer length of the second character sequence
//	lengthTable:
//		2-dimensional vector of integers that holds the lengths of longest
//		common subsequences between two sequences
//	fout:
//		Output file stream object that sends output to the opened output file
//------------------------------------------------------------------------------
void PrintLCS(const char *X, const char *Y, int xLength, int yLength,
	vector<vector<int>>& lengthTable, ofstream& fout);

//------------------------------------------------------------------------------
//LCSBottomUpCase1: Finds the longest common subsequence by creating an LCS
//	length table and parsing the table from the LCS with the largest length
//	and moving through the table by following table entries corresponding to
//	where the two sequences contain the same characters
//--------------------------------------
//	X:
//		Pointer to a char array holding the first sequence that will be
//		processed for subsequences
//	Y:
//		Pointer to a char array holding the second sequence that will be
//		processed for subsequences
//	xLength:
//		Integer length of the first character sequence
//	yLength:
//		Integer length of the second character sequence
//	fout:
//		Output file stream object that sends output to the opened output file
//------------------------------------------------------------------------------
void LCSBottomUpCase1(const char *X, const char *Y, int xLength, int yLength,
	ofstream& fout);

//------------------------------------------------------------------------------
//LCSBottomUpCase2: Finds the length of the longest common subsequence between
//	the two sequences by creating an LCS length table and reading the final
//	table entry, which contains the largest length by the end of the process
//--------------------------------------
//	X:
//		Pointer to a char array holding the first sequence that will be
//		processed for subsequences
//	Y:
//		Pointer to a char array holding the second sequence that will be
//		processed for subsequences
//	xLength:
//		Integer length of the first character sequence
//	yLength:
//		Integer length of the second character sequence
//	fout:
//		Output file stream object that sends output to the opened output file
//------------------------------------------------------------------------------
void LCSBottomUpCase2(const char *X, const char *Y, int xLength, int yLength,
	ofstream& fout);

#endif // !LCS_BottomUp_h
