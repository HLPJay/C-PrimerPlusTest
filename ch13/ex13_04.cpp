#include <iostream>
#include "ex13_04_port.h"

int main()
{
	Port p;
	p.Show();
	std::cout<<p.BottleCount()<<std::endl;
	std::cout<<p<<std::endl;
	std::cout<<(p+=1)<<std::endl;

	Port p1("brand", "styled", 12);
	std::cout<<p1.BottleCount()<<std::endl;
	std::cout<<p1<<std::endl;
	std::cout<<(p1-=1)<<std::endl;
	std::cout<<(p1+=1)<<std::endl;

	Port p2 = p1;
	std::cout<<p2.BottleCount()<<std::endl;
	std::cout<<p2<<std::endl;
	std::cout<<(p2-=1)<<std::endl;
	std::cout<<(p2+=1)<<std::endl;

	VintagePort v;
	std::cout<<v.BottleCount()<<std::endl;
	std::cout<<v<<std::endl;
	std::cout<<(v+=1)<<std::endl;

	VintagePort v1("brand1",22, "nickname1", 45);
	std::cout<<v1.BottleCount()<<std::endl;
	std::cout<<v1<<std::endl;
	std::cout<<(v1+=1)<<std::endl;

	VintagePort v2 = v1;
	std::cout<<v2.BottleCount()<<std::endl;
	std::cout<<v2<<std::endl;
	std::cout<<(v2+=1)<<std::endl;

	Port * ptr = new VintagePort("brand2", 222, "nickname2", 25);
	ptr->Show();
	delete ptr;
	return 0;
}