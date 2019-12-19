#include <iostream>
#include <iomanip>
#include <string>


/*struct mymanip {
	int n;
	mymanip(void* func,int n);
	
};
ostream& operator<<(ostream& os, int n) {
	return os;
}
mymanip::mymanip(void* func, int n) :n(n) {
	return func(n);
}
void bell_ringer(ostream& osm, int n) {
	for (int i = 0; i < n; i++) {
		osm << '\a';
	}
}
ostream& fill(int n) {
	return mymanip(bell_ringer,n);
}*/

void main() {
	using namespace std;
	string str = "tlqkf";
	cout << str << endl;
	str.clear();
	cout << str;
}