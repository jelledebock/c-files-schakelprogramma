#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("lord.txt",ios::in);
    char my_char;
    int frequence[26]={0};
    while(!infile.fail())
    {
        infile.get(my_char);

        if(my_char>='a' && my_char<='z')
        {
            frequence[my_char-'a']+=1;          
        }           
    }

    cout<<"Frequenties: "<<endl;

    for(int i=0 ; i<sizeof(frequence)/sizeof(int);i++)
    {   
        cout << (char)('a'+i) << ":" << frequence[i] << endl;
    }
}
