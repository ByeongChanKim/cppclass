#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

queue<char> cque;

template<class Typ, class charT, class traits = char_traits<charT>>
struct omanip {
	Typ n;
	void(*f)(basic_ostream<charT, traits>&, Typ);
	omanip(void(*f1)(basic_ostream<charT, traits>&, Typ), Typ n1) :f(f1), n(n1) {}
};

template<class charT, class traits, class Typ>
basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os,
	const omanip<Typ, charT>& sman) {
	(sman.f)(os, sman.n);
	return os;
}

void stepws_str(ostream& os, char* str) {
	char ch = *str;
	cque.push(ch);
	static int j = 1;
	if (str == "") {
		os.width(1);
		j = 1;
		while (!cque.empty()) {
			cque.pop();
		}
	}
	else {
		queue<char> another;
		while (!cque.empty()) {
			os << cque.front();
			another.push(cque.front());
			cque.pop();
		}
		while (!another.empty()) {
			cque.push(another.front());
			another.pop();
		}

	}

}
void stempws_static(ostream& os, char* str) {
	static string hapstr = "";
	hapstr.append(str);
	if (str == "") {
		hapstr.clear();
		os << "";
	}
	else {
		os << hapstr.c_str();
	}
}

omanip<char*, char> stepws(char* str) {
	//return omanip<char*, char>(stepws_str, str);
	return omanip<char*, char>(stempws_static, str);
}


ostream& setwpf(ostream& out) {
	static int i = 3;
	out.width(i++);
	return out;
}
int main() {
	cout << 10 << endl;
	cout << setwpf << 20 << endl;
	cout << setwpf << 30 << endl;
	cout << setwpf << 40 << endl;
	cout << 50 << endl;
	cout << setwpf << 60 << endl;
	cout << setwpf << 70 << endl;

	cout << 10 << endl;
	cout << stepws("#") << 20 << endl;
	cout << stepws("#") << 30 << endl;
	cout << stepws("#") << 40 << endl;
	cout << stepws("") << 50 << endl;
	cout << stepws("*") << 60 << endl;
	cout << stepws("$") << 70 << endl;
	cout << stepws("!") << 80 << endl;
	cout << stepws("@") << 90 << endl;
}