#ifndef EX11_06_STONEWT_H_
#define EX11_06_STONEWT_H_

class Stonewt
{
public:
	enum Flag{STONE, INT_FORMAT, DOUBLE_FORMAT};  //TODO:   enum
private:
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
	Flag flag;
public:
	Stonewt(double lbs, Flag falg = STONE);
	Stonewt(int stn, double lbs, Flag falg = STONE);
	Stonewt();
	~Stonewt();

	void stone_mode() { flag = STONE; };
	void int_mode() {flag = INT_FORMAT; };
	void double_mode() {flag = DOUBLE_FORMAT; };
	// void show_lbs() const;
	// void show_stn() const;

	operator int() const;
	operator double() const;
	friend std::ostream & operator<<(std::ostream &os, const Stonewt &t);

	bool operator<(const Stonewt & st) const
    { return pounds < st.pounds; }
    bool operator>(const Stonewt & st) const
    { return pounds > st.pounds; }
    bool operator==(const Stonewt & st) const
    { return pounds == st.pounds; }
    bool operator<=(const Stonewt & st) const
    { return pounds <= st.pounds; }
    bool operator>=(const Stonewt & st) const
    { return pounds >= st.pounds; }
    bool operator!=(const Stonewt & st) const
    { return pounds != st.pounds; }

};//TODO :必须加;

#endif //EX11_06_STONEWT_H_