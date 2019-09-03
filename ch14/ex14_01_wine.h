#ifndef EX14_01_WINE_H_
#define EX14_01_WINE_H_

#include <string>
#include <valarray>

template <class T1, class T2>
class Pair
{
private:
	T1 t1;
	T2 t2;
public:
	Pair(){};
	Pair(T1 & t, T2 & q);
	Pair(T1 t, T2 q);
	Pair(Pair<T1, T2> &q);

	T1 & first() { return t1;}
	T2 & second() { return t2;}
	T1 first() const { return t1;}  //TODO 返回必须是const
	T2 second() const  { return t2;}
};

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	std::string name;
	// Pair<std::valarray<int>, std::valarray<int>> pair;
	PairArray pair;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	Wine();
	void GetBottles();
	const std::string& Label() const;  //TODO  涉及到相关成员的引用 必须加const
	long sum() const ;
	void Show() const;
};

#endif