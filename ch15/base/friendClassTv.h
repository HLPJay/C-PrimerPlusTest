
#ifndef FRIEND_CLASS_TV_H_
#define FRIEND_CLASS_TV_H_

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
public:
	Remote(int m = Tv::TV): mode(m) {}
	bool volup(Tv & t) {return t.volup(); }
	bool voldown(Tv & t) {return t.voldown(); }
	void onoff(Tv & t) {return t.onoff(); }
	void chanup(Tv & t) {return t.chanup(); }
	void chandown(Tv & t) {return t.chandown(); }
	void set_chan(Tv & t, int c) {t.channel = c; } //只有这个用到友元类 可以用友元函数来实现
	void set_mode(Tv & t) {return t.set_mode(); } 
	void set_input(Tv & t) {return t.set_input(); } 
};

#endif