#include <iostream>
#include <string>

using namespace std;

string operator-(string& c1, const string& c2) {
	string temp = c1.erase(c1.find(c2), c2.size());
	return temp;
}
string operator*(const string& c1, const int n) {
	string temp;
	for (int i = 0; i < n; i++) {
		temp += c1;
	}
	return temp;
}
int operator/(const string& c1, const string& c2) {
	int count = 0;
	int pos = 0;
	while (c1.find(c2, pos) != -1) {

		pos = (c1.find(c2, pos));
		pos += +c2.size();
		count++;
	}
	return count;
}


int main() {
	string s1 = "this is test string. test is ok.";
	string s2, s3, s4;
	int n;


	n = s1 / "test";
	cout << n << endl;
	s2 = s1 - "test";
	cout << s2 << endl;
	s3 = s2 - "test";
	cout << s3 << endl;
	n = s3 / "test";
	cout << n << endl;
	string word1 = "test";
	s4 = word1 * 3;
	cout << s4 << endl;

	string s5;
	s5 = s1 - "test" - "this";
	cout << s5 << endl;
	string word2 = "bbaq";
	string s6 = word2 * 3 * 2;
	cout << s6 << endl;
	return 0;
}