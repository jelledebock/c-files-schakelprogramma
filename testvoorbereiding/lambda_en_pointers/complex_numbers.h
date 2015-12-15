#ifndef c_number
#define c_number

#include <iostream>

using namespace std;
class Complex_num
{
    int i,j;

    public:
    Complex_num(int _i, int _j) : i(_i), j(_j) {};
    Complex_num(int _i) : i(_i), j(0) {};
    Complex_num(string notatie);
    friend Complex_num complex_sum(Complex_num c1, Complex_num c2);
    friend ostream& operator<<(ostream &out, const Complex_num &c);
};

Complex_num complex_sum(Complex_num c1, Complex_num c2) 
{ 
    return Complex_num(c1.i+c2.i,c1.j+c2.j); 
} 

Complex_num::Complex_num(string notatie)
{
    string delim = "+";
    int real = stoi(notatie.substr(0, notatie.find(delim)));
    int complex_part = stoi(notatie.substr(notatie.find(delim)+1,notatie.find("ij")));

    i = real;
    j = complex_part;
}


ostream& operator<<(ostream &out, const Complex_num &cnum)
{
    string complex_part;

    out<<cnum.i;
    
    if(cnum.j!=0)
    {
    out<<"+"<< (cnum.j)<<"j";
    }

    return out;
}

#endif
