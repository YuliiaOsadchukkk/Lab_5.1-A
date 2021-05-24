//Source.cpp

#include <iostream>
#include "Progression.h"
using namespace std;

void _unexpected_to_bad()
{
    cerr << "bad_exception" << endl;
    throw;
}

Progression makeProgression(const float& first, const float& second)
{
    return Progression(first, second);
}

void Call_Bad() throw(int)
{
    throw 'x';
}
//////////////////////////////////////////////////////////
int main()
{
	set_unexpected(_unexpected_to_bad);
	try
	{
		Progression A = makeProgression(3, 3);
		Progression B(2, 0);
		B = A;
		cout << A << endl;

		cout<<endl;
		B++;
		cout << B << endl << endl;
		B--;
		cout << B << endl << endl;
		++B;
		cout << B << endl << endl;
		--B;
		cout << B << endl << endl;

		cout << "size of class = " << sizeof(B) << endl;
	}
	catch (invalid_argument a)
	{
		cerr << "Exception: " << a.what() << endl << endl;
	}

	Progression C;
	try
	{
		cin >> C;
		cout << C << endl;
		cout << "elememtJ(3) = " << C.elementJ(3) << endl << endl;
		try
		{
			C--;
			C++;
			--C;
			++C;
		}
		catch (MyDerivedException* c)
		{
			cerr << c->What() << endl << endl;
		}
		catch (MyDerivedException c)
		{
			cerr << c.What() << endl << endl;
		}
	}
	catch (invalid_argument b)
	{
		cerr << "Exception: " << b.what() << endl;
	}

	try
	{
		int first;
		double second;
		cout << "b(0): "; cin >> first;
		C.SetFirst(first);
		cout << "q: "; cin >> second;
		C.SetSecond(second);
	}
	catch (invalid_argument& d)
	{
		cerr << "Exception: " << d.what() << endl;
	}
	catch (MyException d)
	{
		cerr << "Exception: " << d.What() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}

}
