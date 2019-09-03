#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
};

bool operator<(const Review& r1, const Review & r2);
bool worseThan(const Review& r1, const Review & r2);
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

		sort(books.begin(), books.end());
		cout<<"Sorted By title: \nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		cout<<"Sorted By Rating: \nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());  //随机选取概率相同
		cout<<"Sorted By shuffling: \nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
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

bool FillReview(Review & rt)
{
	std::cout<<"Enter books title(quit to quit): \n";
	std::getline(std::cin, rt.title);
	if(rt.title == "quit")
		return false;
	std::cout<<"Enter books rating(quit to quit): \n";
	std::cin>>rt.rating;
	if(!std::cin)
		return false;
	while(std::cin.get()!='\n')
		continue;
	return true;
}

void ShowReview(const Review & rt)
{
	std::cout<<rt.rating<<"\t"<<rt.title<<std::endl;
}