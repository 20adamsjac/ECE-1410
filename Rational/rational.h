#ifndef RATIONAL
#define RATIONAL
using namespace std;

class Rational
{
	int n, d;
public:
	Rational() { n = 0; d = 0; }
	Rational(int x, int y) { n = x; d = y; }
	void set_n(int x) { n = x; }
	void set_d(int x) { d = x; }
	int get_n() { return n; }
	int get_d() { return d; }
	void add(int, int);
	void sub(int, int);
	void mul(int, int);
	void div(int, int);
};

#endif