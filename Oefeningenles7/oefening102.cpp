#include <iostream>
#include <string>
using namespace std;

int main()
{
    char letter;
    string woord;
    char * woordchar;

    cin >> letter;
    while(letter != 'X')
    {
        cout << "*" << letter << "*" << endl;
        cin >> letter;
    }
    letter = cin.get();
    while(letter != 'X')
    {
        cout << "*" << letter << "*" << endl;
        letter = cin.get();    
    }
    getline(cin, letter);
    while(letter != 'X')
    {
        cout << "*" << letter << "*" << endl;
        getline(cin,letter);    
    }
    cin >> woord;
    while(woord != "X")
    {
        cout << "*" << woord << "*" << endl;
        cin >> woord;
    }
    woord=cin.get();
    while(woord != "X")
    {
        cout << "*" << woord << "*" << endl;
        woord=cin.get();
    }
    getline(cin,woord);
    while(woord != "X")
    {
        cout << "*" << woord << "*" << endl;
        getline(cin,woord);
    }

    cin >> *woordchar;
    while(*woordchar != 'X')
    {
        cout << "*" << *woordchar << "*" << endl;
        cin >> *woordchar;
    }
    *woordchar=cin.get();
    while(*woordchar != 'X')
    {
        cout << "*" << *woordchar << "*" << endl;
        *woordchar=cin.get();
    }
    getline(cin,*woordchar);
    while(*woordchar != 'X')
    {
        cout << "*" << *woordchar << "*" << endl;
        getline(cin,*woordchar);
    }
}
