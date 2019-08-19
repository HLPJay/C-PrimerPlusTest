#ifndef EX11_01_VECTOR_H_
#define EX11_01_VECTOR_H_
#include <iostream>
#include <cmath>

namespace VECTOR
{
	class Vector
	{
		public:
			enum Mode{RECT, POL};
		private:
			double x;
			double y;
			// double mag;  //矢量的长度
			// double ang; //矢量的方向
			Mode mode;

			// void set_mag();
			// void set_ang();
			// void set_x();
			// void set_y();
		public:
			Vector();
			Vector(double n1, double n2, Mode form = RECT);
			void reset(double n1, double n2, Mode Form = RECT);
			~Vector();

			double xval() const {return x; };
			double yval() const {return y; };
			double magval() const 
			{
			//	return mag; 
				return std::sqrt(x*x+y*y);
			}
			double angval() const 
			{
				// return mag;
				double ang;
				if(x == 0.0&& y == 0.0)
				{
					ang = 0.0;
				}
				else
				{
					ang = std::atan2(x, y); 
				}
				return ang;
			};
			void polar_mode();
			void rect_mode();

			Vector operator+(const Vector & b) const;
			Vector operator-(const Vector & b) const;
			Vector operator-() const;
			Vector operator*(double n) const;

			friend Vector operator*(double n, const Vector &a);
			friend std::ostream & operator<<(std::ostream &os, const Vector &v);

	};
}


#endif