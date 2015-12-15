#include<iostream>
#include <fstream>
#include <functional>
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

template<typename T>
T reken_l(T x, T y, function <T (T x, T y)> lambda)
{
    return lambda(x,y);
}

int main()
{
    //Met function pointer
    cout<<"Met functie pointers:"<<endl;
    cout<<"3+4="<<reken_p<int>(3,4,som_int)<<endl;
    cout<<"3.5+4.1="<<reken_p<double>(3.5,4.1,som_double)<<endl;
    cout<<"jel+le="<<reken_p<string>("jel","le",som_string)<<endl;
    cout<<"(5-6j) + (1+3j)="<<reken_p<Complex_num>(Complex_num("5+-6j"),Complex_num("1+3i"),complex_sum)<<endl;
    cout<<endl<<endl;
    //Met lambdas
    cout<<"Met lambda uitdrukkingen"<<endl;
    cout<<"3+4="<<reken_l<int>(3,4,[](int x, int y)->int{return x+y;})<<endl;
    cout<<"3.5+4.1="<<reken_l<double>(3.5,4.1,[](double x, double y)->double{return x+y;})<<endl;
    cout<<"jel+le="<<reken_l<string>("jel","le",[](string x, string y)->string{return x+""+y;})<<endl;
    cout<<"(5+j)+(1+4j)="<<reken_l<Complex_num>(Complex_num("5+1i"),Complex_num("1+4j"),[](Complex_num x, Complex_num y)->Complex_num{return complex_sum(x,y);})<<endl;
    cout<<"(1+5j)+(10+4j)="<<reken_l<Complex_num>(Complex_num("1+5i"),Complex_num("10+4j"),[](Complex_num x, Complex_num y)->Complex_num{return x+y;})<<endl;
    cout<<"(5j)+(10)="<<reken_l<Complex_num>(Complex_num("0+5i"),Complex_num("10+0j"),[](Complex_num x, Complex_num y)->Complex_num{return x+y;})<<endl;
}


