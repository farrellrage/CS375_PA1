//------------------------------------------------------------------------------
Longest Common Subsequence
Top-down Recursive
Dynamic Programming
//------------------------------------------------------------------------------
This guide assumes the user has a terminal open in the program directory.
All programs use "makefile" for compilation.
//------------------------------------------------------------------------------
> To compile program 3, run the command "make task3".
> Open the files "filex.txt" and "filey.txt" to enter character sequences for
	the algorithm to process.
> NOTE: This program assumes character sequences will be provided.
	Any numbers may be converted into characters, and the output may not appear
	correct based on the input.
> To run program 3, run the command "make test3".
	This program sends all output to the file "output3.txt".
	This is where the longest common subsequence length and running time can be
	found.
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
	Task3_main.cpp
	HelperFunctions.cpp
	LCS_TopDown.cpp
Header Files:
	Main.h
	HelperFunctions.h
	LCS_TopDown.h
//------------------------------------------------------------------------------

Important Function:

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