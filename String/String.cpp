#include"String.h"
//////////////////////////////////////////////////////////////////
/////      CLASS DEFENITION  -   ОПРЕДЕЛЕНИЕ КЛАССА          /////
/////////////////////////////////////////////////////////////////

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
String::String(const String& other) : String(other.str)
{
	cout << "CopyConstractor:" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
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

//////////////////////////////////////////////////////////////////
/////    CLASS DEFENITION END -  КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА    /////
/////////////////////////////////////////////////////////////////