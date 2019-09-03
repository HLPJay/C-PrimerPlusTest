#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer(){arrive = processtime = 0;}
	void set(long when);
	long when() const {return arrive;}
	int ptime() const {return processtime;}
};

void Customer::set(long when)
{
	processtime = std::rand()%3 +1;
	arrive = when;
}
typedef Customer Item;

const int MIN_PER_HR=60;
bool newcustustomer(double x);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::queue;

	std::srand(std::time(0));//TODO srand and time
	cout<<"enter the maxnum of queue:";
	int qz;
	cin>>qz;
	queue<Item> line;
	cout<< "please enter simulation hours:"<<endl;
	int hours;
	cin>>hours;

	long cyclelimit = MIN_PER_HR*hours;

	cout<<"enter the average number of customers per hours:";
	double perhour;
	cin>>perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR/perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line =0;
	int wait_time = 0;
	long line_wait =0;

	for(int cycle = 0; cycle <cyclelimit; cycle++)
	{
		if(newcustustomer(min_per_cust))
		{
			if(line.size() == qz)
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}

		if(wait_time<=0 && !line.empty())
		{
			temp = line.front();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			line.pop();
			served++;
		}
		
		if(wait_time>0)
			wait_time--;
		sum_line+=line.size();
	}

	if(customers >0)
	{
		cout<<"customers accepted: "<<customers<<endl;
		cout<<"  customers served: "<<served<<endl;
		cout<<"         turnaways: "<<turnaways<<endl;
		cout<<"average queue size:";
		cout.precision(2);
		cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<"average wait time:" <<(double) line_wait/served<<"  mionutes \n";
	}
	else
		cout<<"no customers."<<endl;
	cout<<"Done \n";
	return 0;
}


bool newcustustomer(double x)
{
	return (std::rand()*x/RAND_MAX<1);
}