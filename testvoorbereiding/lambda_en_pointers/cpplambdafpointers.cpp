#include<iostream>
#include <fstream>
#include "complex_numbers.h"

using namespace std;

int som_int (int x, int y)
{
    return x+y;
}

double som_double (double x, double y)
{
    return x+y;
}


string som_string (string x, string y)
{
    return x+""+y;
}

template<typename T>
T reken_p(T x, T y, T (*fp)(T, T))
{
    return (*fp)(x,y);
}

int main()
{
    //Met function pointer
    cout<<"3+4="<<reken_p<int>(3,4,som_int)<<endl;
    cout<<"3.5+4.1="<<reken_p<double>(3.5,4.1,som_double)<<endl;
    cout<<"jel+le="<<reken_p<string>("jel","le",som_string)<<endl;
    cout<<"(5+6j) + (1+3j)="<<reken_p<Complex_num>(Complex_num("5+6j"),Complex_num("1+3i"),complex_sum)<<endl;
    //Met lambdas
    //cout<<"3+4="<<telop_l(3,4)<<endl;
    //cout<<"3.5+4.1="<<telop_l(3.5,4.1)<<endl;
    //cout<<"al+lah="<<telop_l("al","lah")<<endl;
}


