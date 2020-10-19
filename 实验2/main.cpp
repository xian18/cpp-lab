#include "Queue_lab2.h"

extern const char* TestQUEUE(int& s);	//用于实验二

int main(void)
{
    int n;
    const char* s;
    s = TestQUEUE(n);
    printf("%d\n%s", n, s);
    return 0;
}
