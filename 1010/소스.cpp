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
}// 문자열 생성자
MyString::MyString(const MyString& str) {

	string_length = str.length();
	memory_capacity = str.capacity();
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}// 복사 생성자
MyString::~MyString() {
	delete[]string_content;
	//cout << " 나와라 소 멸 자 " << endl;
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
}// String일 경우 set

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
}// 할당할 문자열 크기 reserve, 예약

void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	cout << endl;
}// 출력 함수

	// 문자, 문자열 변경
MyString& MyString::assign(const MyString& str) {
	if (str.length() > this->capacity()) {
		reserve(str.length() + 1);
		setString(str.getString());
	}
	else if (str.length() <= this->capacity()) {
		setString(str.getString());
	}
	else cout << "Assign 실패" << endl;

	return *this;
}
MyString& MyString::assign(const char* str) {
	if (string_length < strlen(str)) {
		reserve(strlen(str) + 1);
	}
	else if (string_length >= strlen(str)) {
		setString(str);
	}
	else cout << "Assing-2 실패" << endl;

	return *this;
}

char MyString::at(int i) const {
	string str = string_content;
	if (i > string_length)
		cout << "가져오려는 string의 범위를 초과했음" << endl;
	return str.at(i);
}// i 위치 문자 리턴

// 문자열 삽입
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

	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

	for (int i = string_length - 1; i >= loc; i--) {
		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
		string_content[i + str.string_length] = string_content[i];
	}
	// 그리고 insert 되는 문자 다시 집어넣기
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

// 문자, 문자열 찾기
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

// 삭제
MyString& MyString::erase(int loc, int num) {
	string temp = string_content;
	temp.erase(loc, num);
	int len = strlen(temp.c_str());
	setString(temp.c_str());
	this->string_length -= num;
	return *this;
}