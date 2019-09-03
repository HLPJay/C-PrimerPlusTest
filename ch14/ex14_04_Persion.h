
/*************************************
Persion 
重新制作启动盘  从新装系统
*************************************/

#ifndef EX14_04_PERSION_H_
#define EX14_04_PERSION_H_
#include <string>
using std::string;

//保存名和姓  Show() 
class Persion
{
private:
	string firstName;
	string secondName;
public:
	Persion():firstName("None"), secondName("None") {}
	Persion(string& first, string& second): firstName(first), secondName(second) {}
	Persion(const char* first, const char* second): firstName(first), secondName(second) {}
	Persion(Persion & P);
	Persion & operator = (Persion & p);
	virtual ~Persion(); //加=0纯虚函数是不能构造的
	virtual void Show() const ;
};

//double Draw() 时间 int void Show（） 
class Cunslinger : virtual public Persion
{
private:
	double useTime;
	int number;
public:
	Cunslinger():Persion(),useTime(0), number(0) {}
	Cunslinger(string& first, string& second, double d, int n)
		:Persion(first, second), useTime(d), number(n) {}
	Cunslinger(const char* first, const char* second, double d, int n)
		:Persion(first, second), useTime(d), number(n) {}
	Cunslinger(Persion &p, double d, int n)
		:Persion(p),useTime(d), number(n){}

	Cunslinger(Cunslinger &c);
	Cunslinger & operator= (Cunslinger & c);
	virtual ~Cunslinger();

	double Draw() const;
	void Show() const;
};

class Card
{
	enum Mode {redPeach, spade, square, plumBlossom};
private:
	Mode color;
	int value; 
public:
	Card();//随机生成面色与数值
	~Card();

	Card(Card& c);
	Card &operator=(Card &c);
	void Show() const;
};

//Draw() 1~52的随机数扑克牌（Card 花色和面值）
//使用基类的Show（）
class PokerPlayer:virtual public Persion
{
private:
	Card card;
public:
	PokerPlayer():Persion() { }
	PokerPlayer(Card & c): Persion(), card(c) {}
	PokerPlayer(string& first, string& second, Card & c)
		:Persion(first, second), card(c) {}
	PokerPlayer(const char* first,const char* second, Card & c)
		:Persion(first, second), card(c) {}
	PokerPlayer(Persion & p, Card & c)
		:Persion(p), card(c) {}	

	PokerPlayer(PokerPlayer &c);
	PokerPlayer& operator= (PokerPlayer &p);
	virtual ~PokerPlayer();

	const Card &Draw() const;
	void Show() const;
};

//Gdraw() Cdraw() Show()
class BadDude: public Cunslinger, public PokerPlayer
{
public:
	BadDude():Persion(), Cunslinger(), PokerPlayer() {}
	BadDude(string& first, string& second, double d, int n, Card & c)
		:Persion(first, second), Cunslinger(first, second, d, n), PokerPlayer(first, second, c)
		{}
	BadDude(const char* first, const char* second, double d, int n, Card & c)
		:Persion(first, second), Cunslinger(first, second, d, n), PokerPlayer(first, second, c)
		{}

	BadDude(Cunslinger & cu, Card & c)
		:Persion(cu), Cunslinger(cu), PokerPlayer(cu,c){}
	BadDude(PokerPlayer & po, double d, int n)
		:Persion(po), PokerPlayer(po), Cunslinger(po, d, n)
		{}

	BadDude(BadDude &b);
	BadDude& operator=(BadDude & b);
	virtual ~BadDude(){};

	double Gdraw() const;
	const Card &Cdraw() const;
	void Show() const;
};



#endif //EX14_04_PERSION_H