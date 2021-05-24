//Progression.cpp
#include "Progression.h"
#include <sstream>

using namespace std;

Progression::Progression()
	: first(0), second(0)
{}

Progression::Progression(int x, double y) throw(invalid_argument)
{
	if (!((x > 0 || x < 0) && (y > 0 || y < 0)))
		throw invalid_argument("Argument is negative");

	this->first = x;
	this->second = y;
}

Progression::Progression(const Progression& v)
{
	first = v.first;
	second = v.second;
}

void Progression::SetFirst(int value) throw (invalid_argument)
{
	if (!(value > 0 || value < 0))
		throw invalid_argument("Argument is negative");
	first = value;
}

void Progression::SetSecond(double value) throw (MyException)
{
	if (!(value > 0 || value < 0))
		throw MyException("Argument is negative");
	second = value;
}

Progression& Progression::operator = (const Progression& r)
{
	first = r.first;
	second = r.second;
	return *this;
}

Progression::operator string() const
{
	stringstream ss;
	ss << first << ", " << second;
	return ss.str();
}
ostream& operator << (ostream& out, const Progression& r)
{
	out << string(r);
	return out;
}
istream& operator >> (istream& in, Progression& r)
{
	cout << "b(0) = "; in >> r.first;
	cout << "q = "; in >> r.second;

	if (!((r.first > 0 || r.first < 0) && (r.second > 0 || r.second < 0)))
		throw invalid_argument("negative argument");

	return in;
}
Progression& Progression::operator ++()
{
	first++;
	if (!(first > -1 || first < -1))
		throw new MyDerivedException();
	return *this;
}
Progression& Progression::operator --()
{
	first--;
	if (!(first > 1 || first < 1))
		throw new MyDerivedException();
	return *this;
}
Progression Progression::operator ++(int)
{
	Progression t(*this);
	second++;
	if (!(first > -1 || first < -1))
		throw MyDerivedException();
	return t;
}
Progression Progression::operator --(int)
{
	Progression t(*this);
	second--;
	if (!(first > 1 || first < 1))
		throw MyDerivedException();
	return t;
}

float Progression::elementJ(const unsigned int& j) const
{
	return first * powf(second, j);
}
