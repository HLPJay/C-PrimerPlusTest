/*****************************
模板中的嵌套:用链表的方式实现队列
*****************************/
#ifndef TEMPLATE_QUEUE_TP_H_
#define TEMPLATE_QUEUE_TP_H_

template <class Item>
class QueueTp
{
private:
	enum { Q_SIZE =10 };
	class Node
	{
	public:
		Item item;
		Node *next;
		Node(const Item &i):item(i), next(nullptr) {}
	};
	Node *front;
	Node *rear;
	int items;
	const int qsize;

	QueueTp(const QueueTp& q):qsize(0){}
	QueueTp & operator = (const QueueTp& q) {return *this;}
public:
	QueueTp(int qz = Q_SIZE);
	~QueueTp();
	bool isempty() const 
	{
		return items ==0;
	}
	bool isfull() const 
	{
		return items == qsize;
	}
	int queuecount()
	{
		return items;
	}

	bool enqueue(const Item & item);
	bool dequeue(Item & item);
};

//模板的定义与声明最好在同一个文件
template <class Item>
QueueTp<Item>::QueueTp(int qz):qsize(qz) //TODO const qsize
{
	front = rear = 0;
	items = 0;

}

template <class Item>
QueueTp<Item>::~QueueTp()
{
	Node * temp;
	while(front!=nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class Item>
bool QueueTp<Item>::enqueue(const Item & item)
{
	if(isfull())
	{
		return false;
	}
	Node * temp;
	temp = new Node(item);
	// temp->item = item;
	if(front==nullptr)
	{
		front = temp;
	}
	else
	{
		rear->next = temp;
	}
	
	rear = temp;
	items++;
	return true;
}

template <class Item>
bool QueueTp<Item>::dequeue(Item & item)
{
	if(isempty())
		return false;
	Node * temp;
	temp = front;
	front = front->next;
	items--;
	item = temp->item;
	delete temp;
	if(items == 0)
		rear = 0;
	return true;
}

#endif //TEMPLATE_QUEUE_TP_H_