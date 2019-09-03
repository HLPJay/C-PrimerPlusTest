/**************************
互为友元会排斥  冲突
**************************/
#ifndef FRIEND_CLASS_TV_15_01_H_
#define FRIEND_CLASS_TV_15_01_H_
#include <iostream>

class Remote;
class Tv
{
public:
	friend class Remote;
	enum { Off, On};
	enum { MinVal, MaxVal = 20};
	enum { Antenna, Cable};
	enum { TV, DVD};

	Tv(int s=Off, int mc = 125)
		: state(s), volume(5), maxchannel(mc) , channel(2), mode(Cable), input(TV) {}
	void onoff() { state=(state == On)?Off:On; }
	bool ison() const { return state == On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {mode = (mode == Antenna )?Antenna:Cable; }
	void set_input() {input =(input = TV) ? TV : DVD;}
	void settings() const;

	bool set_model(Remote & r, int i) ;//{r.model = i;}
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

class Remote
{
private:
	int mode;
	int model;
public:
	friend class Tv;
	enum {Normal, Interactive};

	Remote(int m = Tv::TV): mode(m), model(Normal) {}
	bool volup(Tv & t) {return t.volup(); }
	bool voldown(Tv & t) {return t.voldown(); }
	void onoff(Tv & t) {return t.onoff(); }
	void chanup(Tv & t) {return t.chanup(); }
	void chandown(Tv & t) {return t.chandown(); }
	void set_chan(Tv & t, int c) {t.channel = c; } //只有这个用到友元类 可以用友元函数来实现
	void set_mode(Tv & t) {return t.set_mode(); } 
	void set_input(Tv & t) {return t.set_input(); } 

	void show_model() const { std::cout<<" model:"<< model<<std::endl; }
};

#endif



bool Tv::volup()
{
	if(volume <MaxVal)
	{
		volume++;
		return true;
	}
	return true;
}

bool Tv::voldown()
{
	if(volume <MinVal)
	{
		volume--;
		return true;
	}
	return true;
}

void Tv::chanup()
{
	if(channel <maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 1;
	}
}

void Tv::chandown()
{
	if(channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;
	}
}

void Tv::settings() const
{
	std::cout<<"TV is "<<(state == Off?"off":"on")<<std::endl;
	if(state == On)
	{
		std::cout<<"volume settings: "<< volume<<std::endl;
		std::cout<<"channel settings: "<< channel<<std::endl;
		std::cout<<"Mode = "<< (mode == Antenna? "Antenna" :"Cable")<<std::endl;
		std::cout<<"Input = "<< (input==TV? "TV": "DVD")<<std::endl;
	}
}

bool Tv::set_model(Remote & r, int i) //{r.model = i;}
{
	if(state == On)
	{
		r.model = i;
		return true;
	}
	return false;
}


int main(void)
{
	Tv s42;
	std::cout<<"initial setting for 42 TV: \n";
	s42.settings();
	s42.onoff();
	s42.chanup();

	std::cout<<"\nAdjusted setting for 42 TV: \n";
	s42.chanup();
	std::cout<<"\nAdjusted setting for 42 TV: \n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	std::cout<<"\nsetting after for 42 TV by Remote: \n";
	s42.settings();
	std::cout<<"test:::"<<std::endl;    grey.show_model();
	s42.set_model(grey, 1);
	std::cout<<"test:::"<<std::endl;    grey.show_model();
	s42.set_model(grey, Remote::Interactive);
	std::cout<<"test:::"<<std::endl;    grey.show_model();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 42);
	std::cout<<"\n\n 58 settings: \n";
	s58.settings();
	return 0;
}