#include<iostream>
using namespace std;

class Fraction
{
	int integer; //Целая часть
	int numerator;//Числитель
	int denominator;//Знаменатель
public:
	int het_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int inteder)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//                          Constractor:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstractor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstractor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constractor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//                           Increment/Decrement
	Fraction operator++()
	{
		if (integer)
		{
			integer++;
		}
		else
		{
			numerator += denominator;
			integer = numerator / denominator;
			numerator %= denominator;
		}
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old;
		if (integer)
		{
		  integer++;
		}
		else
		{
			numerator += denominator;
			integer = numerator / denominator;
			numerator %= denominator;
		}
		return old;
	}
	Fraction operator--()
	{
		if (integer)
		{
			integer--;
		}
		else
		{
			numerator -= denominator;
		}
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old;
		if (integer)
		{
			integer--;
		}
		else
		{
			numerator -= denominator;
		}
		return old;
	}

	//                            Operator:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(Fraction& other)
	{
		if (this->denominator != other.denominator)
		{
			this->numerator= this->numerator* other.denominator;
			other.numerator=this->denominator * other.numerator;
			this->numerator += other.numerator;
			this->denominator *= other.denominator;
			other.integer += this->integer;
			this->integer = this->numerator / this->denominator+other.integer;
			this->numerator %= this->denominator;
		}
		else
		{
			this->numerator += other.numerator;
			this->denominator = other.denominator;
			other.integer += this->integer;
			this->integer = this->numerator / this->denominator + other.integer;
			this->numerator %= this->denominator;
		}
		return *this;
	}
	Fraction& operator-=(Fraction& other)
	{
		if (this->denominator != other.denominator)
		{
			this->numerator = this->numerator * other.denominator;
			other.numerator = this->denominator * other.numerator;
			this->numerator -= other.numerator;
			this->denominator *= other.denominator;
			other.integer-=this->integer;
			this->integer = (this->numerator / this->denominator + other.integer)*-1;
			this->numerator %= this->denominator;
		}
		else
		{
			this->numerator -= other.numerator;
			this->denominator = other.denominator;
			other.integer -= this->integer;
			this->integer = (this->numerator / this->denominator + other.integer)*-1;
			this->numerator %= this->denominator;
		}
		return *this;
	}
	Fraction& operator*=( Fraction& other)
	{
		this->numerator = this->integer * this->denominator + this->numerator;
		other.numerator = other.integer * other.denominator + other.numerator;
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		this->integer = this->numerator / this->denominator;
		this->numerator %= this->denominator;
		return *this;
	}
	Fraction& operator/=(Fraction& other)
	{
		this->numerator = this->integer * this->denominator + this->numerator;
		other.numerator = other.integer * other.denominator + other.numerator;
		this->numerator *= other.denominator;
		this->denominator *= other.numerator;
		this->integer = this->numerator / this->denominator;
		this->numerator %= this->denominator;
		return *this;
	}


	//                            Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator+(Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator())
	{
		return Fraction
		(
		left.get_numerator()*right.get_denominator()+right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
		).to_proper();
	}
	else
	{
		return Fraction
		(
			left.get_numerator() + right.get_numerator(),
			left.get_denominator()
		).to_proper();
	}
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator())
	{
		return Fraction
		(
			left.get_numerator() * right.get_denominator() - left.get_denominator() * right.get_numerator(),
			left.get_denominator()*right.get_denominator()
		).to_proper();
	}
	else
	{
		return Fraction
		(
			left.get_numerator()  -  right.get_numerator(),
			left.get_denominator()
		).to_proper();
	}
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/

	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
//#define CONSTRACTORS_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef CONSTRACTORS_CHECK
	Fraction A;        //Default constractor
	A.print();

	double b = 3;
	Fraction B = 5;    //Single-argument constractor
	B.print();

	Fraction C(3, 4);
	C.print();

	Fraction D(4, 3, 4);
	D.print();
#endif // CONSTRACTORS_CHECK

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();

	/*C = A / B;
	C.print();*/

	A-- ;
	A.print();
	
}
