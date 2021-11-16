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
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//                      Increment/Decrement
	Point& operator++() //Prefix Increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this; //Сохраняем старое значение объекта
		x++;
		y++;
		return old;
	}

	//                         Methods:

	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
		//sqrt - Square Root (Квадратный корень)
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& W, const Point& T);
double distance_2(const Point& A, const Point& B)
{
	return sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)));
}

Point operator+(const Point& left, const Point& right)
{
	Point result; //Локальный объект, в который будет сохранен результат
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
Point operator-(const Point& left, const Point& right)
{
	Point result(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X =" << obj.get_x() << "\tY = " << obj.get_y();
	return os;
}

//#define STRUCT_POIN
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK
//#define DZ_1
//#define DISTANCE_CHECK
//#define ARITHMETICAL_OPERATOR_CHECK
#define delimiter "\n-------------------------------------\n"


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

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << delimiter << endl;
	cout << "расттояние от точки а до точки в: " << A.distance(B) << endl;
	cout << delimiter << endl;;
	cout << "расттояние от точки b до точки a: " << B.distance(A) << endl;
	cout << delimiter << endl;;
	cout << "расстояние между точками а и в: " << distance_2(A, B) << endl;
	cout << delimiter << endl;;
	cout << "расстояние между точками в и а: " << distance_2(B, A) << endl;
	cout << delimiter << endl;;
#endif // DISTANCE_CHECK

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

#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << "\n----------------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n----------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGMENT_CHECK

#ifdef DZ_1
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
	//cout << "Расстояние до точки: " << distance(W,T) << endl;
	cout << "Расстояние между точками: " << distance(W, T) << endl;
#endif // DZ_1

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	A += B;
	A.print();
	B = A++;
	/*A.print();
	B.print();*/
	cout << A << endl;
	cout << B << endl;

	/*for (Point i = 0; i.get_x() < 10; i++)
	{
		i.print();
	}*/

#ifdef ARITHMETICAL_OPERATOR_CHECK
	Point C = A + B;
	C.print();
	Point D = A - B;
	D.print();
	(A * B).print();
#endif // ARITHMETICAL_OPERATOR_CHECK

}

double distance(const Point& W, const Point& T)
{
	return sqrt((W.get_x() - T.get_x()) * (W.get_x() - T.get_x()) + (W.get_y() - T.get_y()) * (W.get_y() - T.get_y()));
}
