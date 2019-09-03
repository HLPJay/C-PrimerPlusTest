#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const Review& r1, const Review & r2);
bool worseThan(const Review& r1, const Review & r2);
bool betterThan(const Review& r1, const Review & r2);
bool worseThanPrice(const Review& r1, const Review & r2);
bool betterThanPrice(const Review& r1, const Review & r2);
bool FillReview(Review & rt);
void ShowReview(const Review & rt);
int main(int argc, char const *argv[])
{
	using namespace std;

	vector<Review> books;
	Review temp;
	while(FillReview(temp))
		books.push_back(temp);
	if(books.size()>0)
	{
		cout<<"Thank you, you enter the following:"
			<<books.size()<<"  rating :\n"
			<<"Rating \t Book\n";
		for_each(books.begin(), books.end(), ShowReview);

		cout<<"Menu: \n"
			<<"\t a:display by original order \n"
			<<"\t b:display by Alphabet \n"
			<<"\t c:display by rating Raise \n"
			<<"\t d:display by rating reduce \n"
			<<"\t e:display by price Raise \n"
			<<"\t f:display by price reduce \n"
			<<"\t q:to quit \n";
		cout<<"Please input your choice:";
		char ch;
		
		while(std::cin>>ch && ch!='q')
		{
			switch(ch)
			{
				case 'a':
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 'b':
					sort(books.begin(), books.end());
					cout<<"Sorted By Alphabet: \nRating\tprice\took\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 'c':
					sort(books.begin(), books.end(), worseThan);
					cout<<"Sorted By Rating: \nRating\tprice\tBook\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 'd':
					sort(books.begin(), books.end(), betterThan);
					cout<<"Sorted By Rating: \nRating\tprice\tBook\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;
				case 'e':
					sort(books.begin(), books.end(), worseThanPrice);
					cout<<"Sorted By price: \nRating\tprice\tBook\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;		
				case 'f':
					sort(books.begin(), books.end(), betterThanPrice);
					cout<<"Sorted By price: \nRating\tprice\tBook\n";
					for_each(books.begin(), books.end(), ShowReview);
					break;
				default:
					cout<<"Enter error, Please enter a/b/c/d/e/f/q\n";
					break;
			}
			cout<<"Menu: \n"
			<<"\t a:display by original order \n"
			<<"\t b:display by Alphabet \n"
			<<"\t c:display by rating Raise \n"
			<<"\t d:display by rating reduce \n"
			<<"\t e:display by price Raise \n"
			<<"\t f:display by price reduce \n"
			<<"\t q:to quit \n";
			cout<<"Please input your choice:";
		}
		
	}
	else
		cout<<"No entries.";
	cout<<"Bye.\n";
	return 0;
}

bool operator<(const Review& r1, const Review & r2)
{
	if(r1.title<r2.title)
	{
		return true;
	}
	else if(r1.title== r2.title && r1.rating<r2.rating)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool worseThan(const Review& r1, const Review & r2)
{
	if(r1.rating<r2.rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool betterThan(const Review& r1, const Review & r2)
{
	if(r1.rating>r2.rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool worseThanPrice(const Review& r1, const Review & r2)
{
	if(r1.price<r2.price)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool betterThanPrice(const Review& r1, const Review & r2)
{
	if(r1.price>r2.price)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool FillReview(Review & rt)
{
	std::cout<<"Enter books title(quit to quit): \n";
	std::getline(std::cin, rt.title);
	if(rt.title == "quit")
		return false;
	std::cout<<"Enter books rating: \n";
	std::cin>>rt.rating;
	if(!std::cin)
		return false;
	std::cout<<"Enter books price: \n";
	std::cin>>rt.price;
	if(!std::cin)
		return false;
	
	while(std::cin.get()!='\n')
		continue;
	return true;
}

void ShowReview(const Review & rt)
{
	std::cout<<rt.rating<<"\t"<<rt.price<<"\t"<<rt.title<<std::endl;
}