#include "Stack_lab3.h"
#define POP_STACK_COMPLEX 1
using namespace std;
STACK::STACK(int m) :q(m), QUEUE(m) { cout << "call STACK::STACK(int m:" << m << ")" << endl; }  		//初始化栈：最多存放2m-2个元素
STACK::STACK(const STACK& s) : q(s.q), QUEUE(s.q.size()) 
{
	cout << "call STACK::STACK(const STACK& s:)" << endl;
	QUEUE::operator=(s);
} //用栈s深拷贝初始化栈
STACK::STACK(STACK&& s)noexcept :q(0), QUEUE(0) 
{
	cout << "call STACK::STACK(STACK&& s:)noexcept" << endl;
	QUEUE::operator=((STACK&&)s);
	q.operator=((QUEUE&&)s.q);
} //用栈s移动拷贝初始化栈
int  STACK::size()const noexcept
{
	cout << "call int STACK::size()const noexcept" << endl;
	return (QUEUE::size()) * 2;
}		  		//返回栈的容量即2m
STACK::operator int() const noexcept 
{
	cout << "call STACK::operator int()const noexcept" << endl;
	return (QUEUE::operator int())+q.operator int();
}	   		//返回栈的实际元素个数
#ifdef POP_STACK_COMPLEX
STACK& STACK::operator<<(int e)
{
	cout << "call STACK& STACK::operator<<(int e:" << e << ")" << endl;
	int t, l;
	if (QUEUE::operator int() == QUEUE::size() - 1)
	{
		if (q.operator int() == QUEUE::size()-1) { throw "STACK is full!"; }
		q << (QUEUE::operator>>(t), t);
	}
	QUEUE::operator<<(e);
	return *this;
}

STACK& STACK::operator>>(int& e)
{
	cout << "call STACK& STACK::operator>>(int& e:)" << endl;
	int t, l;
	if (QUEUE::operator int() == 0)
	{
		if (q.operator int() == 0) { throw "STACK is empty!"; }
		while (q.operator int())
		{
			QUEUE::operator<<((q >> t, t));
		}
	}

	l = QUEUE::operator int();
	l--;
	for (int i = 0; i < l; i++)
	{
		QUEUE::operator<<((QUEUE::operator>>(t), t));
	}
	QUEUE::operator>>(e);
	return *this;
}

#else
STACK& STACK::operator<<(int e)
{
	int t, l;
	if (QUEUE::operator int() == QUEUE::size() - 1)
	{
		if (q.operator int() != 0) { throw "STACK is full!"; }
		while (QUEUE::operator int())
		{
			q << (QUEUE::operator>>(t), t);
		}
	}
	QUEUE::operator<<(e);
	l = QUEUE::operator int();
	l--;
	for (int i = 0; i < l; i++)
	{
		QUEUE::operator<<((QUEUE::operator>>(t), t));
	}
	return *this;
} 	     		//将e入栈，并返回当前栈

STACK& STACK::operator>>(int& e)
{
	int t, l;
	if (QUEUE::operator int() == 0)
	{
		if (q.operator int() == 0) { throw "STACK is empty!"; }
		while (q.operator int())
		{
			QUEUE::operator<<((q >> t, t));
		}
	}
	QUEUE::operator>>(e);
	return *this;
}//出栈到e，并返回当前栈
#endif // POP_STACK_COMPLEX

STACK& STACK::operator=(const STACK& s) 
{
	cout << "call STACK& STACK::operator=(const STACK& s)" << endl;
	if (this == &s) { return *this; }
	QUEUE::operator=(s);
	q = s.q;
	return *this; 
}	//深拷贝赋值并返回被赋值栈
STACK& STACK::operator=(STACK&& s)noexcept 
{
	cout << "call STACK& STACK::operator=(STACK&& s)noexcept" << endl;
	if (this == &s) { return *this; }
	QUEUE::operator=((STACK&&)s);
	q = (STACK&&)s.q;
	return *this; 
}//移动赋值并返回被赋值栈

#ifdef POP_STACK_COMPLEX
char* STACK::print(char* b)const noexcept
{
	cout << "call char* STACK::print(char* b)const noexcept" << endl;
	int l,i,t,offstr,i2,l2,count;
	int* tempIntL;
	l = q.operator int();
	offstr = 0;
	t = 0;
	if (l)
	{
		l--;
		l2 = q.size();
		count = 0;
		for (i2 = 0; i2 <l2 ; i2++)
		{
			for (i = 0; i <= l; i++)
			{
				((QUEUE*)&q)->QUEUE::operator>>(t);
				((QUEUE*)&q)->QUEUE::operator<<(t);
				if (i==count)
				{
					offstr += sprintf(b + offstr, "%d ", t);
					count++;
				}
			}
		}
	}
	l = QUEUE::operator int();
	l--;
	l2 = QUEUE::size();
	count = 0;
	for (i2 = 0; i2 < l2; i2++)
	{
		for (i = 0; i <= l; i++)
		{
			(*(STACK*)this).QUEUE::operator>>(t);
			(*(STACK*)this).QUEUE::operator<<(t);
			if (i == count)
			{
				offstr += sprintf(b + offstr, "%d ", t);
				count++;
			}
		}
	}
	return b;
}
#else
char* STACK::print(char* b)const noexcept
{
	int* tempIntL;
	int l, i, t, offstr;
	tempIntL = new int[q.size() * 2];
	l = q.operator int();
	offstr = 0;
	t = 0;
	if (l != 0)
	{
		for (i = 0; i < l; i++)
		{
			((QUEUE*)&q)->QUEUE::operator>>(t);
			tempIntL[i] = t;
			((QUEUE*)&q)->QUEUE::operator<<(t);
		}
		while (true)
		{
			i--;
			if (i < 0) { break; }
			offstr += sprintf(b + offstr, "%d ", tempIntL[i]);
		}
	}
	l = QUEUE::operator int();
	for (i = 0; i < l; i++)
	{
		(*(STACK*)this).QUEUE::operator>>(t);
		tempIntL[i] = t;
		(*(STACK*)this).QUEUE::operator<<(t);
	}
	while (true)
	{
		i--;
		if (i < 0) { break; }
		offstr += sprintf(b + offstr, "%d ", tempIntL[i]);
	}
	delete[]tempIntL;
	return b;
}	//从栈底到栈顶打印栈元素 
#endif // POP_STACK_COMPLEX

STACK::~STACK()noexcept 
{
	cout << "call STACK::~STACK()noexcept" << endl;
	q.~QUEUE(); 
	QUEUE::~QUEUE();
}	             	//销毁栈
