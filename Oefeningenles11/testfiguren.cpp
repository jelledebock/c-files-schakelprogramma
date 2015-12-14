#include "figuren.h"
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<Figuur*> figuren;
    try
    {
        lees(figuren,"figuren.txt");
    
        for(Figuur *figuur:figuren)
            cout<<*figuur<<endl;
    }
    catch(std::runtime_error& e)
    {
        cerr<<e.what()<<endl;
    }
}
