#include <iostream>
using namespace std;


class A {
	static int* j, A::* a, i[5];
public :
	A() {

	}
	int x;
	static int& k, * n;
};

int y;
int A::i[5] = { 1,2,3 };
int* A::j = &y;
int A::* j = &A::x;
int A::* A::a = &A::x;
int& A::k = y;
int* A::n = &y;


int main() {
	A a;
	cout << a.k << endl;
	return 0;
}