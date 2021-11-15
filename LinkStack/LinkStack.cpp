#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "LinkStack.h"

template <class DataType>
LinkStack<DataType>::LinkStack()
{
	top = NULL;
	cout << "构造中。。。" << endl;
}

template <class DataType>
LinkStack<DataType>::~LinkStack()
{
	node *tmpNode;
	
	//cout << isEmpty() << endl;
	//cout << "top是：" << top->data << endl;
		while(!isEmpty())
		{
			cout << "析构中。。。" << endl;
			tmpNode = top;
			//delete top;
			top = top->next;
			delete tmpNode;
		}
		if (isEmpty())
			cout << "析构完成" << endl;
}

template <class DataType>
void LinkStack<DataType>::push(DataType X)
{
	node* tmpPtr = new node;
	tmpPtr->data = X; //将新数据放入新node
	tmpPtr->next = top; //将新node与原本的LinkStack相连，此时新node处于最顶端
	top = tmpPtr; //将top指针指向新node。新LinkStack完成。

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

	result = top->data; //将top的值赋给result，以便pop结果
	tmpNode = top; //将原top node的地址传给tmpNode以便之后delete原来的top node
	top = top->next; //top指向pop后新的top node

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