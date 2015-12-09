#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include "containers.h"
#define AANTAL 5
using namespace std;

template<typename T> void oef1()
{

    std::vector<T> v(3,1);
    v.push_back(1);
    v.push_back(3);
    schrijf(v);
    cout<<endl<<endl;
}

void oef2()
{
    queue<string> my_queue;
    my_queue.push("Een");
    my_queue.push("Twee");
    my_queue.push("Drie");
    schrijf(my_queue);
    cout<<endl<<endl;
}

void oef3()
{
    vector<string> vector_array[AANTAL];
    vector_array[1].push_back("aap");
    vector_array[1].push_back("noot");
    vector_array[1].push_back("mies");
    schrijf<string>(vector_array,AANTAL);
    cout<<endl<<endl;
}

void oef4()
{
    //Slecht idee om te gebruiken... Een array kent zijn size niet!
    vector<int[3]> my_vecint;
    cout<<endl<<endl;
}

void oef5()
{
    vector<vector<int> > my_vecint(AANTAL);
    for(int i=0;i<AANTAL;i++)
    {
        for(int j=0;j<i;j++)
        {
            my_vecint[i].push_back(10+j*10);
        }
    }
    //Uitschrijven
    for(int i=my_vecint.size()-1;i>=0;i--)
    {
        cout<<my_vecint[i]<<endl;
    }
    cout<<endl<<endl;

}


void oef6()
{
    vector<vector <int> > my_vec(AANTAL,vector<int>(0));

    for(int i=0;i<AANTAL;i++)
    {
        my_vec[i].push_back(10+i*10);
    }
    schrijf(my_vec);
    cout<<endl<<endl;
}

void oef7()
{
    map<char, set<string> > indexed_word;

    cout<<"Geef een sequentiewoorden in eindig met STOP"<<endl;
    string woord;
    cin>>woord;
    while(woord!="STOP")
    {
        char first_char = woord[0];

        indexed_word[first_char].insert(woord);

        cin>>woord;
    }
    for(map<char, set<string> >::const_iterator iterator = indexed_word.begin();iterator!=indexed_word.end();iterator++)
    {
        cout<<iterator->first<<": bevat "<<iterator->second.size()<<" elementen"<<endl;
    }
    cout<<endl<<endl;
}
void oef8()
{
    map<char, set<string> > indexed_word;

    cout<<"Geef een sequentiewoorden in eindig met STOP"<<endl;
    string woord;
    cin>>woord;
    while(woord!="STOP")
    {
        char first_char = woord[0];

        indexed_word[first_char].insert(woord);

        cin>>woord;
    }

    schrijf(indexed_word);
}

void oef10()
{
    vector<map<char, set<string> > > woordenlijst;
    string woord;
    cin>>woord;
    while(woord!="STOP")
    {
        int lengte = woord.size()+1;
        char first_char = woord[0];
        if(lengte>woordenlijst.size())
        {
            woordenlijst.resize(lengte);
            cout<<"Resizing vector to " <<lengte<<endl;
        }
        woordenlijst[lengte-1][first_char].insert(woord);
        cin>>woord;
    }
    string zoekstring = "sinterklaas";
    cout<<"Searching the words with the same length and the same startchar as " << zoekstring<<endl;
    
    int lengte = zoekstring.size();
    
    if(lengte < woordenlijst.size())
    {
        if(woordenlijst[lengte-1].count(zoekstring[0])==1)
            cout<<woordenlijst[lengte-1][zoekstring[0]]<<endl;
    }
    else
    {
        cout<<"Er staan geen zulke lange woorden in!"<<endl;
    }
}


int main(int argc, char *argv[])
{
    oef1<int>();
    oef2();
    oef3();
    oef4();
    oef5();
    oef6();
    //oef7();
    //oef8();
    oef10();
    return 0;
}



