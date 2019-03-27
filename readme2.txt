//------------------------------------------------------------------------------
Longest Common Subsequence
Recursive
No Memoization
//------------------------------------------------------------------------------
This guide assumes the user has a terminal open in the program directory.
All programs use "makefile" for compilation.
//------------------------------------------------------------------------------
> To compile program 2, run the command "make task2".
> Open the files "filex.txt" and "filey.txt" to enter character sequences for
	the algorithm to process.
> NOTE: This program assumes character sequences will be provided.
	Any numbers may be converted into characters, and the output may not appear
	correct based on the input.
> To run program 2, run the command "make test2".
	This program sends all output to the file "output2.txt".
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
	Task2_main.cpp
	HelperFunctions.cpp
	LCS_RecursiveNoMemoization.cpp
Header Files:
	Main.h
	HelperFunctions.h
	LCS_RecursiveNoMemoization.h
//------------------------------------------------------------------------------

Important Function:

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