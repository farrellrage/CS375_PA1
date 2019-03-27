//------------------------------------------------------------------------------
Longest Common Subsequence
Bottom-up
Dynamic Programming
//------------------------------------------------------------------------------
This guide assumes the user has a terminal open in the program directory.
All programs use "makefile" for compilation.
//------------------------------------------------------------------------------
> To compile program 1, run the command "make task1".
> Open the files "filex.txt" and "filey.txt" to enter character sequences for
	the algorithm to process.
> NOTE: This program assumes character sequences will be provided.
	Any numbers may be converted into characters, and the output may not appear
	correct based on the input.
> To run program 1, run the command "make test1".
	This program sends all output to the file "output1.txt".
	This is where the output sets,
	lenLCS matrix, longest common subsequence, and running time
	OR
	longest common subsequence length and running time
	can be found.
//------------------------------------------------------------------------------
Other Commands:
All three programs can be compiled and executed simultaneously by running
	the command "make all".
All three programs can be compiled simultaneously by running the command
	"make tasks"
All three programs can be executed simultaneously by running the command
	"make tests"
Executables can be removed by running the command "make clean"
//------------------------------------------------------------------------------
Component Files:
Source Files:
	Task1_main.cpp
	HelperFunctions.cpp
	LCS_BottomUp.cpp
Header Files:
	Main.h
	HelperFunctions.h
	LCS_BottomUp.h
//------------------------------------------------------------------------------

Important Functions:

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
//InitializeLCSLenTable: Initializes the first row and column to 0 in the
//	longest common subsequence length table
//--------------------------------------
//	lengthTable:
//		2-dimensional vector of integers that holds the lengths of longest
//		common subsequences between two sequences
//	rows:
//		The number of rows within lengthTable
//	columns:
//		The number of columns within lengthTable
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