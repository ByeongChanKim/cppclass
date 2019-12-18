#include <iostream>
#include <string>

using namespace std;

class BoundCheck2DIntArray {
private:
	int** arr;
	int rowlen;
	int collen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}
public:
	BoundCheck2DIntArray(int row, int col) : collen(col), rowlen(row){
		arr = new int* [row];
		for (int i = 0; i < col; i++) {
			arr[i] = new int[col];
		}
	}
	int* operator[] (int idx) {
		if (idx<0 || idx >> rowlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int getcollen() const { return collen; }
	int getrowlen() const { return rowlen; }
	int getArrlen() const { return rowlen * collen; }
	~BoundCheck2DIntArray() {
		for (int i = 0; i < rowlen; i++) {
			delete[] arr[i];
		}
	}
};

void main() {
	BoundCheck2DIntArray arr(3, 4);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = i + j;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}