/***********************
链表比数组添加和删除容易 但是排序复杂

***********************/

#include <iostream>
#include <vector>
#include <list>

#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(void)
{

	std::srand(time(0));
	vector<int> vi0;

	for(long i =0; i<100000; i++)
	{
		vi0.push_back(rand()%100000);
	}

	vector<int> vi1(vi0.begin(), vi0.end());
	list<int> li1(vi0.begin(), vi0.end());

	cout<<"vi1 size: "<<vi1.size()<<endl;
	cout<<"li1 size: "<<li1.size()<<endl;

	clock_t start = clock();
	sort(vi1.begin(), vi1.end());
	clock_t end = clock();
	cout<<"vi1 time: "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;

	clock_t start1 = clock();
	// sort(li1.begin(), li1.end());
	li1.sort();
	clock_t end1 = clock();
	cout<<"vi1 time: "<<(double)(end1-start1)/CLOCKS_PER_SEC<<endl;


	//TODO copy以及不要用list进行排序
	copy(vi0.begin(), vi0.end(), li1.begin());
	start = clock();
	copy(li1.begin(), li1.end(), vi1.begin());
	sort(vi1.begin(), vi1.end());
	copy(vi1.begin(), vi1.end(), li1.begin());
	end = clock();
	cout<<"test time: "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}