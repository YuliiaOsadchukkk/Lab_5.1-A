//Progression.h
#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "MyException.h"
#include "MyDerivedException.h"

using namespace std;

class Progression
{
private:
    float first;
    float second;

public:
	Progression();
	Progression(int first, double second) throw(invalid_argument);///////
	Progression(const Progression& v);

	int GetFirst() const { return first; }
	double GetSecond() const { return second; }
	void SetFirst(int value) throw(invalid_argument);///////
	void SetSecond(double value) throw(MyException);///////

	Progression& operator = (const Progression& r);
	operator string() const;

	Progression& operator --() throw(out_of_range);///////
	Progression& operator ++();
	Progression operator --(int) throw(MyDerivedException);///////
	Progression operator ++(int);

	friend ostream& operator <<(ostream& out, const Progression& r);
	friend istream& operator >>(istream& in, Progression& r) throw(invalid_argument);///////


    float  elementJ(const unsigned int& j) const;
};
