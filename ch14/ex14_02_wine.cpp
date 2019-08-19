#include <iostream>
#include "ex14_02_wine.h"
//TODO 模板函数的使用必须带template声明

template <class T1, class T2>
Pair<T1,T2>::Pair(T1 & t, T2 & q)
	:t1(t),t2(q)
{

}

template <class T1, class T2>
Pair<T1,T2>::Pair(T1 t, T2 q)
	:t1(t),t2(q)
{

}

template <class T1, class T2>
Pair<T1,T2>::Pair(Pair<T1,T2> &q)
{
	t1=q.t1;
	t2=q.t2;
}

//TODO 查阅valarray的构造函数 确定valarray的构造方法及相关函数
	Wine::Wine(const char* l, int y, const int yr[], const int bot[])
		:std::string(l), Pair(std::valarray<int>(yr, y), std::valarray<int>(bot, y))
	{

	}

	Wine::Wine(const char* l, int y)
		:std::string(l),Pair(std::valarray<int>(y), std::valarray<int>(y))
	{

	}

	Wine::Wine():std::string(""), Pair(std::valarray<int>(0), std::valarray<int>(0))
	{

	}

	void Wine::GetBottles() //保存数据
	{
		std::cout<<"Enter years and counts:"<<std::endl;
		std::cout<<"size:"<<PairArray::first().size();
		int years, counts;
		for(int i=0;i<PairArray::first().size(); i++)
		{
			std::cout<<"Enter for "<<i<<" years and counts:"<<std::endl;
			std::cin>>years>>counts;
			PairArray::first()[i] = years;
			PairArray::second()[i] = counts;
		}
		return ;
	}

	const std::string& Wine::Label() const
	{
		return (const std::string &)*this;  // TODO 子类强转为基类 这里用引用
	}

	long Wine::sum() const 
	{
		long sum = 0;
		for(int i=0;i<PairArray::second().size();i++)
		{
			sum += PairArray::second()[i];
		}
		return sum;
	}

	void Wine::Show() const
	{
		std::cout<<"name:"<<(const std::string &)*this<<std::endl;
		for(int i=0;i<PairArray::second().size();i++)
		{
			std::cout<<i<<" first:"<<PairArray::first()[i]<<"second:"<<PairArray::second()[i]<<std::endl;
		}
		return;
	}