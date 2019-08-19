#ifndef EX12_04_STACK_H_
#define EX12_04_STACK_H_
/*************************
1：定义默认的大小
2：传参传入定义的大小
3：
*************************/
typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10};
	Item * pitems;
	int size; //保存存储的个数
	int top;  //保存栈顶位置
public:
	Stack(int n = MAX);
	Stack(const Stack & st);
	Stack & operator=(const Stack &st);
	~Stack();

	bool isempty() const;
	bool isfull() const;

	bool push(const Item &item);
	bool pop(Item &item);
	void show();
};

#endif //EX12_04_STACK_H_