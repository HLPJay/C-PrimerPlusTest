#include <iostream>
#include <new>
#include <cstdlib>

struct big
{
	double stuff[20000];
};

int main()
{
	using namespace std;
	big *b;
	try
	{
		cout<<"Tring to get a big block of memory: \n";
		b = new big[10000];
		cout<<"get past  th new request \n"; 
	}
	catch (bad_alloc &ba)
	{
		cout<<"Caught the exception!\n";
		cout<<ba.what()<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Merrory success allocated!\n";
	b[0].stuff[0] = 4;
	cout<<b[0].stuff[0]<<endl;
	delete [] b;
	return 0;
}