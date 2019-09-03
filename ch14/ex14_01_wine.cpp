#include <iostream>
#include "ex14_01_wine.h"
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
		:name(l), pair(ArrayInt(yr, y), ArrayInt(bot, y))
	{

	}

	Wine::Wine(const char* l, int y)
		:name(l),pair(ArrayInt( y), ArrayInt( y))
	{

	}

	Wine::Wine():name(""), pair(ArrayInt(0), ArrayInt(0))
	{

	}

	void Wine::GetBottles() //保存数据
	{
		std::cout<<"Enter years and counts:"<<std::endl;
		std::cout<<"size:"<<pair.first().size();
		int years, counts;
		for(int i=0;i<pair.first().size(); i++)
		{
			std::cout<<"Enter for "<<i<<" years and counts:"<<std::endl;
			std::cin>>years>>counts;
			pair.first()[i] = years;
			pair.second()[i] = counts;
		}
		return ;
	}

	const std::string& Wine::Label() const
	{
		return name;
	}

	long Wine::sum() const 
	{
		long sum = 0;
		for(int i=0;i<pair.second().size();i++)
		{
			sum += pair.second()[i];
		}
		return sum;
	}

	void Wine::Show() const
	{
		std::cout<<"name:"<<name<<std::endl;
		for(int i=0;i<pair.second().size();i++)
		{
			std::cout<<i<<" first:"<<pair.first()[i]<<"second:"<<pair.second()[i]<<std::endl;
		}
		return;
	}