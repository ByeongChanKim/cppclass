#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;




void calcul(char, int, int);
ofstream output("result.txt");
int main(void) {
	ifstream input("calculation.txt");

	vector<char> opv;
	vector<int> f;
	vector<int> s;

	char op;
	int first;
	int second;
	int i = 0;
	while (i != 5) {
		input >> dec >> op >> hex >> first >> second;
		opv.push_back(op);
		f.push_back(first);
		s.push_back(second);
		i++;
	}
	while (!opv.empty()) {
		calcul(opv.back(), f.back(), s.back());
		opv.pop_back(); f.pop_back(); s.pop_back();
	}

	input.close();
	output.close();

	return 0;
}
void calcul(char op, int first, int second) {
	output.width(8);
	output.setf(ios_base::left);
	if (op == '+') {
		output << first << "+" << second << "=" << dec << "dec :" << first + second << setw(4) << oct << "oct : " << first + second << setfill(' ') << hex << "hex : " << first + second << endl;
	}
	else if (op == '-') {
		output << first << " - " << second << "   =   " << dec << "dec :" << first - second << setw(4) << oct << "oct : " << first + second << setfill(' ') << hex << "hex : " << first - second << endl;
	}
	else if (op == '*') {
		output << first << " * " << second << "   =   " << dec << "dec :" << float(first * second) << setw(4) << oct << "oct : " << first + second << setfill(' ') << hex << "hex :" << first * second << endl;
	}
	else if (op == '/') {
		if (second == 0) { output << "divide zero!" << endl; }
		else if (isxdigit(first) || isxdigit(second) == 1) {
			output << "It's wrong!" << endl;
		}
		else {
			output << first << " / " << second << "   =   " << setw(4) << dec << (double)((double)first / (double)second) << endl;
		}
	}
	else output << "It's wrong!!!!" << endl;
}