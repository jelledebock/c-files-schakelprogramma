#include "figuren.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Blokkendoos : vector<unique_ptr<Figuur>>{
    private:
        unique_ptr<Figuur> max_opp;
    public:    
        void schrijf(ostream&) const;
    public:
        Blokkendoos();
        Blokkendoos(const string & bestandsnaam);
        unique_ptr<Figuur> geef_figuur_met_grootste_oppervlakte();
        void push_back(unique_ptr<Figuur> && figuur);
        friend ostream& operator<<(ostream& out, const Blokkendoos& l){
            l.schrijf(out);
            return out; }
};

void Blokkendoos::push_back(unique_ptr<Figuur> && figuur){
    if(!max_opp)
        max_opp=move(figuur);
    else
    {
        push_back(move(figuur));
        if(operator[](size()-1)->oppervlakte()>max_opp->oppervlakte())
        {
            max_opp.swap(operator[](size()-1)); 
        }
    }
}

unique_ptr<Figuur> Blokkendoos::geef_figuur_met_grootste_oppervlakte()
{
    int index_tweede_grootste = 0;

    for(int i=1;i<size();i++)
    {
        if(operator[](i)->oppervlakte()>operator[](index_tweede_grootste)->oppervlakte())
        {
            index_tweede_grootste = i;
        }
    }

    operator[](index_tweede_grootste).swap(operator[](size()-1));
    unique_ptr<Figuur> hulpptr;
    hulpptr.swap(max_opp);
    max_opp.swap((*this)[size()-1]);
    resize(size()-1);

    return move(hulpptr);
}
Blokkendoos::Blokkendoos(){}
Blokkendoos::Blokkendoos(const string & bestandsnaam){
    ifstream input(bestandsnaam);
    string soort;
    input >> soort;   
    while (!input.fail() ){
        if (soort == "rechthoek"){
            double lengte, breedte;
            input >> lengte >> breedte;
            push_back((unique_ptr<Figuur>)new Rechthoek(lengte,breedte));     
        }
        else if(soort == "vierkant"){
            double zijde;
            input >> zijde;
            push_back((unique_ptr<Figuur>)new Vierkant(zijde));         
        }   
        else if(soort == "cirkel"){
            double straal;
            input >> straal;     
            push_back((unique_ptr<Figuur>)new Cirkel(straal));
        }
        else{
            string c;
            getline(input,c);  // om overschot in te lezen
        }
        input >> soort;      
    }    
    input.close();
}

void Blokkendoos::schrijf(ostream& out) const
{
    for(int i=0;i<size();i++)
    {
        out<<endl<<" "<<i<<" ";
        out<<*(this->operator[](i));
    }
    out<<endl<<"MAX"<<*max_opp;
}


int main(){
    Blokkendoos blokkendoos("figuren.txt");
    cout<<endl<<"ALLE FIGUREN: ";
    cout<<blokkendoos<<endl;
    cout<<endl<<"DE 3 GROOTSTE, van groot naar klein: "<<endl;
    for(int i=0; i<3; i++){
        cout<<"figuur met grootste opp:    "<<*blokkendoos.geef_figuur_met_grootste_oppervlakte()<<endl;
    }
    cout<<endl<<"DE NIEUWE BLOKKENDOOS BEVAT DEZE 3 NIET MEER: ";
    cout<<blokkendoos<<endl;
    return 0; 
}
