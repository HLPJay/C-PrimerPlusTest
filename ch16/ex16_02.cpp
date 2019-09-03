/*********************************
简单的回文数
关注大小写 空格 标点等复杂的问题
*********************************/

#include <iostream>
#include <string>
#include <cctype>


bool StrIsTracts(std::string& s);
std::string format(std::string& s);

int main()
{
	std::string temp = "tot";
	std::cout<<"tot is tracts:"<<StrIsTracts(temp)<<std::endl;
	std::string temp1 = "top";
	std::cout<<"top is tracts:"<<StrIsTracts(temp1)<<std::endl;
	std::string temp2 = "otto";
	std::cout<<"otto is tracts:"<<StrIsTracts(temp2)<<std::endl;



	std::string temp3 = "Madam, I'm Adam";
	std::cout<<"otto is tracts:"<<StrIsTracts(temp3)<<std::endl;
	return 0;
}

void ToLower(std::string& s)
{
	for(int i=0;i<s.length(); i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			s[i] = std::tolower(s[i]);
		}
	}
	std::cout<<"ToLower:"<< s<<std::endl;
}

//要把大写转为小写  要把其中的其他字符去掉
std::string format(std::string& s)
{
	std::string temp(s);
	ToLower(temp);


	std::string::iterator sit = temp.begin();
	int i=0;
	while(sit != temp.end())
	{
		if(*sit<='a' || *sit>='z')
		{
			temp.erase(i,1);
		}
		else
		{
			i++;
			sit++;
		}
	}
	return temp;
}

bool StrIsTracts(std::string& s)
{
	if(s.size() == 0)
	{
		return false;
	}

	std::string temp;
	temp = format(s);
	std::cout<<s<<" format: "<<temp<<std::endl;
	for(int i=0, z= temp.size()-1;i<=temp.size()/2; i++,z--)
	{
		if(temp[i] != temp[z])
		{
			return false;
		}
	}
	return true;
}