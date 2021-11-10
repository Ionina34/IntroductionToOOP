#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{ return x; }
	double get_y()const
	{ return y; }
	void set_x(double x)
	{ this->x = x; }
	void set_y(double y)
	{ this->y = y; }
};

//#define STRUCT_POIN

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef STRUCT_POIN
	//type name;   //Синтаксис объявления переменной
	int a;   //Обьявление переменной 'a' типа 'int'
	Point A; // Обьявление переменной 'A' типа 'Pointer'
			 //Создание объкта 'А' структуры 'Pointer'
			 //Обьявление объекта 'А' структуры 'Pointer'
			 //Создание экземпляра 'А' структура 'Pointer'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;//Создаем (объявляем) указатель на Pointer
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POIN

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

}