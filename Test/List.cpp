typedef int Status;
#define OK 0
#define ERROR -1
#define My_OVERFLOW -2

template <typename ElemType>
class List
{
	ElemType* elem;
	int length;
	int listsize;
	int LIST_INITISIZE;
	int LISTINCREMENT;
public:
	List(int initSize = 1, int increaseSize = 1);
	~List();
	ElemType& operator[](int index);
	Status InitList();
	Status DestroyList();
	Status ListInsert(int i, ElemType e);
	Status SET_LIST_INITISIZE(int list_initsize);
	Status SET_LISTINCREMENT(int list_increment);
};

template <typename ElemType>
List<ElemType>::List<ElemType>(int initSize, int increaseSize)
{
	elem = nullptr;
	length = 0;
	listsize = 0;
	LIST_INITISIZE = initSize;
	LISTINCREMENT = increaseSize;
};

template <typename ElemType>
List<ElemType>::~List<ElemType>()
{
	if(elem)
		delete[]elem;
	elem = nullptr;
	listsize = 0;
	length = 0;
}


template <typename ElemType>
Status List<ElemType>::InitList()
{
	if (elem)
		DestroyList();
	elem = new ElemType[LIST_INITISIZE];
	
	length = 0;
	listsize = LIST_INITISIZE;
	return OK;
}

template<typename ElemType>
Status List<ElemType>::DestroyList()
{
	if (elem)
		delete[]elem;
	elem = nullptr;
	listsize = 0;
	length = 0;
	return OK;
}

template<typename ElemType>
Status List<ElemType> ::ListInsert(int i, ElemType e)
{
	ElemType* newelem;
	int copy;
	if (!elem)
		InitList();
	if (!elem)
		return ERROR;

	if (i<1 || i>length + 1)
		return My_OVERFLOW;

	if (length >= listsize)
	{
		newelem = new ElemType[listsize + LISTINCREMENT];
		for (copy = length; copy >= 0; copy--)
		{
			if (copy < i - 1)
			{
				newelem[copy] = elem[copy];
			}
			else
			{
				if (copy > i - 1)
					newelem[copy] = elem[copy - 1];
				else
					newelem[copy] = e;
			}
		}
		delete[]elem;
		elem = newelem;
		elem[i - 1] = e;
		listsize += LISTINCREMENT;
		length++;
		return OK;
	}
	for (copy = length; copy >= i; copy--)
	{
		elem[copy] = elem[copy - 1];
	}
	length++;
	elem[i - 1] = e;
	return OK;
}


template <typename ElemType>
ElemType& List<ElemType>::operator[](int index)
{
	ElemType* newelem;
	int copy;

	if (!this)
		return *(new ElemType);
	if (!elem)
		InitList();
	if (!elem)
		return *(new ElemType);
	if (index<0 || index>length)
		return *(new ElemType);
	if (index == length)
		ListInsert(index + 1, ElemType());
	return elem[index];
}

template<typename ElemType>
Status List<ElemType>::SET_LIST_INITISIZE(int list_initsize)
{
	LIST_INITISIZE = list_initsize;
	return OK;
}

template<typename ElemType>
Status List<ElemType>::SET_LISTINCREMENT(int list_increment)
{
	LISTINCREMENT = list_increment;
	return OK;
}

