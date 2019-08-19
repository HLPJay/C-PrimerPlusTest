/******************************
先进先出的队列 应该用链表来实现的
******************************/

#ifndef EX14_03_QUEUE_H_
#define EX14_03_QUEUE_H_

#include <cstdlib>
template <class T>
class queueTp
{
private:
	struct Node
	{
		T t;
		struct Node * next;
	};
	enum {Q_SIZE = 10};
	int items; //队列中元素的个数
	int qsize; //队列的大小
	Node * first;
	Node * rear;

public:
	queueTp(int ss = Q_SIZE); //初始化，确定队列存储的类型
	queueTp(const queueTp & qp) = delete;
	queueTp & operator = (const queueTp & qp) =delete;
	~queueTp();

	T & front(); //返回第一个元素的引用
	T & back();  //返回最后一个元素的引用
	bool isempty() const;
	bool isfull() const;
	int Size() const; //TDOD 这里吧函数名和成员名重名了
	bool push(const T & t);
	bool pop(T & t);
};


template <class T>
queueTp<T>::queueTp(int ss)
		:items(0), qsize(ss)
{
	first = rear = nullptr;
}

// template <class T>
// queueTp<T>::queueTp(const queueTp<T> & qp) 
// {
	
// }

// template <class T>
// queueTp<T> & queueTp<T>::operator = (const queueTp<T> & qp)
// {
	
// }

template <class T>
queueTp<T>::~queueTp()
{
	Node * temp;
	while(!isempty())
	{
		temp = first;
		first = first->next;
		delete temp;
		--items;
	}

	// while(first!=nullptr)
	// {
	// 	temp = first;
	// 	first = first->next;
	// 	delete temp;
	// }
}

template <class T>
T & queueTp<T>::front()
{
	if(isempty())
	{
		std::cerr<<"queueTp is empty: "
		<<" front() is error\n";
		std::exit(EXIT_FAILURE);
	}
	return first->t;
}

template <class T>
T & queueTp<T>::back()
{

	if(isempty())
	{
		std::cerr<<"queueTp is empty: "
		<<" back() is error\n";
		std::exit(EXIT_FAILURE);
	}
	return rear->t;
}

template <class T>
bool queueTp<T>::isempty() const
{
	return items == 0;
}

template <class T>
bool queueTp<T>::isfull() const
{
	return items == qsize;
}

template <class T>
int queueTp<T>::Size() const
{
	return items;
}

//如果不考虑队列会满的情况下
//应该用链表的方式实现
template <class T>
bool queueTp<T>::push(const T & t)
{
	if(isfull())
	{
		return false;
	}
	Node * temp;
	temp = new Node;
	temp->t = t;
	temp->next = nullptr;

	if(first == nullptr)
		first = temp;
	else
		rear->next = temp;
	rear = temp;

	items++;
	return true;

}

//取第一个
template <class T>
bool queueTp<T>::pop(T & t)
{
	if(isempty())
	{
		return false;
	}
	Node * temp;
	temp = first;
	first = first->next;
	items--;

	t = temp->t;
	delete temp;
	if(items == 0)
	{
		rear = nullptr;
	}
	return true;

}
#endif