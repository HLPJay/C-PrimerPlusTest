
#include <iostream>
#include <string>
#include <cstring>

namespace Test10_1{
	using std::string;
	class Person{
	private:
		static const int LIMIT = 25;
		string lname;
		char fname[LIMIT];
	public:
		Person(){lname = ""; fname[0] = '\0'; }
		Person(const string &ln, const char *fn = "Heyyou");
		// ~Person();  //默认析构函数
		void show() const;
		void FormalShow() const;
	};

	Person::Person(const string &ln, const char *fn) //默认值只需要在声明的时候加就好  默认参数写在声明处啊
	{
		this->lname = ln;
		strcpy(this->fname, fn);
	}

	void Person::show() const
	{
		std::cout<<"lname :"<<this->lname<<"     \t";
		std::cout<<"fname :"<<this->fname<<std::endl;
	}

	void Person::FormalShow() const
	{

		std::cout<<"fname :"<<this->fname<<"     \t";
		std::cout<<"lname :"<<this->lname<<std::endl;
	}
}

int main(void)
{
	using namespace Test10_1;
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");

	one.show();
	one.FormalShow();

	two.FormalShow();
	three.FormalShow();

	return 0;
}