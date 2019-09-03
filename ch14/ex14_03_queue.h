/******************************

创建一个队列

先进先出
******************************/

//设计 不用管队列的大小只需要在内部定义一个就好
//TODO 如果设置模板时  定义的cpp文件和头文件分开会怎样？
#ifndef EX14_03_QUEUE_H_
#define EX14_03_QUEUE_H_

template <class T>
class queueTp
{
private:
	// enum MAX{10};
	enum { MAX=10};  //TODO 枚举类型的定义
	T items[MAX];
	int size;  //判断是否满了
	int start;
	int end;
public:
	queueTp(); //初始化，确定队列存储的类型
	queueTp(const queueTp & qp);
	queueTp & operator = (const queueTp & qp);
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
queueTp<T>::queueTp()
	:size(0), start(0), end(0)
{

}

template <class T>
queueTp<T>::queueTp(const queueTp<T> & qp)
{
	size = qp.size;
	start = qp.start;
	end = qp.end;
	for(int i=start; i<end; i++)
	{
		items[i] = qp.items[i];
	}
}

template <class T>
queueTp<T> & queueTp<T>::operator = (const queueTp<T> & qp)
{
	if(this == &qp)
	{
		return *this;
	}
	size = qp.size;
	start = qp.start;
	end = qp.end;
	for(int i=start; i<end; i++)
	{
		items[i] = qp.items[i];
	}
}

template <class T>
queueTp<T>::~queueTp()
{
}

template <class T>
T & queueTp<T>::front()
{
	return items[start];
}

template <class T>
T & queueTp<T>::back()
{
	return items[end-1];
}

template <class T>
bool queueTp<T>::isempty() const
{
	return size == 0;
}

template <class T>
bool queueTp<T>::isfull() const
{
	return size == MAX;
}

template <class T>
int queueTp<T>::Size() const
{
	return size;
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


	items[end++] = t;
	++size;

}

template <class T>
bool queueTp<T>::pop(T & t)
{
	if(isempty())
	{
		return false;
	}
	t = items[start++];
	--size;
}
#endif