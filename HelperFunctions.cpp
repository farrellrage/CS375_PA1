//------------------------------------------------------------------------------
//File Name:        HelperFunctions.cpp
//Associated file:  HelperFunctions.h
//Functions:
//      PrintDivider
//      PrintCenteredMessage
//		max
//------------------------------------------------------------------------------

#include "HelperFunctions.h"

//------------------------------------------------------------------------------
//PrintDivider: Outputs a divider line to a designated location
//--------------------------------------
//	fout:
//		Output file stream object that sends output to the opened output file
//	length:
//		Length that the divider will be printed as
//	character:
//		Character that the divider will be consisted of
//------------------------------------------------------------------------------
void PrintDivider(ofstream& fout, int length, char character)
{
	// Output a divider line to the specified destination
	fout << setw(length) << setfill(character) << character << setfill(' ') << endl;
} // !PrintDivider

//------------------------------------------------------------------------------
//PrintCenteredMessage: Outputs a centered message to a designated location
//--------------------------------------
//	fout:
//		Output file stream object that sends output to the opened output file
//	message:
//		String message that will be centered on the given width
//	centerWidth:
//		Width that the given message will be centered over
//------------------------------------------------------------------------------
void PrintCenteredMessage(ofstream& fout, string message, int centerWidth)
{
	//Holds the value that will center the given message on the given width
	int centerOfScreen;

	// Calculate the center of the screen for the message
	centerOfScreen = static_cast<int>((centerWidth + message.length()) / 2);

	// Output the centered message to the specified destination
	fout << right << setw(centerOfScreen) << message << endl;
} // !PrintCenteredMessage

//------------------------------------------------------------------------------
//max: If a is greater than b then return a, else return b
//--------------------------------------
//	a:
//		First value that will be compared by
//	b:
//		Second value that will be compared to
//------------------------------------------------------------------------------
int max(int a, int b)
{
	return (a > b) ? a : b;
} // !max