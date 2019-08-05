/*******************************
处理数组和结构的函数
*******************************/

#include <iostream>
using namespace std;
const int SLEN = 30 ;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);
int main()
{
	cout<<"Enter class Size:";
	int class_size;
	cin>>class_size;
	while(cin.get()!='\n')
	{
		continue;
	}
	student *ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for(int i=0;i<entered;i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu,entered);
	delete [] ptr_stu;
	cout<<"Done. \n"<<endl;
	return 0;
}

int getinfo(student pa[], int n)
{
	cout<<"Please input student info:"<<endl;
	int i;
	for( i=0;i<n;i++)
	{
		cout<<" Enter the student #"<<i<<" :"<<endl; 
		cout<<"fullname:";

		cin.getline(pa[i].fullname,SLEN);
		if(!pa[i].fullname)
		{
			break;
		}
		cout<<"hobby:";
		cin.getline(pa[i].hobby, SLEN);
		cout<<"ooplevel:";
		cin>> pa[i].ooplevel;
		cin.get();
	}
	return i;
}

void display1(student st)
{
	cout<<"fullname :\t\t"<<st.fullname<<endl;
	cout<<"hobby :\t\t"<<st.hobby<<endl;
	cout<<"ooplevel :\t\t"<<st.ooplevel<<endl;
	return;
}
void display2(const student *ps)
{
	cout<<"fullname :\t\t"<<ps->fullname<<endl;
	cout<<"hobby :\t\t"<<ps->hobby<<endl;
	cout<<"ooplevel :\t\t"<<ps->ooplevel<<endl;
	return;
}
void display3(const student pa[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"#"<<i<<":"<<endl;
		cout<<"fullname :\t\t"<<pa[i].fullname<<endl;
		cout<<"hobby :\t\t"<<pa[i].hobby<<endl;
		cout<<"ooplevel :\t\t"<<pa[i].ooplevel<<endl;
	}
	return;
}