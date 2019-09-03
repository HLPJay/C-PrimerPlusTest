#include <iostream>
#include <array>

const int Size = 5;

template <typename T>
void Sum(std::array<double, Size> a, T fp);

class Adder
{
	double tot;
public:
	Adder(double q =0):tot(q){}
	void operator()(double w){tot+=w;};
	double tot_v() const {return tot; }
};

int main()
{
	double total = 0.0;
	// Adder ad(total);
	std::array<double,Size> temp_c = {32.1,34.3,37.8,35.2,34.7};
	// Sum(temp_c, ad);

	Sum(temp_c, [&total](double x){ total +=x;}); //这里直接传函数块  不能用引用
	std::cout<<"total:"<<total<<std::endl;
	// total = ad.tot_v();
	// std::cout<<"total:"<<ad.tot_v()<<"\n";
}

template<typename T>
void Sum(std::array<double, Size> a, T fp)
{
	for(auto pt=a.begin(); pt!= a.end(); ++pt)
	{
		fp(*pt);
	}
}