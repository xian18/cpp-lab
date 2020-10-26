// main.cpp
#include <iostream>
#include "MAT_lab4.h"

template MAT<int>;			//用于实验四
template MAT<long long>;		//用于实验四
extern const char* TestMAT(int& s);	//用于实验四
int main(int argc, char* argv[]) 					//请扩展main()测试其他运算
{
	int s;
	const char* r;
	r = TestMAT(s);
	printf("%s\n%d", r, s);
	return 0;
}
