#include "figuren.h"
#include "blokken_errors.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Blokkendoos : vector<unique_ptr<Figuur>>{
    private:
        unique_ptr<Figuur> max_opp;
        void schrijf(ostream&)const;
    public:
        Blokkendoos();
        Blokkendoos(const string & bestandsnaam);
        unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();
        void push_back(unique_ptr<Figuur> &&figuur);
        friend ostream& operator<<(ostream& out, const Blokkendoos& l){
            l.schrijf(out);
            return out;
        }
};

Blokkendoos::Blokkendoos(const string & bestandsnaam)
{
    ifstream infile;
    infile.open(bestandsnaam);

    if(infile.is_open())
    {
        cout<<"File opened!"<<endl;
        try
        {
        while(!infile.eof())
        {
            unique_ptr<Figuur> tmp(move(lees_figuur(infile)));
            if(tmp)
            {
                push_back(move(tmp));
                cout<<"Added to vector"<<endl;
            }
            else
                throw Figuur_read_error("all figures read!");
        }
        } catch(Figuur_read_error e)
        {
            cout<<e.what()<<endl;
    
        }
    }
    else
    {
        throw File_Not_Opened();
    }
}

unique_ptr<Figuur> Blokkendoos::geef_figuur_met_grootste_oppervlakte()
{
    unique_ptr<Figuur> tmp = move(max_opp);

    int grootste = 0;

    for(int i=0;i<size();i++)
    {
        if(this->operator[](i)->oppervlakte()>this->operator[](grootste)->oppervlakte())
        {
            //iets gevonden wat groter is
            grootste = i;
        }
    }

    //Nu moet het grootste in de vector naar de max_opp vector
    this->operator[](grootste).swap(this->operator[](size()-1));
    max_opp = move(back());
    resize(size()-1);
    return tmp;
}

void Blokkendoos::push_back(unique_ptr<Figuur> &&figuur)
{
    if(!max_opp)
    {
        max_opp = move(figuur);
    }
    else
    {
        cout<<"Maxopp not null"<<endl;
        vector<unique_ptr<Figuur>>::push_back(move(figuur));
        if(operator[](size()-1)->oppervlakte()>max_opp->oppervlakte())
        {
            cout<<"Swap biggest figure"<<endl;
            max_opp.swap(operator[](size()-1));
        }
    }
}

void Blokkendoos::schrijf(ostream &out) const
{
    out<<endl<<"-----------------------------------\nFiguur met grootste oppervlakte:\n--------------------------------------\n"<<*max_opp<<endl;
    out<<"-----------------------------------\nVector met figuren:             \n--------------------------------------\n"<<endl;
    for(int i=0;i<size();i++)
    {
        out<<i<<")\t"<<*(this->operator[](i))<<endl;
    }
    out<<endl;
}
int main(){
    try
    {
        Blokkendoos blokkendoos("figuren.txt");
        cout<<endl<<"ALLE FIGUREN: ";
        cout<<blokkendoos<<endl;
        cout<<endl<<"DE 3 GROOTSTE, van groot naar klein: "<<endl;
        for(int i=0; i<3; i++){
            cout<<"figuur met grootste opp: "<<*blokkendoos.geef_figuur_met_grootste_oppervlakte()<<endl;
        }
        cout<<endl<<"DE NIEUWE BLOKKENDOOS BEVAT DEZE 3 NIET MEER: ";
        cout<<blokkendoos<<endl;
        return 0;
    }
    catch(File_Not_Opened e)
    {
        cout<<"Error: "<<e.what()<<endl;
    }
    catch(Figuur_read_error e2)
    {
        cout<<"Error: "<<e2.what()<<endl;
    }
    catch(...)
    {
        cout<<"Unexpected error..."<<endl;
    }
}


