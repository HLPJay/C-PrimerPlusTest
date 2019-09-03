#include <iostream>
#include <string>


class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info *pi;
public :
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();

	Cpmv & operator= (const Cpmv & cp);
	Cpmv & operator= (Cpmv && mv);

	Cpmv operator+(const Cpmv& obj) const;
	void Display() const;
};

Cpmv::Cpmv()
{
	pi = new Info;
}

Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
	if(pi!=nullptr)
	{
		delete pi;
	}
}

Cpmv & Cpmv::operator= (const Cpmv & cp)
{
	if(&cp == this)
	{
		return *this;
	}
	delete pi;
	pi = new Info;	
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}

Cpmv & Cpmv::operator= (Cpmv && mv)//TODO 移动构造函数 移动赋值构造函数
{
	if(&mv == this)
	{
		return *this;
	}
	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
	this->pi->qcode = this->pi->qcode + obj.pi->qcode;
	this->pi->zcode = this->pi->zcode + obj.pi->zcode;
	return *this;
}

void Cpmv::Display() const
{
	std::cout<<"qcode :"<<this->pi->qcode
			 <<" qcode "<<this->pi->zcode<<std::endl;
}


int main()
{
	Cpmv cp;
	std::cout<<"cp:\n";
	cp.Display();
	Cpmv cp1("test1", "test2");

	std::cout<<"cp1:\n";
	cp1.Display();

	Cpmv cp2(cp1);
	std::cout<<"cp2:\n";
	cp2.Display();

	Cpmv cp3(std::move(cp1));//TODO:: 移动构造函数  原来的构造函数再去作移动赋值会出问题？？？
	std::cout<<"cp3:\n";
	cp3.Display();
	std::cout<<"cp2:\n";
	cp2.Display();

	Cpmv cp4 = cp2;
	std::cout<<"cp4:\n";
	cp4.Display();

	Cpmv cp5 = std::move(cp2);
	std::cout<<"cp5:\n";
	cp5.Display();
	return 0;
}