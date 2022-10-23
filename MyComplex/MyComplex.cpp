#include <iostream>
#include <iomanip>
#include"MyComplex.h"

using namespace std;

/******************************************************************************
* Function Title: MyComplex
*
* Summary: This is the constructor for the MyComplex class
*
* Inputs: 2 floats for the real part and imaginary part
* Outputs: none
* *****************************************************************************
* Pseudocode
*
* BEGIN
* set x equal to the real part
* set y equal to the imaginary part
* END
******************************************************************************/

MyComplex::MyComplex(float x, float y)
{
	rp = x; //set the first provided value to the real part
	ip = y; //set the second provided value to the imaginary part
};

/******************************************************************************
* Function Title: MyComplex
*
* Summary: This is the default constructor for the MyComplex class
*
* Inputs:none
* Outputs: none
* *****************************************************************************
* Pseudocode
*
* BEGIN
* set the real part equal to 0
* set the imaginary part equal to 0
* END
******************************************************************************/

MyComplex::MyComplex()
{
	rp = 0;	//set the real part equal to 0
	ip = 0;	//set the imaginary part equal to 0
}

/******************************************************************************
* Function Title: printMyComplex
*
* Summary: This function prints out the given complex number in standard form
*
* Inputs: none
* Outputs: none
* *****************************************************************************
* Pseudocode
*
* BEGIN
* if the ip is negative
*	create float x
*	set x equal to ip times -1
*	print rp - x'i'
* else
*	print rp + ip'i'
* endif
* END
******************************************************************************/

void MyComplex::printMyComplex()
{
	cout << fixed << setprecision(1);	//make sure that results will be printed with one decimal place

	if (ip < 0)				//if the imaginary part is negative
	{
		float x = ip * -1;	//set 'x' equal to the absolute value of 'ip'

		cout << rp << " - " << x << "i" << endl;	//print the result in standard form
	}
	else
		cout << rp << " + " << ip << "i" << endl;	//print the result in standard form
}

/******************************************************************************
* Function Title: operator*
*
* Summary: defines what to do with * operator when used on MyComplex type
*
* Inputs: MyComplex object pointer
* Outputs: MyComplex object
* *****************************************************************************
* Pseudocode
*
* BEGIN
* create new MyComplex object
* set new object's rp equal to the real part using complex number multiplication
* set new object's ip equal to the imaginary part using complex number multiplication
* return the new object
* END
******************************************************************************/

MyComplex MyComplex::operator*(const MyComplex& x)
{
	MyComplex temp;							//create temporary MyComplex object

	temp.rp = (rp * x.rp) - (ip * x.ip);	//define the real part when two objects are multiplied
	temp.ip = (x.rp * ip) + (rp * x.ip);	//define the imaginary part when two objects are multiplied

	return temp;							//return the temporary object
}

/******************************************************************************
* Function Title: operator+
*
* Summary: defines what to do with + operator when used on MyComplex type
*
* Inputs: MyComplex object pointer
* Outputs: MyComplex object
* *****************************************************************************
* Pseudocode
*
* BEGIN
* create new MyComplex object
* set new object's rp equal to the addition of the two real parts
* set new object's ip equal to the addition of the two imaginary parts
* return new object
* END
******************************************************************************/

MyComplex MyComplex::operator+(const MyComplex& x)
{
	MyComplex temp;			//create temporary MyComplex object

	temp.rp = rp + x.rp;	//define the real part when two objects are added
	temp.ip = ip + x.ip;	//define the imaginary part when two objects are added

	return temp;			//return the temporary object
}

/******************************************************************************
* Function Title: operator-
*
* Summary:  defines what to do with - operator when used on MyComplex type
*
* Inputs: MyComplex object pointer
* Outputs: MyComplex object
* *****************************************************************************
* Pseudocode
*
* BEGIN
* create new MyComplex object
* set new object's rp equal to the difference of real parts
* set new object's ip equal to the difference of imaginary parts
* return new object
* END
******************************************************************************/

MyComplex MyComplex::operator-(const MyComplex& x)
{
	MyComplex temp;			//create temporary MyComplex object

	temp.rp = rp - x.rp;	//define the real part when two objects are subtracted
	temp.ip = ip - x.ip;	//define the imaginary part when two objects are subtracted

	return temp;			//return the temporary object
}