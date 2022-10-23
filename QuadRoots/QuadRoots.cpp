#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include "files.h"
using namespace std;

/******************************************************************************
* Function Title: main
* 
* Summary:
* 
* Inputs: int argc and char* argv[]
* Outputs: int
* 
* Compile Instructions: make
* *****************************************************************************
* Pseudocode
* 
* BEGIN
* define variables
* open input file
*	while the input file still has values
*		read the 3 from a line
*		store them as float values
*		compute the roots
*		if there is an output file assigned
*			open output file
*			if there are complex roots
*				display error 
*			print the roots to the output file
*		else 
*			print them to the screen
*	endloop
* close input file
* if there is an output file
*	close output file
* END
******************************************************************************/

int main(int argc, char* argv[])
{
	float a, b, c, root1, root2; //defining variables
	ifstream input;
	
	if (openFile(input, argv[1])) //if the input file opens
	{
		if(argv[2]) //if there is an output file
		{
			ofstream output; //create an output file type

			if (openFile(output, argv[2])) //if the output file opens
			{
				while (input >> a >> b >> c) //while the input file has 3 values for a, b and c
				{
					output << fixed << setprecision(0) << a << "\t\t" << b << "\t\t" << c << "\t\t"; //print a, b and c
					if (((b * b) - (4 * a * c)) < 0) //if the roots are complex
								output << "complex roots, did not compute" << endl;//print error
					else
						{
							root1 = ((-b - sqrt((b * b) - (4 * a * c))) / (2 * a)); //compute roots
							root2 = ((-b + sqrt((b * b) - (4 * a * c))) / (2 * a));
							output << fixed << setprecision(4) << root1 << "\t\t" << root2 << endl; //print roots
						}
				}
			}
			output.close();//close output file
		}
		else //if there is not an output file
		{
			while (input >> a >> b >> c) //while there are still values in the input file
			{
				cout << fixed << setprecision(0) << a << "\t\t" << b << "\t\t" << c << "\t\t"; //print a, b and c
				if (((b * b) - (4 * a * c)) < 0)//if the roots are complex
					cout << "complex roots, did not compute" << endl; //print error
				else
				{
					root1 = ((-b - sqrt((b * b) - (4 * a * c))) / (2 * a));//compute roots
					root2 = ((-b + sqrt((b * b) - (4 * a * c))) / (2 * a));
					cout << fixed << setprecision(4) << root1 << "\t\t" << root2 << endl;//print roots
				}
			}
		}
		input.close(); //close input file
	}
	return 0; 
}
