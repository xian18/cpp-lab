#include "Stack_lab3.h"
#define POP_STACK_COMPLEX 1
using namespace std;
STACK::STACK(int m) :q(m), QUEUE(m) { cout << "call STACK::STACK(int m:" << m << ")" << endl; }  		//��ʼ��ջ�������2m-2��Ԫ��
STACK::STACK(const STACK& s) : q(s.q), QUEUE(s.q.size()) 
{
	cout << "call STACK::STACK(const STACK& s:)" << endl;
	QUEUE::operator=(s);
} //��ջs�����ʼ��ջ
STACK::STACK(STACK&& s)noexcept :q(0), QUEUE(0) 
{
	cout << "call STACK::STACK(STACK&& s:)noexcept" << endl;
	QUEUE::operator=((STACK&&)s);
	q.operator=((QUEUE&&)s.q);
} //��ջs�ƶ�������ʼ��ջ
int  STACK::size()const noexcept
{
	cout << "call int STACK::size()const noexcept" << endl;
	return (QUEUE::size()) * 2;
}		  		//����ջ��������2m
STACK::operator int() const noexcept 
{
	cout << "call STACK::operator int()const noexcept" << endl;
	return (QUEUE::operator int())+q.operator int();
}	   		//����ջ��ʵ��Ԫ�ظ���
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
} 	     		//��e��ջ�������ص�ǰջ

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
}//��ջ��e�������ص�ǰջ
#endif // POP_STACK_COMPLEX

STACK& STACK::operator=(const STACK& s) 
{
	cout << "call STACK& STACK::operator=(const STACK& s)" << endl;
	if (this == &s) { return *this; }
	QUEUE::operator=(s);
	q = s.q;
	return *this; 
}	//�����ֵ�����ر���ֵջ
STACK& STACK::operator=(STACK&& s)noexcept 
{
	cout << "call STACK& STACK::operator=(STACK&& s)noexcept" << endl;
	if (this == &s) { return *this; }
	QUEUE::operator=((STACK&&)s);
	q = (STACK&&)s.q;
	return *this; 
}//�ƶ���ֵ�����ر���ֵջ

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
}	//��ջ�׵�ջ����ӡջԪ�� 
#endif // POP_STACK_COMPLEX

STACK::~STACK()noexcept 
{
	cout << "call STACK::~STACK()noexcept" << endl;
	q.~QUEUE(); 
	QUEUE::~QUEUE();
}	             	//����ջ
