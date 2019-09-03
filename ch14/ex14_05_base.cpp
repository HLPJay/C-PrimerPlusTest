#include "ex14_05_base.h"

abstr_emp::abstr_emp()
	:fname("None"), lname("None"), job("None")
{}

abstr_emp::abstr_emp(const std::string& fn,const std::string &ln,const std::string& j)
	:fname(fn), lname(ln), job(j)
{}

void abstr_emp::ShowAll() const
{
	std::cout<<"fname: "<<fname<<"\t lname: "<<lname<<"\t job: "<<job<<"! \n";
}

void abstr_emp::SetAll()
{
	std::cout<<"Plase enter a fname:\n";
	getline(std::cin, fname);
	std::cout<<"Plase enter a lname:\n";
	getline(std::cin, lname);
	std::cout<<"Plase enter a job:\n";
	getline(std::cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp &e)
{
	os<<"fname: "<<e.fname<<"\t lname: "<<e.lname<<"\t job: "<<e.job<<"!";
	return os;
}

abstr_emp::~abstr_emp()
{}


employee::employee()
	:abstr_emp()
{}

employee::employee(const std::string& fn,const std::string &ln,const std::string& j)
	:abstr_emp(fn, ln, j)
{}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager()
	:abstr_emp(), inchargeof(0)
{

}

manager::manager(const std::string& fn,const std::string &ln,const std::string& j, int ico)
	:abstr_emp(fn, ln, j), inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico)
	:abstr_emp(e)//TODO 按照默认的赋值构造函数
{
	inchargeof = ico;
}

manager::manager(const manager & m)
	:abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout<<"inchargeof:"<<inchargeof<<std::endl;
}

void manager::SetAll()
{
	std::cout<<"manager:"<<std::endl;
	abstr_emp::SetAll();
	std::cout<<"Please Input manager inchargeof: \n";
	std::cin>>inchargeof;
	return;
}


fink::fink()
	:abstr_emp(), reportsto("None")
{}

fink::fink(const std::string& fn,const std::string &ln,const std::string& j, const std::string& rpo)
	:abstr_emp(fn, ln, j), reportsto(rpo)
{}

fink::fink(const abstr_emp &e, const std::string &rpo)
	:abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink & e)
	:abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout<<"reportsto:"<<reportsto<<"\n";
}

void fink::SetAll()
{
	std::cout<<"fink:"<<std::endl;
	abstr_emp::SetAll();	
	std::cout<<"Enter reportsto:\n";
	std::getline(std::cin, reportsto);
	return;
}

highfink::highfink()
	:abstr_emp(), manager(), fink()
{}

highfink::highfink(const std::string& fn,const std::string &ln,const std::string& j,
 	const std::string& rpo, int ico)
	:abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{}

highfink::highfink(const fink& f, int ico)
	:abstr_emp(f), manager(f,ico), fink(f)
{

}

highfink::highfink(const manager& m, const std::string& rpo)
	:abstr_emp(m), manager(m), fink(m, rpo)
{}

highfink::highfink(const highfink& h)
	:abstr_emp(h),manager(h),fink(h)
{}

void highfink::ShowAll() const
{
	manager::ShowAll();
	fink::ShowAll();
}

void highfink::SetAll()
{
	manager::SetAll();
	fink::SetAll();
}