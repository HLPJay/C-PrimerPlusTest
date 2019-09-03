#include <cstdlib> 
#include <ctime>
#include <iostream>
#include "ex14_04_Persion.h"

Persion::Persion(Persion & P)
{
	firstName = P.firstName;
	secondName = P.secondName;
}

Persion & Persion::operator = (Persion & p)
{
	if(this == &p)
	{
		return *this;
	}
	firstName = p.firstName;
	secondName = p.secondName;
}

Persion::~Persion()
{}

void Persion::Show() const
{
	std::cout<<"fullName:"<<secondName<<"  "<<firstName<<std::endl;
}


Cunslinger::Cunslinger(Cunslinger &c)
	:Persion(c)
{
	useTime = c.useTime;
	number = c.number;
}

Cunslinger & Cunslinger::operator= (Cunslinger & c)
{
	if(this == &c)
	{
		return *this;
	}
	Persion::operator=(c);
	useTime = c.useTime;
	number = c.number;
}

Cunslinger::~Cunslinger(){}

double Cunslinger::Draw() const
{
	return useTime;
}

void Cunslinger::Show() const
{
	Persion::Show();
	std::cout<<"useTime:"<<useTime;
	std::cout<<"\nnumber:"<<number<<std::endl;
}

Card::Card()
{
	std::srand(std::time(0));
	color = static_cast<Mode>(std::rand()%4);  //TODO 强制类型转换
	value = std::rand()%13+1;
}

Card::Card(Card& c)
{
	color = c.color;
	value = c.value;
}

Card &Card::operator=(Card &c)
{
	if(this == &c)
	{
		return *this;
	}
	color = c.color;
	value = c.value;
}

Card::~Card()
{}

void Card::Show() const 
{

	switch(color)
	{
		case redPeach :
			std::cout<<"Card::color"<<redPeach<<"  redPeach  ";
			break;
		case spade :
			std::cout<<"Card::color"<<spade<<"  spade  ";
			break;
		case square :
			std::cout<<"Card::color"<<square<<"  square  ";
			break;
		case plumBlossom :
			std::cout<<"Card::color"<<plumBlossom<<"  plumBlossom  ";
			break;
		default:
			std::cout<<"ERROR！";
	}
	std::cout<<"Card::value:"<<value<<std::endl;
}


PokerPlayer::PokerPlayer(PokerPlayer &c)
{
	Persion::operator=(c);
	card = c.card;
}

PokerPlayer& PokerPlayer::operator= (PokerPlayer &p)
{
	if(this == &p)
	{
		return *this;
	}
	Persion::operator=(p);
	card = p.card;
}

PokerPlayer::~PokerPlayer()
{

}

const Card &PokerPlayer::Draw() const
{
	return card;
}

void PokerPlayer::Show() const
{
	Persion::Show();
	card.Show();
}

BadDude::BadDude(BadDude &b)
	:Persion(b), Cunslinger(b), PokerPlayer(b)
{
}

BadDude& BadDude::operator=(BadDude & b)
{
	if(this == &b)
	{
		return *this;
	}
	Persion::operator=(b);
	Cunslinger::operator=(b);
	PokerPlayer::operator=(b);
}

double BadDude::Gdraw() const
{
	return Cunslinger::Draw();
}

const Card & BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

void BadDude::Show() const
{
	Persion::Show();
	Cunslinger::Show();
	PokerPlayer::Show();
}