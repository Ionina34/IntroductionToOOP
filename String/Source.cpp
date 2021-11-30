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
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//                              Constractor
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//                           Operators:

	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);

	//                          Methods:
	void print()const;
};

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//                              Constractor
 String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefConstract:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstractor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	/*this->size = other.size;
	this->str = other.str;*/ //Копируем указатель на уже выделенную пямять, принадлежащую другому объекту.
	other.str = nullptr;   //Зануляем указатель в другом обьекте, 
						   //чтобы диструктор не смог удалить память, которая ему принадлежит.
	other.size = 0;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	this->str = nullptr;
	this->size = 0;
	cout << "Destroctor:\t" << this << endl;
}

//                           Operators:

String& String::operator=(const String& other)
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
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size = 0;
	cout << "MoveAssighment:\t" << this << endl;
}
String& String::operator+=(const String& other)
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
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//                          Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

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