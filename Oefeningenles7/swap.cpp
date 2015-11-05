#include<iostream>
using namespace std;

void my_swap(int &, int &);

int main()
{
    int x = 1;
    int y = 2;

    cout << "Ervoor: x=" << x << "\t" << "y="<<y<<endl;
    my_swap(x,y);
    cout << "Ervoor: x=" << x << "\t" << "y="<<y<<endl;
}

void my_swap(int &x, int &y)
{
    int h = x;
    x = y;
    y = h;
}
