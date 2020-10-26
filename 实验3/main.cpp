// main.cpp
#include "Stack_lab3.h"
#include <iostream>
#define DEBUG_FLAG 0
extern const char* TestSTACK(int& s);	//用于实验三
int main()
{
#if DEBUG_FLAG
	STACK s(4);
	char str[100];
	s << 1 << 2 << 3 << 4 << 5;
	printf(s.print(str));
	return 0;
	
#else
	int s;
	const char* r;
	r=TestSTACK(s);
	printf("%s\n%d",r, s);
	return 0;
#endif
	
}