//------------------------------------------------------------------------------
//File Name:        LCS_BottomUp.cpp
//Associated file:  LCS_BottomUp.h
//Functions:
//      PrintLCS
//		LCSBottomUpCase1
//		LCSBottomUpCase2
//------------------------------------------------------------------------------

#include "LCS_BottomUp.h"

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
	vector<vector<int>>& lengthTable, ofstream& fout)
{
	//Index for the FOR loops that output the two character sequences to the
	//output file
	int i;

	//Index for the FOR loop that iterates over rows in lengthTable
	int row;

	//Index for the FOR loop that iterates over columns in lengthTable
	int col;

	//Output the second sequence to the output file
	fout << "  y ";
	for (i = 0; i < yLength; i++)
	{
		fout << Y[i] << ' ';
	} // !for
	fout << endl;

	//Output the first row of the length table to the output file
	fout << "x ";
	for (i = 0; i <= yLength; i++)
	{
		fout << lengthTable[0][i] << ' ';
	} // !for
	fout << endl;

	//For each character in the first sequence
	for (row = 0; row < xLength; row++)
	{
		//Output the current character of the first sequence to the output file
		fout << X[row] << ' ' << lengthTable[row][0] << ' ';

		//For each character in the second sequence
		for (col = 0; col < yLength; col++)
		{
			//Output the current length in the table to the output file
			fout << lengthTable[row + 1][col + 1] << ' ';
		} // !for
		fout << endl;
	} // !for
} // !PrintLCS

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
	ofstream& fout)
{
	//Index for the FOR loop that iterates over rows in lengthTable
	int row = 0;

	//Index for the FOR loop that iterates over columns in lengthTable
	int col = 0;

	//2-dimensional array to LCS lengths
	vector<vector<int>> lengthTable((xLength + 1), vector<int>(yLength + 1));

	//Vector to hold LCS
	vector<char> LCS = {};

	InitializeLCSLenTable(lengthTable, xLength, yLength);
	
	//For each character in the first sequence (rows)
	for (row = 0; row < xLength; row++)
	{
		//For each character in the second sequence (columns)
		for (col = 0; col < yLength; col++)
		{
			//Case when the characters in the current position of the sequences
			//match
			if (X[row] == Y[col])
			{
				//Set the value in the current position of the table to the
				//value of the previous top-left diagonal position of the table
				//plus 1
				lengthTable[row + 1][col + 1] = (lengthTable[row][col] + 1);
			} // !else if
			else
			{
				//The value at the current position of the table is the larger of
				//the value at the last row and same column, or the same row and
				//last column
				lengthTable[row + 1][col + 1]
					= max(lengthTable[row][col + 1], lengthTable[row + 1][col]);
			} // !else
		} // !for
	} // !for

	PrintLCS(X, Y, xLength, yLength, lengthTable, fout);

	//Set the row and column indices to the max value for the two sequences
	row = (xLength - 1);
	col = (yLength - 1);

	//While the end of either sequence has not been reached
	while ((row >= 0) && (col >= 0))
	{
		//Determine whether the character at the current index for each sequence
		//matches
		if (X[row] == Y[col])
		{
			//Add the character to the LCS
			LCS.push_back(X[row]);
			
			//Decrement both sequence indices
			row--;
			col--;
		} // !if
		//Case where the LCS length above the current LCS length is larger than
		//the LCS length to the left of the current length
		else if (lengthTable[row][col + 1] > lengthTable[row + 1][col])
		{
			//Decrement the row index
			row--;
		} // !else if
		else
		{
			//Decrement the column index
			col--;
		} // !else
	} // !while
	
	//Output the LCS to the output file
	fout << "LCS: ";

	//Create vector iterator to output each LCS character
	vector<char>::iterator backIt = LCS.end();

	//While the iterator has not reached the front of the vector
	while (backIt != LCS.begin())
	{
		//Decrement the iterator first since it initially pointer to one value
		//ahead of what we want
		backIt--;

		//Output the current character
		fout << *backIt;
	} // !while
	fout << endl;

} // !LCSBottomUpCase1

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
	ofstream& fout)
{
	//Index for the FOR loop that iterates over rows in lengthTable
	int row = 0;

	//Index for the FOR loop that iterates over columns in lengthTable
	int col = 0;

	//2-dimensional array to LCS lengths
	vector<vector<int>> lengthTable((xLength + 1), vector<int>(yLength + 1));

	InitializeLCSLenTable(lengthTable, xLength, yLength);

	//For each character in the first sequence (rows)
	for (row = 0; row < xLength; row++)
	{
		//For each character in the second sequence (columns)
		for (col = 0; col < yLength; col++)
		{
			//Case when the characters in the current position of the sequences
			//match
			if (X[row] == Y[col])
			{
				//Set the value in the current position of the table to the
				//value of the previous top-left diagonal position of the table
				//plus 1
				lengthTable[row + 1][col + 1] = (lengthTable[row][col] + 1);
			} // !else if
			else
			{
				//The value at the current position of the table is the larger of
				//the value at the last row and same column, or the same row and
				//last column
				lengthTable[row + 1][col + 1] = max(lengthTable[row][col + 1], lengthTable[row + 1][col]);
			} // !else
		} // !for
	} // !for

	//Output the length of the LCS to the output file
	//The longest LCS length is held in the last position in the length table
	fout << "LCS length: "
		<< lengthTable[xLength][yLength]
		<< " characters"
		<< endl;
} // !LCSBottomUpCase2
