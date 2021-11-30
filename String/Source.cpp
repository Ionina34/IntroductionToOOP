#include"String.h"

#define CONSTRACTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define CONSTRACTOR_CALLING

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef CONSTRACTORS_CHECK
	String str(5);           //Default Constractor
	str.print();

	String str1 = "Hello";
	str1 = str1;
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;      //CopyConstractor
	cout << str2 << endl;

	String str3;
	str3 = str2;             //CopyAssignment(operator=)
	//str3.operator=(str2);
	cout << str3 << endl;

	int a = 2;
	int b = 3;
	a = b;
	cout << a << endl;
#endif // CONSTRACTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << "\n---------------------------------------\n";
	String str3;
	str3 = str1 + str2;  //Неявно вызываем оператор + 
	cout << "\n---------------------------------------\n";
	cout << str3 << endl;
	//cout << operator+(str1, str2) << endl;  //Явный вызов оператора+
	//str1 += str2;
	//cout << str1 << endl;  
#endif // OPERATOR_PLUS_CHECK

#ifdef CONSTRACTOR_CALLING
	String str1;              //Default constractor
	cout << str1 << endl;
	String str2 = "Hello";    //Single-argument constructor
	cout << str2 << endl;
	String str3 = str2;       //Copy constructor
	cout << str3 << endl;
	str3.print();

	String str4();  //Здесь НЕ создаётся никаклй объкт, 
					//эта строка НЕ вызывает конструктор по умолчанию явным образом,
					//Здесь объявляется функция str4(), которая ничего не принимает, 
	                //и возвращает объкт класса String

   //cout << str4 << endl;
	String str5{}; //Явный вызов конструктора по умолчанию
	str5.print();
#endif // CONSTRACTOR_CALLING

}