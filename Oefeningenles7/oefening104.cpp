#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    for(int i=0; i<65; i++)
    {
        cout<<setw(5)<<i<<setw(5)<<oct<<setw(5)<<i<<hex<<setw(5)<<i;
        cout<<dec << endl;
    }
}
