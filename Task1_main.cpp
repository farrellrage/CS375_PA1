#include "Main.h"
#include "HelperFunctions.h"
#include "LCS_BottomUp.h"

int main(int argc, char **argv)
{
	//Pointers to character arrays that will hold the two sequences to process
	const char *X;
	const char *Y;

	//Integers to hold the lengths of the two character sequences
	int lenX;
	int lenY;

	//time_point object that will hold the starting time of the algorithm
	//process
	chrono::time_point<chrono::system_clock> timeStart;

	//time_point object that will hold the ending time of the algorithm process
	chrono::time_point<chrono::system_clock> timeEnd;

	//Strings to hold the names of the two text files that contain each
	//character sequence
	string fileXName;
	string fileYName;

	//String to hold the name of the output file that all output for the first
	//task will be sent to
	string outputFileName;

	//Strings that initially hold the sequences from the input files before the
	//sequences are converted to character arrays
	string sequenceOne;
	string sequenceTwo;

	//Input file stream objects that allow the character sequences to be read
	//from the input files
	ifstream fileX;
	ifstream fileY;

	//Output file stream object that allows output to be sent to the output file
	ofstream fout;

	//Determine whether the correct number of arguments were passed to the
	//program
	if (argc != 4)
	{
		//Output an error message to the console
		cout << "Error - Invalid number of arguments" << endl
			<< "Arguments must be: " << argv[0]
			<< " <filex.txt> <filey.txt> <output1.txt>" << endl;

		return -1;
	} // !if
	
	//Open input/output files---------------------------------------------------
	//Get the file names from the program arguments
	fileXName = argv[1];
	fileYName = argv[2];
	outputFileName = argv[3];

	//Open the files
	fileX.open(fileXName);
	fileY.open(fileYName);
	fout.open(outputFileName);

	//Get sequence data---------------------------------------------------------
	//Get the sequences from the input files
	fileX >> sequenceOne;
	fileY >> sequenceTwo;

	//Get the lengths of the strings
	lenX = sequenceOne.length();
	lenY = sequenceTwo.length();

	//Convert the strings to sequences of characters
	X = sequenceOne.c_str();
	Y = sequenceTwo.c_str();

	//Output file header for task one to the output file
	PrintDivider(fout, DIVIDER_WIDTH, DIVIDER_CHAR);
	fout << "Longest Common Subsequence: Bottom-up" << endl;

	//Determine whether either input sequence is shorter or equal to 10
	//characters
	if ((lenX <= 10) && (lenY <= 10))
	{
		//Get the system time before finding the LCS
		timeStart = chrono::system_clock::now();

		//Perform case 1: output LCS length matrix and the LCS file
		LCSBottomUpCase1(X, Y, lenX, lenY, fout);

		//Get the system time after finding the LCS
		timeEnd = chrono::system_clock::now();
	} // !if
	else
	{
		//Get the system time before finding the LCS
		timeStart = chrono::system_clock::now();

		//Perform case 2: output the length of the LCS to the output file
		LCSBottomUpCase2(X, Y, lenX, lenY, fout);

		//Get the system time after finding the LCS
		timeEnd = chrono::system_clock::now();
	} // !else

	//Calculate the elapsed time as a duration data type
	chrono::duration<double> timeElapsed = timeEnd - timeStart;

	//Output the running time for finding the LCS
	fout << "Running Time: " << timeElapsed.count() << " seconds" << endl;
	PrintDivider(fout, DIVIDER_WIDTH, DIVIDER_CHAR);
	
	//Close the input and output files
	fileX.close();
	fileY.close();
	fout.close();

	return 0;
} // !main
