// main.cpp
#include <iostream>
#include "MAT_lab4.h"

template MAT<int>;			//����ʵ����
template MAT<long long>;		//����ʵ����
extern const char* TestMAT(int& s);	//����ʵ����
int main(int argc, char* argv[]) 					//����չmain()������������
{
	int s;
	const char* r;
	r = TestMAT(s);
	printf("%s\n%d", r, s);
	return 0;
}
