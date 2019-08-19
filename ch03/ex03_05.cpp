/*****************************

输入：全球人口和美国人口
输出：美国人口占全球人口的百分比。

******************************/


#include <iostream>
using namespace std;
int main(void)
{
	long long Global_population;
    long long American_population;

    cout<<"Enter the world's population:" ;
    cin>>Global_population;
    cout<<"Enter the population of US:" ;
    cin>>American_population;

    double percentage;
    percentage = American_population/(Global_population*1.0);
    cout<<"The population of the US is "<<percentage*100.0<<"% of the world population."<<endl;
	return 0;
}