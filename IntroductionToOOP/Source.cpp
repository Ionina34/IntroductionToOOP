#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	/*double distance(double x,double y)
	{
		return sqrt(this->x*this->x  + this->y *this->y);
	}*/
	double distance(const Point& W, const Point& T)
	{
		return sqrt((W.get_x() - T.get_x()) * (W.get_x() - T.get_x()) + (W.get_y() - T.get_y()) * (W.get_y() - T.get_y()));
	}


	//                       Constructors:

	//Point()
	//{
	//	x = y = double();//В обе координаты ложим значение по умолчанию для double.
	//	cout << "DefaultConstructor:\t" << this << endl;
	//}

	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArdumentConstructor : \t" << this << endl;
	}*/

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}

	Point(const Point& other)//other-другой
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}

	//                          Operators
Point operator=(const Point& other)
	{
		this->x = other.x;
	    this->y = other.y;
	  cout << "CopyAssignment:\t" << this << endl;
	  return *this;
	}

		~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//                         Methods:

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
double distance(const Point& W, const Point& T);

//#define STRUCT_POIN
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_OPERATOR


void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef STRUCT_POIN
	//type name;   //Синтаксис объявления переменной
	int a;   //Обьявление переменной 'a' типа 'int'
	Point A; // Обьявление переменной 'A' типа 'Point'
			 //Создание объкта 'А' структуры 'Point'
			 //Обьявление объекта 'А' структуры 'Point'
			 //Создание экземпляра 'А' структура 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;//Создаем (объявляем) указатель на Point
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POIN

#ifdef CONSTRUCTORS_CHECK
	cout << int() << endl; //Значение поумолчанию для int.
	Point A;  //Default constructor
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;  //Sindle-argument-constructor
	B.print();

	Point C(7);     //Sindle-argument-constructor
	C.print();

	Point D(4, 5);
	D.print();

	Point E = D;   //Copy Constructor
	E.print();

	Point F;       //Default Constructor
	F = E;         //Copy Assignment
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_OPERATOR
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << "\n----------------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n----------------------------------\n";
#endif // ASSIGMENT_OPERATOR

	int x;
	int y;
	Point T;
	Point W;
	cout << "Координаты точки: "; cin >> x >> y;
	T.set_x(x);
	T.set_y(y);
	cout << "Координаты введеной точки: "; cin >> x >> y;
	W.set_x(x);
	W.set_y(y);
	cout << "Расстояние до точки: " << distance(W, T) << endl;
	cout << "Расстояние между точками: " << distance(W, T)<<endl;
}
double distance(const Point& W, const Point& T)
{
	return sqrt((W.get_x() - T.get_x()) * (W.get_x() - T.get_x()) + (W.get_y() - T.get_y()) * (W.get_y() - T.get_y()));
}