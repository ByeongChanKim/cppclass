#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

float cal(int a, int b, char c) {
	switch (c)
	{
	case '+':
		return (float)a + (float)b;
		break;
	case '-':
		return (float)a - (float)b;
		break;
	case '*':
		return (float)a * (float)b;
		break;
	case '/':
		return (float)a / (float)b;
		break;
	default:
		break;
	}
}
int main() {
	ifstream inFile("calculation.txt");
	string num1, num2;
	char sign1, sign2;

	if (!inFile.is_open()) {
		cout << "Can not find file" << endl;
		return 0;
	}
	while (inFile >> num1 >> sign1 >> num2 >> sign2) {

		int read1 = 0;
		int read2 = 0;
		if (num1.find("0x") == 0) {
			read1 = stoi(num1.c_str(), nullptr, 16);
			read2 = stoi(num2.c_str(), nullptr, 16);
		}
		else {
			read1 = atoi(num1.c_str());
			read2 = atoi(num2.c_str());
		}
		float answer = cal(read1, read2, sign1);

		cout << left << setw(6) << num1 <<
			setw(2) << sign1 << left << setw(6) << num2
			<< sign2;
		if (sign1 == '/') {
			cout << showpoint << fixed << setprecision(2) << right << setw(8) << answer << endl;
		}
		else if (num1.find("0x") == 0) {
			cout << right << setw(7) << hex << "0x0" << (int)answer << endl;
		}
		else {
			cout << right << setw(8) << (int)answer << endl;
		}
	}
	inFile.close();
	return 0;
}