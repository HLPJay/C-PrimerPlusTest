#include <iostream>
#include "dma.h"

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	

	BassDMA shirt("Portabelly", 8);
	LacksDMA ballon("red" , "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo keys", 5);


	cout<<"Displaying BassDMA Object:";
	cout<<shirt<<endl;
	cout<<"Displaying LacksDMA Object:";
	cout<<ballon<<endl;
	cout<<"Displaying hasDMA Object:";
	cout<<map<<endl;

	LacksDMA ballon2(ballon);
	cout<<"result of  LacksDMA copy:";
	cout<<ballon2<<endl;

	hasDMA map2;
	map2 = map;
	cout<<"result of  hasDMA assignment:";
	cout<<map2<<endl;
	return 0;
}