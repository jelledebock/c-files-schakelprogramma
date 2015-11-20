#include <iostream>
#include <vector>
#include "persoon.h"

using namespace std;

template<typename T>
void schrijf(vector<T> &);

int main(int argc, char *argv[])
{
    vector<int> integers(4,2);
    vector<double> doubles(4,1.5);
    vector<char> chars(4,'c');
    struct Persoon jan = {"Jan",23};
    vector<struct Persoon> personen;
    personen.push_back(jan);
    vector<vector<int> > vector_nest;
    vector_nest.push_back(vector<int>(2,3));
    vector_nest.push_back(vector<int>(1,3));

    cout<<"\n";
    schrijf(integers);
    cout<<"\n";
    schrijf(doubles);
    cout<<"\n";
    schrijf(chars);
    cout<<"\n";
    schrijf(personen);
    cout<<"\n";
    schrijf(vector_nest);
    cout<<"\n";
    return 0;
}

ostream & operator<<(ostream& out, const Persoon & p){
    out<<p.naam<<" ("<<p.leeftijd<<" j)";
    return out;
}

template<typename T>
ostream & operator<<(ostream& out,vector<T> &v)
{
    schrijf(v);
}

template<typename T>
void schrijf(vector<T> &v)
{
    if(v.size()>0)
    {
        cout<<"["<<v[0];
        for (int i = 1; i < v.size(); ++i) {
            cout <<" | "<< v[i] << " ";
        }
        cout<<"]";
    }
}


