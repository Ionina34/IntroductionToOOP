#include"Fraction.h"
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

//                               Constractor:
Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{
	cout << "DefaultConstractor:\t" << this << endl;
}
Fraction::Fraction(int integer) : integer(integer), numerator(0), denominator(1)
{
	cout << "SingleArgConstractor:\t" << this << endl;
}
Fraction::Fraction(double decimal) : integer(decimal), denominator(1e+9)
{
	decimal -= integer;
	numerator = (decimal + 1e-10) * denominator;
	reduce();
}
Fraction::Fraction(int numerator, int denominator) :integer(0), numerator(numerator), denominator(denominator)
{
	cout << "Constractor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator) : integer(integer), numerator(numerator)
{
	set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) : integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}

//                           Increment/Decrement:
Fraction Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction Fraction:: operator--()
{
	integer--;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}

//                          Type-cast operstors:
Fraction:: operator int()const
{
	return integer;
}
Fraction:: operator double()const
{
	return  (double)numerator / denominator + integer;
}

//                            Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator+=(Fraction& other)
{
	if (this->denominator != other.denominator)
	{
		this->numerator = this->numerator * other.denominator;
		other.numerator = this->denominator * other.numerator;
		this->numerator += other.numerator;
		this->denominator *= other.denominator;
		other.integer += this->integer;
		this->integer = this->numerator / this->denominator + other.integer;
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
Fraction& Fraction::operator-=(Fraction& other)
{
	if (this->denominator != other.denominator)
	{
		this->numerator = this->numerator * other.denominator;
		other.numerator = this->denominator * other.numerator;
		this->numerator -= other.numerator;
		this->denominator *= other.denominator;
		other.integer -= this->integer;
		this->integer = (this->numerator / this->denominator + other.integer) * -1;
		this->numerator %= this->denominator;
	}
	else
	{
		this->numerator -= other.numerator;
		this->denominator = other.denominator;
		other.integer -= this->integer;
		this->integer = (this->numerator / this->denominator + other.integer) * -1;
		this->numerator %= this->denominator;
	}
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(Fraction& other)
{
	this->numerator = this->integer * this->denominator + this->numerator;
	other.numerator = other.integer * other.denominator + other.numerator;
	this->numerator *= other.denominator;
	this->denominator *= other.numerator;
	this->integer = this->numerator / this->denominator;
	this->numerator %= this->denominator;
	return *this;
}


//                             Methods:
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer = numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	int buffer = inverted.numerator;
	inverted.numerator = inverted.denominator;
	inverted.denominator = buffer;
	return inverted;
}
Fraction& Fraction::reduce()
{
	int more, less;
	int rest; //Остаток от деления 
	if (numerator > denominator)
	{
		more = numerator;
		less = denominator;
	}
	else
	{
		more = denominator;
		less = numerator;
	}
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;
	//GCD -Greatest Common Divisor (Наибольший общий делитель)
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()const
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


Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator())
	{
		return Fraction
		(
			left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
			left.get_denominator() * right.get_denominator()
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
			left.get_denominator() * right.get_denominator()
		).to_proper();
	}
	else
	{
		return Fraction
		(
			left.get_numerator() - right.get_numerator(),
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

ostream& operator<<(ostream& os, const Fraction obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	/*int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/

	const int SIZE = 80;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);
	//5
	//1/2
	//2(3,4)
	//2 (3/4)
	char delimiters[] = "() /"; //Разделители, по по которым мы будем делить строку
	char* number[5];  //В этом массиве будут храниться указатели на числа в buffer
	int n = 0;        //Счётчик прочитанных из строки чесел
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = pch;
	}
	switch (n)
	{
		//int atoi(char* str) - преобразует строку в целое число
	case 1:obj.set_integer(atoi(number[0])); break;
	case 2:
		obj.set_numerator(atoi(number[0]));
		obj.set_denominator(atoi(number[1]));
		break;
	case 3:
		obj.set_integer(atoi(number[0]));
		obj.set_numerator(atoi(number[1]));
		obj.set_denominator(atoi(number[2]));
	}
	return is;
}

bool operator==(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();*/
	/*if (left.get_denominator() != right.get_denominator())
	{
		int left_numerator = left.get_numerator() * right.get_denominator();
		int right_numerator = right.get_numerator() * left.get_denominator();
		int denominator = left.get_denominator() * right.get_denominator();
		if (left_numerator == right_numerator)return true;
		else return false;
	}
	else
	{
		if (left.get_numerator() == right.get_numerator())return true;
		else return false;
	}*/

	return
		left.to_improper().get_numerator() * right.get_denominator() ==
		right.to_improper().get_numerator() * left.get_denominator();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
	{
		return true;
	}
	else
	{
		return false;
	}*/
}
bool operator!=(const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator())
	{
		int left_numerator = left.get_numerator() * right.get_denominator();
		int right_numerator = right.get_numerator() * left.get_denominator();
		int denominator = left.get_denominator() * right.get_denominator();
		if ( left_numerator>right_numerator)return true;
		else return false;
	}
	else
	{
		if (left.get_numerator() > right.get_numerator())return true;
		else return false;
	}*/
	return
		left.to_improper().get_numerator() * right.get_denominator() >
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator())
	{
		int left_numerator = left.get_numerator() * right.get_denominator();
		int right_numerator = right.get_numerator() * left.get_denominator();
		int denominator = left.get_denominator() * right.get_denominator();
		if (left.get_numerator() < right.get_numerator())return true;
		else return false;
	}
	else
	{
		if (left.get_numerator() < right.get_numerator())return true;
		else return false;
	}*/
	/*return !(left > right);*/
	return
		left.to_improper().get_numerator() * right.get_denominator() <
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction left, const Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	if (left.get_denominator() != right.get_denominator())
	{
		int left_numerator = left.get_numerator() * right.get_denominator();
		int right_numerator = right.get_numerator() * left.get_denominator();
		int denominator = left.get_denominator() * right.get_denominator();
		if (left_numerator >= right_numerator)return true;
		else return false;
	}
	else
	{
		if (left.get_numerator() >= right.get_numerator())return true;
		else return false;
	}*/
	//return left > right || left == right;
	return !(left < right);
}
bool operator<=(const Fraction left, const Fraction right)
{
	return !(left > right);
}