#include"Fraction.h"


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

	Fraction A = 2.76;
	cout << A << endl;
}