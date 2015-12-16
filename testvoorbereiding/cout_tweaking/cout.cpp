#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<<1<<endl;
    cout<<setw(8)<<1<<endl;
    cout<<setw(8)<<right<<1<<left<<endl;
    cout<<setw(8)<<internal<<1<<left<<endl;
    cout<<setw(8)<<hex<<1024<<endl;
    cout<<setw(8)<<oct<<1024<<endl;
}
