#include <fstream> // nodig voor volgende oef
#include <vector>  // idem
#include <string>  // idem
#include <cmath>   // idem
#define PI 3.141592653589793238462643383279502884L
#include <stdexcept>

using namespace std;
class Figuur
{
    private:
        virtual void schrijf_soort(ostream & out) const=0;
    public:
        friend ostream& operator<<(ostream& out, const Figuur & f);
        virtual double omtrek() const=0;
        virtual double oppervlakte() const=0;
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

Figuur* lees_figuur(ifstream &in)
{
    string type;
    double arg1,arg2;
    in>>type;

    if(type=="cirkel")
    {
            in>>arg1;
            return new Cirkel(arg1);
    }
    else if(type=="rechthoek")
    {
            in>>arg1;
            in>>arg2;
            return new Rechthoek(arg1,arg2);
    }
    else if(type=="vierkant")
    {
            in>>arg1;
            return new Vierkant(arg1);        
    }
    else return NULL;

}
void lees(vector<Figuur*> &figuren, string filename)
{
    ifstream infile;
    infile.open(filename);
    
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            Figuur *tmp = lees_figuur(infile);
            if(tmp)
                figuren.push_back(tmp);
        }
    }
    else
    {
        throw std::runtime_error("File not opened");
    }
}
