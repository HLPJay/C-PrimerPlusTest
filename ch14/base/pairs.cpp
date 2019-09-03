#include <iostream>
#include <string>

using std::string;
template <class T1, class T2>

class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 &first();
	T2 & second();
	T1 first() const{return a;}
	T2 second() const {return b;}
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval){}
	Pair() {}
};

template <class T1, class T2>
T1 &Pair<T1,T2>::first()
{
	return a;
}

template <class T1, class T2>
T2 &Pair<T1,T2>::second()
{
	return b;
}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Pair<string, int> rating[4] = 
	{
		Pair<string, int>("The purple Duck", 5),
		Pair<string, int>("Jaquie's Frisco Al Fresco", 5),
		Pair<string, int>("Cafe Souffle", 5),
		Pair<string, int>("Bertie's Eats", 5),
	};
	int joints = sizeof(rating)/sizeof(Pair<string,int>);
	cout<<"rating: \t   Eatery \n";
	for(int i=0; i<joints; i++)
	{
		cout<<rating[i].second()<<":\t"
			<<rating[i].first()<<endl;
	}
	cout<<"Oops！Revised rating:\n";
	rating[3].first() = "Berties's Fad Eats";
	rating[3].second() = 6;
	cout<< rating[3].second()<<":\t"<<rating[3].first()<<endl;
	return 0;
}