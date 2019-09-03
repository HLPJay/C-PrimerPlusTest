#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <stdexcept>
#include <string>
#include <iostream>
#include <cmath> 

class arg_error : public std::logic_error
{
private:
    double arg1;
    double arg2;
    std::string fname;

public:
    arg_error(double a1 = 0.0, double a2 = 0.0, std::string f = "none",
              std::string msg = "invalid arguments\n")
        : logic_error(msg), arg1(a1), arg2(a2), fname(f)
    {
    }

    void mesg() const;
};

class hmean_error : public arg_error
{
public:
    hmean_error(double a1 = 0.0, double a2 = 0.0, std::string f = "none",
                std::string msg = "invalid arguments\n")
        : arg_error(a1, a2, f, msg)
    {
    }
};

class gmean_error : public arg_error
{
public:
    gmean_error(double a1 = 0.0, double a2 = 0.0, std::string f = "none",
                std::string msg = "invalid arguments\n")
        : arg_error(a1, a2, f, msg)
    {
    }
};

inline void arg_error::mesg() const
{
    std::cout << arg1 << ", " << arg2 << ", " << fname << std::endl;
}

#endif


double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {                  // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (hmean_error & he)    // start of catch block
        {
            he.mesg();
            cout << "Try again.\n";
            continue;
        }                  
        catch (gmean_error & ge) 
        {
            ge.mesg();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
        catch (arg_error & ae)
        {
            ae.mesg();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw hmean_error(a, b, "hmean()");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw gmean_error(a, b, "gmean()");
    return std::sqrt(a * b); 
}