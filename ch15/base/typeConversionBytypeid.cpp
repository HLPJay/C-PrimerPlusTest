/**************************
dynamic_cast
**************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


using std::cout;

class Grand
{
private:
	int hold;
public:
	Grand(int h =0 ): hold(h) {}
	virtual void Speak() const 
	{ 
		cout<<"I am a grand class! \n";
	}
	virtual int Value() const
	{
		return hold;
	}
};

class Superb: public Grand
{
public:
	Superb(int h=0): Grand(h) {}
	void Speak() const 
	{
		cout<<"I am a Superb class! \n";
	}
	virtual void Say() const
	{
		cout<<"I am a Superb Value of:"<<Value()<<"\n";
	}
};

class Magnificent: public Superb
{
private:
	char ch;
public:
	Magnificent(int h =0 , char c='A'):Superb(h), ch(c){}
	void Speak() const 
	{
		cout<<"I am a Magnificent class!\n";
	}
	void Say() const
	{
		cout<<"I am a Magnificent Value of:"<<Value()<<"and the ch is "<<ch<<"\n";
	}
};

Grand* GetOne();

int main()
{
	std::srand(std::time(0));

	Grand* pg;
	Superb* ps;

	for(int i=0; i<5; i++)
	{
		pg =GetOne(); //TODO typeid 以及 name()
		cout<<"Now proceccing type "<<typeid(*pg).name() <<".\n";
		pg->Speak();
		if(ps = dynamic_cast<Superb*>(pg))
			ps->Say();
		if(typeid(Magnificent) == typeid(*pg))
			cout<<"Yes, you are relly Magnificent.\n";
	}
	return 0;
}

Grand* GetOne()
{
	Grand * p;
	switch(std::rand() %3)
	{
		case 0:p =new Grand(std::rand() %100); break;
		case 1:p =new Superb(std::rand() %100); break;
		case 2:p =new Magnificent(std::rand() %100, 'A'+std::rand()%26); break;
	}
	return p;
}
