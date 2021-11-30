#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);//прототип функции *
//Прототип функции - это объявление функции 
ostream& operator<<(ostream& os, const Fraction obj);

class Fraction
{
	int integer; //Целая часть
	int numerator;//Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//                               Constractor:
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//                           Increment/Decrement:
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);

	//                          Type-cast operstors:
	explicit operator int()const;
	explicit operator double()const;

	//                            Operators:
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(Fraction& other);
	Fraction& operator-=(Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(Fraction& other);

	//                             Methods:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	void print()const;
};

