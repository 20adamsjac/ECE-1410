#include <iostream>
#include "rational.h"
using namespace std;

/******************************************************************************
* Function Title: Main
*
* Summary:
*
* Inputs: none
* Outputs: int
*
* Compile Instructions: make
*******************************************************************************
* Pseudocode
*
* Begin
* define variables
* prompt user for numerator 
* prompt user for denominator
* if either value is zero
*	print error message and end
* endif
* simplify the fraction
* while (1)
*	display options
*	take user option
*	if option == 0
*		END
*	endif
*	try
*		if option is invalid
*			throw 	
*		endif
*	catch
*		print error
*		END
*	endtry
*	prompt for numerator
*	prompt for denominator
*	execute selection with fraction
*	print the end result
* endloop
******************************************************************************/


int main()
{
	int n, d, sel, x, y;	//variable definitions
	Rational a;				//creating new object from class Rational

	cout << "Enter numerator: ";	//ask user for a numerator
	cin >> n;						//set the numerator to int n
	cout << "Enter denominator: ";	//ask user for a denominator
	cin >> d;						//set the denominator to int d

	if (n == 0 || d == 0)			//check to see if values are illegal
	{
		cout << "Illegal value in fraction" << endl; //print error
		return 1; //end program
	}

	for (int i = d * n; i >= 1; i--)		
	{
		if ((d % i == 0) && (n % i == 0))	 //find greatest common denominator
		{
			n /= i;
			d /= i;
			a.set_n(n);			//set fraction in the object to simplified form
			a.set_d(d);
		}
	}

	cout << "Fraction reduces to " << n << "/" << d << endl << endl;	//display simplified fraction

	while (1)	//ifinite loop
	{
		x = 0;		//reset int values
		y = 0;
		sel = 0;

		cout << "1. Add a rational" << endl;		//display menu of options
		cout << "2. Subtract a rational" << endl;
		cout << "3. Multiply by a rational" << endl;
		cout << "4. Divide by a rational" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter selection: ";				//prompt for selection
		cin >> sel;									//read selection

		if (sel == 0)		//exit program if selection is 0
			return 0;

		try								
		{
			if (sel > 4 || sel < 1)		//try for any invalid selections
			{
				throw (sel);			//throw using selection as variable
			}
		}
		catch (int z)
		{
			cout << z << " is not a valid option" << endl;	//print error 
			return 1;										//end function
		}

		cout << "Enter numerator: ";	//prompt for new numerator
		cin >> x;						//save numerator as int x
		cout << "Enter denominator: ";	//prompt for new denominator
		cin >> y;						//save denominator as int y

		if (x == 0 || y == 0)				//if values in fraction are illegal
		{
			cout << "illegal value in fraction" << endl; //print error
			return 1;									//end function
		}

		switch (sel) //execute proper command based on selection 
		{
		case 1:
			a.add(x, y);
			break;
		case 2:
			a.sub(x, y);
			break;
		case 3:
			a.mul(x, y);
			break;
		case 4:
			a.div(x, y);
			break;
		default:
			break;
		}

		cout << a.get_n() << "/" << a.get_d() << endl << endl; //print end result 
	}
}
