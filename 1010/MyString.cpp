#include "MyString.h"
#include <string>
#include <iostream>

using namespace std;

MyString::MyString()
{
}

MyString::MyString(const char* str)
{
	int i = 0;
	while (str[i] != '\0') i++;
	string_content = new char[i+1];
	for (int j = 0; j < i; i++) {
		string_content[j] = str[j];
	}
	string_length = i;
	memory_capacity = i;
}

MyString::MyString(const MyString& str)
{
	int i = 0;
	while (str.string_content[i] != '\0') i++;
	string_content = new char[i+1];
	for (int j = 0; j < i; i++) {
		string_content[j] = str.string_content[j];
	}
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
}

MyString::~MyString()
{
	delete[] string_content;
}

void MyString::setString(const char* str)
{
	int len = strlen(str);

	
	string_length = len;
	if (memory_capacity < len) {
		
		for (int i = 0; i < len; i++) {
			string_content[i] = str[i];
		}
		reserve(len);
	}
	else {
		string_content = new char[len + 1];
		for (int i = 0; i < len; i++) {
			string_content[i] = str[i];
		}
	}
}

MyString MyString::getMyString() const
{
	return *this;
}

char* MyString::getString() const
{
	return this->string_content;
}

int MyString::length() const
{
	return this->string_length;
}

int MyString::capacity() const
{
	return this->memory_capacity;
}

void MyString::reserve(int size)
{
	memory_capacity = size;
	char* newstr = new char[size+1];
	for (int i = 0; i < string_length; i++) {
		newstr[i] = string_content[i];
	}
	for (int i = string_length; i < size; i++) {
		newstr[i] = 0;
	}
	string_content = new char[size+1];
	for (int i = 0; i < size; i++) {
		string_content[i] = newstr[i];
	}

	delete[] newstr;
}

void MyString::println() const
{
	for (int i = 0; i < string_length; i++) {
		cout << string_content[i];
	}
	cout << endl;
}

MyString& MyString::assign(const MyString& str)
{
	if (str.string_length+ length() > this->capacity()) {
		this->memory_capacity += str.memory_capacity;
	}
	string_length += str.string_length;
	return *this;
}

MyString& MyString::assign(const char* str)
{
	if (string_length > memory_capacity) {
		memory_capacity += strlen(str);
	}
	return *this;
}

char MyString::at(int i) const
{
	return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str)
{
	int totallen = string_length + str.string_length;
	int len = str.string_length;
	if (memory_capacity < totallen) {
		reserve(totallen);
	}
	string_length = totallen;
	char* mytemp = new char[totallen+1];
	int j = loc + len;
	for (int i = j; i < totallen; i++) {
		string_content[i] = string_content[i - len];
	} // save char after location
	
	for (int i = loc; i < len+loc; i++) {
		string_content[i] = str.string_content[i-loc];
	}//save new string
	return *this;
}

MyString& MyString::insert(int loc, const char* str)
{
	int totallen = string_length + strlen(str);
	int len = strlen(str);
	if (memory_capacity < totallen) {
		reserve(totallen);
	}
	string_length = totallen;
	char* mytemp = new char[totallen + 1];
	int j = loc + len;
	for (int i = j; i < totallen; i++) {
		string_content[i] = string_content[i - len];
	} // save char after location

	for (int i = loc; i < len + loc; i++) {
		string_content[i] = str[i - loc];
	}//save new string
	return *this;
}

int MyString::find(int find_from, const MyString& str) const
{
	for (int i = 0; i < string_length; i++) {
		if (str.string_content[find_from] == string_content[i]) {
			return i;
		}
	}
	return -1;
}

int MyString::find(int find_from, const char* str) const
{
	for (int i = 0; i < string_length; i++) {
		if (str[find_from] == string_content[i]) {
			return i;
		}
	}
	return -1;
}

MyString& MyString::erase(int loc, int num)
{
	for (int i = 0; i < string_length; i++) {
		if (loc + i + num > string_length) break;
		string_content[loc + i] = string_content[loc + num + i];
	}
	string_length -= num;
	return *this;
}

int main() {
	MyString str1("I love this long long string");
	MyString str2("<some string inserted betweend>");
	MyString str3(str1);
	str1.reserve(30);

	cout << "str1" << endl;
	cout << "용량 : " << str1.capacity() << endl;
	cout << "길이 : " << str1.length() << endl;
	cout << "5th char : " << str1.at(5) << endl;
	str1.println();
	cout << endl;

	cout << "str2" << endl;
	cout << "str2" << endl;
	cout << "용량 : " << str2.capacity() << endl;
	cout << "길이 : " << str2.length() << endl;
	cout << "5th char :" << str2.at(5) << endl;
	str2.println();
	cout << endl;

	str1.insert(5, str2);
	str1.erase(0, 3);
	cout << "after insertion" << endl;
	cout << "용량 : " << str3.capacity() << endl;
	cout << "길이 : " << str3.length() << endl;
	str3.println();
	cout << endl;

	MyString str4;
	str4.setString("this is a very very long string");
	str4.println();
	cout << "find word in str4" << endl;
	cout << "find 1th <vert> in the str4 " 
		<< str4.find(0,"very") << endl;
	cout << "find 2th <vert> in the str4 "
		<< str4.find(str4.find(0,"very")+1, "very") << endl;
	cout << "길이 : " << str4.length() << endl;
	cout << "5th char :" << str4.at(5) << endl;
	cout << endl;
}