#include <iostream>
#include "rational.h"
using namespace std;

/******************************************************************************
* Funciton Title: add
* 
* Summary: adds a fraction to the existing object
* 
* Inputs: 2 ints for numerator and denominator
* Outputs: none
*******************************************************************************
* Pseudocode
* 
* BEGIN
* if the denominators are the same
*	add the new fraction's numerator to the existing object
* else 
*	make the fractions have equal denominators
*	add the fractions
* endif
* simplify the fraction
* END
******************************************************************************/

void Rational::add(int x, int y)
{
	if (y == d)		//if denominators are equal
		n += x;		//add x to n
	else
	{
		x *= d;		//multiply new numerator by object denominator
		d *= y;		//and object fraction by new denominator
		n *= y;
		n += x;		//add x to n
	}

	for (int i = d * n; i >= 1; i--)	//simplify the fraction
	{
		if ((d % i == 0) && (n % i == 0))
		{
			n /= i;
			d /= i;
		}
	}
}

/******************************************************************************
* Funciton Title: sub
*
* Summary: subtract a fraction from the existing object
*
* Inputs: 2 ints for numerator and denominator
* Outputs: none
*******************************************************************************
* Pseudocode
*
* BEGIN
* if the denominators are the same 
*	subtract the fractions
* else
*	make the fractions have equal denominators
*	subtract the fractions
* endif
* simplify the fraction
* END
******************************************************************************/

void Rational::sub(int x, int y)
{
	if (y == d)		//if denominators are equal
		n -= x;		//subtract x from n
	else
	{
		x *= d;		//multiply new numerator by object denominator
		d *= y;		//and object fraction by new denominator
		n *= y;
		n -= x;		//subtract x from n
	}

	for (int i = d * n; i >= 1; i--)	//simplifiy the fraction
	{
		if ((d % i == 0) && (n % i == 0))
		{
			n /= i;
			d /= i;
		}
	}
}

/******************************************************************************
* Funciton Title: mul
*
* Summary: multiplies a fraction to the existing object
*
* Inputs: 2 ints for numerator and denominator
* Outputs: none
*******************************************************************************
* Pseudocode
*
* BEGIN
* multiply numerator to numerator
* multiply denominator to denominator
* simplify the fraction
* END
******************************************************************************/

void Rational::mul(int x, int y)
{
	n *= x;		//multiply object numerator by new numerator
	d *= y;		//multiply object denominator by new denominator

	for (int i = d * n; i >= 1; i--)	//simplify the fraction
	{
		if ((d % i == 0) && (n % i == 0))
		{
			n /= i;
			d /= i;
		}
	}
}

/******************************************************************************
* Funciton Title: div
*
* Summary: divide the existing object by a fraction
*
* Inputs: 2 ints for numerator and denominator
* Outputs: none 
*******************************************************************************
* Pseudocode
*
* BEGIN
* multiply the object numerator by the denominator of the new fraction
* multiply the object denominator by the numerator of the new fraction
* simplify the fraction
* END
******************************************************************************/

void Rational::div(int x, int y)
{
	n *= y;		//multiply new denominator to object numeratorf
	d *= x;		//multiply new numerator to object denominator

	for (int i = d * n; i >= 1; i--)	//simplify the fraction
	{
		if ((d % i == 0) && (n % i == 0))
		{
			n /= i;
			d /= i;
		}
	}
}
