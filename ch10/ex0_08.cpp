
#include <iostream>
using namespace std;

//TODO:利用链表的方式来实现list
typedef int Item;
const int MAX = 10;

class List
{
private:
	Item items[MAX];
	int count;
public:
	List();
	bool isempty() const ;
	bool isfull() const;
	bool addItem(const Item & it);
	// Item & visitItem();
	void visit(void(*pf)(Item &));
};

List::List()
{
	count = 0;
}

bool List::isempty() const
{
	if(count==0)
	{
		return true;
	}
	return false;
}

bool List::isfull() const
{
	if(count==10)
	{
		return true;
	}
	return false;
}

bool List::addItem(const Item & it)
{
	if(count>=MAX)
	{
		return false;
	}
	items[count++] = it;
	return true;
}

void List::visit(void (*pf)(Item &))
{
	for(int i = 0; i < count; ++i)
        (*pf)(items[i]);  //传递的是引用 可以对其实现各种操作  TODO ：函数调用
}

void reset(Item & it);
void showItem(Item & it);

int main()
{
	List list;
	if(list.isempty())
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		cout<<"list is not empty"<<endl;
	}

	if(list.isfull())
	{
		cout<<"list is full"<<endl;
	}
	else
	{
		cout<<"list is not full"<<endl;
	}

	Item it = 2;
	for(int i=0;i<11;i++)
	{
		if(!list.addItem(it))
		{
			cout<<"list"<< i <<" push failed!"<< endl;
		}
	}
	list.visit(reset);
	list.visit(showItem);  //TODO 函数指针传递
	list.visit(showItem);
	return 0;
}

void reset(Item & it)
{
	it = 1;
}

void showItem(Item & it)
{
	cout<<it<<endl;
}