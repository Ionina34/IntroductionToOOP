#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String;
String operator+(const String left, const String& right);

class String
{
	int size;      //Размер строки в Байтах
	char* str;     //Указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//                              Constractor
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstract:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;//Считаем размер строки
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstractor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destroctor:\t" << this << endl;
	}

	//                           Operators:

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstractor:" << this << endl;
		return *this;
	}
	String& operator+=( String& other)
	{
		/*for (int i = 0; i < other.size; i++)
		{
			this->str[size] + str[i];
		}
		return *this;*/

		/*this->str[size] + other.str[size];
		return *this;*/

		return *this = *this + other;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//                          Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;

}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRACTORS_CHECK

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

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;  //Неявно вызываем оператор + 
	cout << str3 << endl;
	cout << operator+(str1, str2) << endl;  //Явный вызов оператора+
	str1 += str2;
	cout << str1 << endl;
}