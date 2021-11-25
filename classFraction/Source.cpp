#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);//прототип функции *
//Прототип функции - это объявление функции 

class Fraction
{
	int integer; //Целая часть
	int numerator;//Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const
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
	void set_integer(int integer)
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

	//                               Constractor:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstractor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstractor:\t" << this << endl;
	}
	Fraction(double chislo)
	{
		this->integer =(int)chislo;
		double a = chislo - (int)chislo;
		int i = 0;
		while (a > 0)
		{
			a =a*10 - (int)(a*10);
			i++;
		}
		this->numerator =(chislo - (int)chislo) * pow(10, i);
		this->denominator = pow(10, i);
		this->reduce();
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

	//                           Increment/Decrement:
	Fraction operator++()
	{
		/*if (integer)
		{
			integer++;
		}
		else
		{
			numerator += denominator;
			integer = numerator / denominator;
			numerator %= denominator;
		}
		return *this;*/
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		/*Fraction old=*this;
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
		return old;*/
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction operator--()
	{
		/*if (integer)
		{
			integer--;
		}
		else
		{
			numerator -= denominator;
		}
		return *this;*/
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		/*Fraction old = *this;
		if (integer)
		{
			integer--;
		}
		else
		{
			numerator -= denominator;
		}
		return old;*/
		Fraction old = *this;
		integer--;
		return old;
	}

	//                          Type-cast operstors:
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return  (double)numerator / denominator + integer;
	}

	//                            Operators:
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
	Fraction& operator*=(const Fraction& other)
	{
		/*this->numerator = this->integer * this->denominator + this->numerator;
		other.numerator = other.integer * other.denominator + other.numerator;
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		this->integer = this->numerator / this->denominator;
		this->numerator %= this->denominator;
		return *this;*/
		return *this = *this * other;
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


	//                             Methods:
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
	Fraction& reduce()
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
istream& operator>>(istream& is,  Fraction& obj)
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

bool operator==(Fraction left,  Fraction right)
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
bool operator!=(const Fraction left,const Fraction right)
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
bool operator>=(const Fraction left,const Fraction right)
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
bool operator<=(const Fraction left,const Fraction right)
{
	return !(left > right);
}

//#define CONSTRACTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define ISTREAM_OPERATOR_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TYPES_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER_TYPES
//#define REDUCE_CHECK

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

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);

	/*Fraction C = A * B;
	C.print();

	C = A / B;
	C.print();*/

	A *= B;
	A = B++;
	/*A.print();
	B.print();*/
	cout << A << endl;
	cout << B << endl;
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef ISTREAM_OPERATOR_CHECK
	Fraction A;// (2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // ISTREAM_OPERATOR_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(2, 1, 2);
	Fraction B(2, 5, 10);
	cout << "\n---------------------------------------------------\n";
	cout << (A >= B) << endl;
	cout << "\n---------------------------------------------------\n";
#endif // COMPARISON_OPERATORS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	int a = a;       //No conversion
	double b = 3;    //Conversion from less to more(от меньшего к большему)
	int c = b;       //Conversion from more to less without data loss(без потери данных)
	int d = 8.3;     //Conversion from more to less with data loss(с потерей данных)
	int e = a + b;   //2 Conversions in both directions
					 //2 преобразования в обоих направлениях  
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSION_FROM_OTHER_TYPES_TO_CLASS
	double a = 2;                  //Conversion from int to double(from less to more)
	cout << a << endl;
	Fraction A = (Fraction)5;      //Conversion from int to Fraction()
	cout << A << endl;
	Fraction B;
	cout << "\n----------------------------------------------\n";
	B = Fraction(8);               //operator=(CopyAssignment)
	cout << "\n----------------------------------------------\n";
	cout << B << endl;
	//Fraction C = 12;             //explicit-конструктор не возможно вызвать так
	Fraction C(12);                //его можно вызвать только так  
#endif // CONVERSION_FROM_OTHER_TYPES_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER_TYPES
	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
	//double b = A;  без explicit
	double b = (double)A;
	//Fraction - простая дробь
	//double - десятичная дробь
	cout << b << endl;
	int c = int(A);
	cout << c << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER_TYPES

#ifdef REDUCE_CHECK
	Fraction A(2, 5, 10);
	cout << A.reduce() << endl;
	cout << Fraction(840, 3600).reduce() << endl;
#endif // REDUCE_CHECK

	Fraction A = 2.75;
	cout << A << endl;
}