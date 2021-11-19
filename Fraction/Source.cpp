#include<iostream>
using namespace std;

class Fraction
{
	int h; //Числитель
	int z; //Знаменатель 
public:
	int get_h()const
	{
		return h;
	}
	int get_z()const
	{
		return z;
	}
	void set_h(int h)
	{
		this->h = h;
	}
	void set_z(int z)
	{
		this->z = z;
	}

	//                                  Constructors
	Fraction(int h = 0, int z = 0)
	{
		this->h = h;
		this->z = z;

		/*int NOD;
		for (int i = 0; i < h; i++)
		{
			if (h % i == 0 && z % i == 0)
			{
				NOD = i;
			}
		}

		int NOK;
		for (int i = 0; i < h * z; i++)
		{
			if (i % h == 0 && i % z == 0)
			{
				NOK = i;
				break;
			}
			else continue;
		}*/
		
		//cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->h = other.h;
		this->z = other.z;
		//cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		//cout << "Destructor:\t" << this << endl;
	}

	//                                    Operator

	Fraction& operator=(const Fraction& other)
	{
		this->h = other.h;
		this->z = other.z;
		//cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(Fraction& other)
	{
		if (this->z != other.z)
		{
			this->h = (this->h * other.z);
			other.h = (other.h * this->z);
			this->h += other.h;
			this->z *= other.z;
		}
		else
		{
			this->h += other.h;
			this->z = other.z;
		}
		return *this;
	}
	Fraction& operator-=(Fraction& other)
	{
		if (this->z != other.z)
		{
			this->h = (this->h * other.z);
			other.h = (other.h * this->z);
			this->h -= other.h;
			this->z *= other.z;
		}
		else
		{
			this->h -= other.h;
			this->z = other.z;
		}
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		this->h *= other.h;
		this->z *= other.z;
		return *this;
	}

	//                                 Increment/Decrement
	Fraction& operator++()
	{
		h += z;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction old;
		h += z;
		return old;
	}
	Fraction& operator--()
	{
		h -= z;
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction old;
		h -= z;
		return old;
	}

	//                                       Methods
	void print()const
	{
		cout <<  h << "/" << z << endl;
	}
};
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	if (left.get_z() != right.get_z())
	{
		result.set_h(left.get_h() * right.get_z() + right.get_h() * left.get_z());
		result.set_z(left.get_z() * right.get_z());
	}
	else
	{
		result.set_h(left.get_h() + right.get_h());
		result.set_z(left.get_z());
	}
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	if (left.get_z() != right.get_z())
	{
		result.set_h(left.get_h() * right.get_z() - right.get_h() * left.get_z());
		result.set_z(left.get_z() * right.get_z());
	}
	else
	{
		result.set_h(left.get_h() - right.get_h());
		result.set_z(left.get_z());
	}
	return result;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_h(left.get_h() * right.get_h());
	result.set_z(left.get_z() * right.get_z());
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_h(left.get_h() * right.get_z());
	result.set_z(left.get_z() * right.get_h());
	return result;
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	os << "Простая дробь: " << obj.get_h() << "/" << obj.get_z();
	return os;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	Fraction A(2, 3);
	Fraction B(3, 0);
	A.print();
	B.print();

	/*(A + B).print();
	(A - B).print();
	(A * B).print();
	(A / B).print();*/
	A++;
	A.print();
}