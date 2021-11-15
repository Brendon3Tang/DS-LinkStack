#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "LinkStack.h"

template <class DataType>
LinkStack<DataType>::LinkStack()
{
	top = NULL;
	cout << "�����С�����" << endl;
}

template <class DataType>
LinkStack<DataType>::~LinkStack()
{
	node *tmpNode;
	
	//cout << isEmpty() << endl;
	//cout << "top�ǣ�" << top->data << endl;
		while(!isEmpty())
		{
			cout << "�����С�����" << endl;
			tmpNode = top;
			//delete top;
			top = top->next;
			delete tmpNode;
		}
		if (isEmpty())
			cout << "�������" << endl;
}

template <class DataType>
void LinkStack<DataType>::push(DataType X)
{
	node* tmpPtr = new node;
	tmpPtr->data = X; //�������ݷ�����node
	tmpPtr->next = top; //����node��ԭ����LinkStack��������ʱ��node�������
	top = tmpPtr; //��topָ��ָ����node����LinkStack��ɡ�

	tmpPtr = NULL;
	delete tmpPtr;

}

template <class DataType>
DataType LinkStack<DataType>::pop()
{
	if (top == NULL)
		throw Empty();

	DataType result;
	node* tmpNode = new node;

	result = top->data; //��top��ֵ����result���Ա�pop���
	tmpNode = top; //��ԭtop node�ĵ�ַ����tmpNode�Ա�֮��deleteԭ����top node
	top = top->next; //topָ��pop���µ�top node

	delete tmpNode;

	return result;
}

template <class DataType>
DataType LinkStack<DataType>::getTop()
{
	if (isEmpty())
		throw Empty();

	return top->data;
}

template <class DataType>
bool LinkStack<DataType>::isEmpty()
{
	if (top == NULL)
		return true;
	return false;
}

int main()
{
	LinkStack<int> ls;
	ls.push(10);
	ls.push(20);
	ls.push(30);

	try
	{
		cout << ls.pop() << endl;
		cout << ls.getTop() << endl;
		cout << ls.pop() << endl;
		cout << ls.isEmpty() << endl;
		//cout << ls.pop() << endl;
		//cout << ls.isEmpty() << endl;
		//cout << ls.pop() << endl;
		//cout << ls.pop() << endl;
	}
	catch (LinkStack<int>::Empty)
	{
		cout << "LinkStack is empty!" << endl;
	}

		_CrtDumpMemoryLeaks();
	return 0;
}