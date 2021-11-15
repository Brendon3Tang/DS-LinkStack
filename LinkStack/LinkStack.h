#pragma once
#include <iostream>
using namespace std;

template <class DataType>
class LinkStack
{
private:
	struct node
	{
		DataType data;
		struct node* next;
	};

	node* top;
public:
	LinkStack();

	~LinkStack();

	void push(DataType X);

	DataType pop();

	DataType getTop();

	bool isEmpty();

	class Empty{};
};