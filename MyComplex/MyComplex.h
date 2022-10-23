#ifndef COMPLEX
#define COMPLEX

#include <iostream>

using namespace std;

class MyComplex 
{
	float rp, ip;
public:
	MyComplex(float x, float y); 
	MyComplex();
	MyComplex operator* (const MyComplex&);
	MyComplex operator+ (const MyComplex&);
	MyComplex operator- (const MyComplex&);
	void printMyComplex();
};

#endif

