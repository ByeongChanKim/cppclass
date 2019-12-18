#include <deque>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Deque {
	int elem[100000];
	int front = 50000;
	int back = 50000;
public:
	Deque();
	int push_front(int n);
	int push_back(int n);
	int pop_front();
	int pop_back();
	int size();
	int Front();
	int Back();
	int Empty();

};
Deque::Deque() { front = NULL; back = NULL; }

int Deque::push_front(int n) {
	elem[--front] = n;
	return n;
}
int Deque::push_back(int n) {
	elem[back++] = n;
	return n;
}
int  Deque::pop_front() {
	int r = elem[front];
	elem[front++] = 0;
	return r;
}
int  Deque::pop_back() {
	int r = elem[front];
	elem[--back] = 0;
	return r;
}
int Deque::size() {
	int count = 0;
	for (int i = back; i > front; i--) {
		count++;
	}
	return count;
}
int  Deque::Front() {
	return elem[front];
}
int Deque::Back() {
	return elem[back - 1];
}
int Deque::Empty() {
	if (front == back) return 1;
	else return 0;
}

void main() {
	Deque deque;

	int inst;
	cin >> inst;
	int i = 0;
	int num;
	string instruction;
	char* tok1[2], * context;
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
}