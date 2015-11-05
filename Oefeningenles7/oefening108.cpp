#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct frequency{
    string word;
    int occurences;
};

bool add_or_increment(vector<frequency> &haystack, string word)
{
    for (int i=0; i<haystack.size();i++)
    {
        if(haystack.at(i).word == word)
        {
           haystack.at(i).occurences++;
           return true;
        }
    }
    struct frequency temp = {word,1};
    haystack.push_back(temp);
    return true;
}

int main()
{
    ifstream infile;
    infile.open("lord.txt",ios::in);
    string temp;
    vector<frequency> table;
    while(infile >> temp)
    {
        add_or_increment(table, temp);
    }

    cout<<"Frequenties: "<<endl;

    for(int i=0 ; i<table.size();i++)
    {   
        cout << table.at(i).word << ":" << table.at(i).occurences << endl;
    }
}
