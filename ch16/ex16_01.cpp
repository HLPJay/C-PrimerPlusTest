/*********************************
简单的回文数
不关注大小写 空格 标点等复杂的问题
*********************************/

#include <iostream>
#include <string>
bool StrIsTracts(std::string& s);

int main()
{
	std::string temp = "tot";
	std::cout<<"tot is tracts:"<<StrIsTracts(temp)<<std::endl;
	std::string temp1 = "top";
	std::cout<<"top is tracts:"<<StrIsTracts(temp1)<<std::endl;
	std::string temp2 = "otto";
	std::cout<<"otto is tracts:"<<StrIsTracts(temp2)<<std::endl;
	return 0;
}

bool StrIsTracts(std::string& s)
{
	if(s.size() == 0)
	{
		return false;
	}

	for(int i=0, z= s.size()-1;i<=s.size()/2; i++,z--)
	{
		if(s[i] != s[z])
		{
			return false;
		}
	}
	return true;
}