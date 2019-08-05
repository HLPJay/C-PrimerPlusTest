/*************************
输入：正整数
练习：创建一个动态int数组

**************************/

// #include <iostream>
// #include <vector>
// using namespace std;

// int main(void)
// {
// 	unsigned int num;
// 	cout<<"Please input the num:";
// 	cin>>num;
// 	int *dynamicArray = new int [num];
// 	delete [] dynamicArray;
// 	dynamicArray= nullptr;

// 	vector<int> myVector(num); //TODO:vector的初始化要指定类型
// 	return 0;
// }

	// struct FishInformation{
	// 	string variety;
	// 	int weight;
	// 	float length;
	// };

	// int main(void)
	// {
	// 	FishInformation *fishOne = new FishInformation;
	// 	fishOne->variety = "yellow fish";
	// 	fishOne->weight = 10;
	// 	fishOne->length = 8.88;
	// 	cout<<(*fishOne).variety <<" "<<(*fishOne).weight<<" "<<(*fishOne).length<<endl;
	// }

#include <iostream>
#include <vector>
#include <array>
#include <string>

int main(void)
{
	const int stringNUm{10};
	std::vector<std::string> myVector(stringNUm);
	std::array<std::string,stringNUm> myArray;
	return 0;
}