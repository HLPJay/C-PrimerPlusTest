
#include "ex12_04_stack.h"
#include <iostream>
Stack::Stack(int n)
{
	pitems = new Item[n];//TODO new 数组和给new一个赋初值的对象
	size = n;
	top = 0;
}

Stack::Stack(const Stack & st)
{
	// delete [] pitems;
	size = st.size;
	top = st.top;
	pitems = new(std::nothrow) Item[size];
	if(nullptr == pitems)
	{
		std::cout<<"ERROR."<<std::endl;
	}

	for(int i=0;i<top;i++){
		pitems[i] = st.pitems[i];
	}
}

Stack & Stack::operator=(const Stack &st)
{
	if(this == &st)
		return *this;
	delete []pitems;
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for(int i=0;i<top;i++){
		pitems[i] = st.pitems[i];
	}
	return *this;
}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	if(top == 0)
		return true;
	return false;
}

bool Stack::isfull() const
{
	if(top == size)
		return true;
	return false;
}

//后进先出
bool Stack::push(const Item &item)
{
	if(isfull())
		return false;
	pitems[top++] = item;//TODO 当我构造函数错误new Item（size）; 为啥这里正确塞值前四个
	return true;
}

bool Stack::pop(Item &item)
{
	if(isempty())
		return false;
	item = pitems[--top];
	return true;
}

void Stack::show()
{
	for(int i=0;i<top;i++)
	{
		std::cout<<i <<"  is  "<<pitems[i]<<std::endl;
	}
	return ;
}