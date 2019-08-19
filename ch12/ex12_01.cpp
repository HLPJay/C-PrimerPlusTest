/****************************
对类声明提提供实现
****************************/
#include <iostream>
#include <cstring>

class Cow{
	char name[20];
	char *bobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(Cow& c);
	~Cow();

	Cow& operator=(const Cow& c);
	void showCow() const;
};

Cow::Cow()
{
	name[0] = '\0';
	bobby = new char[1];
	bobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy(name,nm);//应该对其进行判断
	bobby = new char[std::strlen(ho)+1];
	strcpy(bobby, ho);
	weight = wt;
}

Cow::Cow(Cow& c)
{
	strcpy(name,c.name);
	bobby = new char[std::strlen(c.bobby)+1];
	strcpy(bobby, c.bobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] bobby;
	weight = 0;
}

Cow& Cow::operator=(const Cow& c)//TODO 这里返回引用 所以用this来处理
{
	if(this == &c)   //TODO 这里判断指针相同 
	{
		return *this;
	}
	delete [] bobby;
	strcpy(name,c.name);
	bobby = new char[std::strlen(c.bobby)+1];
	strcpy(bobby, c.bobby);
	weight = c.weight;

}

void Cow::showCow() const
{
	std::cout<<"name: "<<name <<" bobby :"<<bobby <<" weight: "<<weight<<std::endl;
}

int main(void)
{
	Cow co;
	co.showCow();

	Cow co1("my name","my body", 60);
	co1.showCow();

	Cow co2(co1);
	co2.showCow();

	Cow co3;
	co3 = co2;
	co3.showCow();

	Cow* co4 = new Cow(co1);
	co4->showCow();
	delete co4;

	Cow* co5 = new Cow;
	*co5 = co1;//TODO 这是正确的赋值运算符的用法 而不是用& co1
	co5->showCow();

	Cow* co6 = new Cow(*co5);
	delete co5;
	co6->showCow();
	delete co6;
	return 0;
}