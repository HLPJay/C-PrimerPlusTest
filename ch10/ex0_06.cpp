#include <iostream>
using namespace std;

class Move
{
private:
	double x;
	double y;
public:
	Move(double a=0, double  = 0);  //定义不能加默认参数  只在声明的地方加就好了
	void showmove();
	Move add(const Move& m) const;
	void reset(double a =0, double b=0);
};



Move::Move(double a, double b)
{
	this->x =a;
	this->y =b;
}

void Move::showmove()
{
	cout<<"x:"<<this->x<<"    y:"<<this->y<<endl;
}

Move Move::add(const Move& m) const // const 类型
{
	// this->x =this->x + m.x;
	// this->y =this->y + m.y;
	Move m1(x+m.x, y+m.y);
	return m1;
	// return *this;
}

void Move::reset(double a , double b)
{
	this->x = a;
	this->y = b;
}

int main()
{
	Move mv(3,4);
	mv.showmove();
	Move mv1(2,2);
	Move mv2=mv.add(mv1);
	mv2.showmove();
	mv.reset(7,8);
	mv.showmove();

	return 0;
}