#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void checkcode(char *);

int main(int argc, char *argv[])
{
    if(argc==2)
    {
        checkcode(argv[1]);
    }
    else
    {
        cout<<"Please specify a valid filename"<<endl;
    }
}

void checkcode(char * filepath)
{
    ifstream input(filepath);
    char character;
    vector<char> brackets = {'{','}','[',']','(',')'};
    stack <char> charstack;
    
    if(input.is_open())
    {
        input >> character;

        while(!input.eof())
        {
            if(find(brackets.begin(), brackets.end(), character) != brackets.end())
            {
                if(charstack.empty())
                    charstack.push(character);
                else if(!charstack.top()+1==character)
                    charstack.push(character);
                else
                    charstack.pop();

            }
            input >> character;
        }
        input.close();
        if(charstack.empty())
        {
            cout<<"All brackets were balanced!"<<endl;
        }
        else
        {
            cout<<"The following brackets weren't balanced : ";
            while(!charstack.empty())
            {
                cout<<" "<<charstack.top();
                charstack.pop();
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"Failed opening the file!"<<endl;
    }
}
