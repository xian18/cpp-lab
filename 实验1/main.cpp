#include <stdio.h>
#include "Queue_lab1.h"
extern const char* TestQueue(int& s);	//用于实验一
int main(void)
{
    int n;
    const char* s;
    s = TestQueue(n);
    printf("%d\n%s", n, s);
    return 0;
}
