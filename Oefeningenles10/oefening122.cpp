#include <iostream>
#include <fstream> // nodig voor volgende oef
#include <vector>  // idem
#include <string>  // idem
#include <cmath>   // idem
#define PI 3.141592653589793238462643383279502884L

using namespace std;
class Figuur
{
    private:
        virtual double omtrek() const=0;
        virtual double oppervlakte() const=0;
        virtual void schrijf_soort(ostream & out) const=0;
    public:
        friend ostream& operator<<(ostream& out, const Figuur & f);
};

ostream& operator<<(ostream& out, const Figuur & f){
    f.schrijf_soort(out);
    out<<" met omtrek "<<f.omtrek()<<" en oppervlakte "<<f.oppervlakte()<<endl;
    return out;
}

class Rechthoek : public Figuur
{
    public:
        Rechthoek(double lengte, double breedte);
    protected:
        virtual double oppervlakte() const;
        virtual double omtrek() const;
        virtual void schrijf_soort(ostream & out) const;
        double breedte;
        double lengte;
};

Rechthoek::Rechthoek(double lengte, double breedte):lengte(lengte), breedte(breedte){}

double Rechthoek::oppervlakte() const
{
    return lengte*breedte;
}

double Rechthoek::omtrek() const
{
    return (lengte+breedte)*2;
}

void Rechthoek::schrijf_soort(ostream &out) const
{
    out<<"Rechthoek"<<endl;
}    

class Vierkant : public Rechthoek
{
    public:
        Vierkant(double zijde);
    protected:
        virtual void schrijf_soort(ostream & out) const;       
};

Vierkant::Vierkant(double zijde):Rechthoek(zijde,zijde){}

void Vierkant::schrijf_soort(ostream &out) const
{
    out<<"Vierkant"<<endl;    
}

class Cirkel: public Figuur
{
    private:
        double radius;
        double oppervlakte() const;
        double omtrek() const;
        void schrijf_soort(ostream &out) const;
    public:    
        Cirkel(double radius);
};

Cirkel::Cirkel(double radius):radius(radius){}

double Cirkel::oppervlakte() const
{
    return radius*radius*PI;
}

double Cirkel::omtrek() const
{
    return radius*2*PI;
}

void Cirkel::schrijf_soort(ostream &out) const{
    out<<"cirkel"<<endl;
}
int main(){
    vector<Figuur*> container={ new Rechthoek(3.4,3.7), new Vierkant(2.3), new Rechthoek(3,5) };

    for(Figuur *rechthoek: container)
    {
        cout<<*rechthoek;
    }

    return 0;
}
