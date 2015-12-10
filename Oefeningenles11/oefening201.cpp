#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<string> setje = {"Jan","Albert","Pol","Zuzu","Lulu"};
    setje.insert("Abba");
    setje.insert("Aal",setje.end());
    setje.insert("Baai");
    for(auto element:setje)
    {
        cout<<element<<"\t";
    }
    cout<<endl;
    return 0;
}
