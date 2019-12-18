// 1121.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
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
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
