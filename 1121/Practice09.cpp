#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
template <class T>
class Deque {
	T elem[100000];
	int front = 50000;
	int back = 50000;
public:
	Deque();
	int push_front(T n);
	int push_back(T n);
	int pop_front();
	int pop_back();
	int size();
	int Front();
	int Back();
	int Empty();

};
template <class T>
Deque<T>::Deque() { front = NULL; back = NULL; }
template <class T>
int Deque<T>::push_front(T n) {
	elem[--front] = n;
	return n;
}
template <class T>
int Deque<T>::push_back(T n) {
	elem[back++] = n;
	return n;
}
template <class T>
int  Deque<T>::pop_front() {
	int r = elem[front];
	elem[front++] = 0;
	return r;
}
template <class T>
int Deque<T>::pop_back() {
	int r = elem[front];
	elem[--back] = 0;
	return r;
}
template <class T>
int Deque<T>::size() {
	int count = 0;
	for (int i = back; i > front; i--) {
		count++;
	}
	return count;
}
template <class T>
int  Deque<T>::Front() {
	return elem[front];
}
template <class T>
int Deque<T>::Back() {
	return elem[back - 1];
}
template <class T>
int Deque<T>::Empty() {
	if (front == back) return 1;
	else return 0;
}


int main() {
	Deque<int> deque;

	int inst;
	cin >> inst;
	int i = 0;
	
	int num;
	string instruction;
	char* tok1[2];
	char *context;
	const char* const instSet[8] = {
		"push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front","back"
	};
	while (i != inst) {
		cin >> instruction;

		if (strcmp(instruction.c_str(), instSet[0]) == 0) {
			cin >> num;
			deque.push_front(num);
		}
		else if (strcmp(instruction.c_str(), instSet[1]) == 0) {
			cin >> num;
			deque.push_back(num);
		}
		else if ((strcmp(instruction.c_str(), instSet[2]) == 0)) {
			cout << deque.pop_front() << endl;
		}
		else if (strcmp(instruction.c_str(), instSet[3]) == 0) {
			cout << deque.pop_back() << endl;
		}
		else if (strcmp(instruction.c_str(), instSet[4]) == 0) {
			cout << deque.size() << endl;
		}
		else if (strcmp(instruction.c_str(), instSet[5]) == 0) {
			cout << deque.Empty() << endl;
		}
		else if (strcmp(instruction.c_str(), instSet[6]) == 0) {
			cout << deque.Front() << endl;
		}
		else if (strcmp(instruction.c_str(), instSet[7]) == 0) {
			cout << deque.Back() << endl;
		}
		i++;
	}
	return 0;
}