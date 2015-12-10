#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
    string woorden = "Jan Jaap Klaas Pieter Jelle Yoni Abraham Valere";
    set<string> alfabetisch;

    istringstream stream(woorden);
    string word;

    while(stream>>word)
    {
        alfabetisch.insert(word);    
    }
    
    set<string>::const_iterator it;

    for(it=alfabetisch.begin();it!=alfabetisch.end();it++)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;

    return 0;
}
