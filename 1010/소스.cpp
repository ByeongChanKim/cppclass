#include "Mystring.h"
#include <iostream>
#include <string>
using namespace std;

MyString::MyString() {
	string_content = NULL;
	string_length = 0;
	memory_capacity = 0;
}//default constructor
MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length + 1];
	for (int i = 0; i < string_length; i++) {
		string_content[i] = str[i];
	}
}// ���ڿ� ������
MyString::MyString(const MyString& str) {

	string_length = str.length();
	memory_capacity = str.capacity();
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}// ���� ������
MyString::~MyString() {
	delete[]string_content;
	//cout << " ���Ͷ� �� �� �� " << endl;
} // delete[] string_content


void MyString::setString(const char* str) {
	//*string_content = *str;
	if (string_length == 0) {
		string_length = strlen(str);
		memory_capacity = string_length;
		string_content = new char[string_length];
	}
	for (int i = 0; i != string_length; i++) string_content[i] = str[i];
	//cout << string_length;
}// String�� ��� set

MyString MyString::getMyString() const {
	return *this.strn;
	//??????????????????????????????????????????????????????????????????
}//return MyString class
char* MyString::getString() const {
	return string_content;
}//return string_content
int MyString::length() const {
	return string_length;
}// return string length
int MyString::capacity() const {
	return memory_capacity;
}// retrun momory_capacity
void MyString::reserve(int size) {

	char* temp = string_content;
	string_content = new char[size];
	for (int i = 0; i != string_length; i++) string_content[i] = temp[i];
	memory_capacity = size;

	delete[] temp;
}// �Ҵ��� ���ڿ� ũ�� reserve, ����

void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	cout << endl;
}// ��� �Լ�

	// ����, ���ڿ� ����
MyString& MyString::assign(const MyString& str) {
	if (str.length() > this->capacity()) {
		reserve(str.length() + 1);
		setString(str.getString());
	}
	else if (str.length() <= this->capacity()) {
		setString(str.getString());
	}
	else cout << "Assign ����" << endl;

	return *this;
}
MyString& MyString::assign(const char* str) {
	if (string_length < strlen(str)) {
		reserve(strlen(str) + 1);
	}
	else if (string_length >= strlen(str)) {
		setString(str);
	}
	else cout << "Assing-2 ����" << endl;

	return *this;
}

char MyString::at(int i) const {
	string str = string_content;
	if (i > string_length)
		cout << "���������� string�� ������ �ʰ�����" << endl;
	return str.at(i);
}// i ��ġ ���� ����

// ���ڿ� ����
MyString& MyString::insert(int loc, const MyString& str) {
	/*
	string mytemp = string_content;
	string strtemp = str.getString();

	mytemp.insert(loc, strtemp);
	string_length = strlen(mytemp.c_str());
	reserve(string_length);
	setString(mytemp.c_str());
	*/
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) {
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
	// ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.

	for (int i = string_length - 1; i >= loc; i--) {
		// �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
		string_content[i + str.string_length] = string_content[i];
	}
	// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];

	string_length = string_length + str.string_length;
	return *this;
	//???????????????????????????????????????????????????????????
}
MyString& MyString::insert(int loc, const char* str) {
	/*string mytemp = getString();
	string strtemp = str;

	mytemp.insert(loc, strtemp);
	reserve(strlen(mytemp.c_str()));
	setString(mytemp.c_str());
	string_length = strlen(mytemp.c_str());
	*/
	MyString temp(str);
	return insert(loc, temp);
	return *this;
}

// ����, ���ڿ� ã��
int MyString::find(int find_from, const MyString& str) const {
	/*
	string findstring = getString();
	findstring.find(find_from,str.getString());
	return findstring.find(find_from, this->length() ,str.getString());
	*/
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i < string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}

		if (j == str.string_length) return i;
	}

	return -1;
}
int MyString::find(int find_from, const char* str) const {
	/*
	int len = strlen(str);
	return std::find(find_from, this->length(), str);
	*/
	MyString temp(str);
	return find(find_from, temp);
}

// ����
MyString& MyString::erase(int loc, int num) {
	string temp = string_content;
	temp.erase(loc, num);
	int len = strlen(temp.c_str());
	setString(temp.c_str());
	this->string_length -= num;
	return *this;
}