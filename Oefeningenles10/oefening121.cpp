#include <iostream>
#include <fstream> // nodig voor volgende oef
#include <vector>  // idem
#include <string>  // idem
#include <cmath>   // idem

using namespace std;

class Rechthoek
{
    public:
        virtual void schrijf(bool newline=true) const;
        virtual double oppervlakte() const;
        virtual double omtrek() const;
        Rechthoek(double lengte, double breedte);
    protected:
        double lengte;
        double breedte;
};

Rechthoek::Rechthoek(double lengte, double breedte):lengte(lengte), breedte(breedte){};

double Rechthoek::oppervlakte() const
{
    return lengte*breedte;
}

double Rechthoek::omtrek() const
{
    return (lengte+breedte)*2;
}

void Rechthoek::schrijf(bool newline) const
{
    cout<<"[RECHTHOEK]"<<endl;
    cout<<"Lengte: "<<lengte<<", breedte: "<<breedte<<endl;
    cout<<"Opervlakte: "<<Rechthoek::oppervlakte()<<", Omtrek: "<<Rechthoek::omtrek();    
    if(newline)
    {
        cout<<endl;
    }
}
class Vierkant : public Rechthoek
{
    public:
        virtual void schrijf(bool newline=true) const;
        Vierkant(double zijde);
};

Vierkant::Vierkant(double zijde):Rechthoek(zijde,zijde){}

void Vierkant::schrijf(bool newline) const
{
    cout<<"[Vierkant]"<<endl;
    cout<<"Zijde: "<<lengte<<endl;
    cout<<"Opervlakte: "<<Vierkant::oppervlakte()<<", Omtrek: "<<Vierkant::omtrek();    
    if(newline)
    {
        cout<<endl;
    }
}



int main(){
    Rechthoek rechthoek(2.2,3); // lengte 2.2, breedte 3
    rechthoek.schrijf();
    Vierkant vierkant(4);       // zijde 4
    vierkant.schrijf(true);
    vector<Rechthoek*> container={ new Rechthoek(3.4,3.7), new Vierkant(2.3), new Rechthoek(3,5) };

    for(Rechthoek *rechthoek: container)
    {
        rechthoek->schrijf();
    }

    return 0;
}
