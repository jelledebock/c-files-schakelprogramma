#include <cmath>
#include <ostream>
#include "breuk.h"

using namespace std;

static int ggd(int a, int b){
    if(a < 0 || b < 0){
        return ggd(abs(a),abs(b));
    }
    if(a < b){
        return ggd(b,a);
    }
    if(b == 0){
        return a; }
    if(b == 1){
        return b;
    }
    return ggd(b,a%b);
}

bool is_stambreuk(Breuk& breuk)
{
    return (breuk.getTeller()/ggd(breuk.getTeller(),breuk.getNoemer())==1?true:false);
}

Breuk::Breuk(): teller(0), noemer(0){}

Breuk::Breuk(int teller, int noemer): teller(teller), noemer(noemer){}

Breuk::Breuk(int teller):teller(teller), noemer(1){}

Breuk Breuk::operator+(Breuk& breuk)
{
    int new_teller = teller*breuk.noemer+breuk.teller*noemer;
    int new_noemer = noemer*breuk.noemer;

    int deler = ggd(new_teller,new_noemer);

    return Breuk(new_teller/deler,new_noemer/deler);
}

Breuk Breuk::operator-(Breuk& breuk)
{
    int new_teller = teller*breuk.noemer-breuk.teller*noemer;
    int new_noemer = noemer*breuk.noemer;

    int deler = ggd(new_teller,new_noemer);

    return Breuk(new_teller/deler,new_noemer/deler);
}

Breuk Breuk::operator*(Breuk& breuk)
{
    int new_teller = teller*breuk.teller;
    int new_noemer = noemer*breuk.noemer;

    int deler = ggd(new_teller,new_noemer);

    return Breuk(new_teller/deler, new_noemer/deler);
}

Breuk Breuk::operator/(Breuk& breuk)
{
    int new_teller = teller*breuk.noemer;
    int new_noemer = noemer*breuk.teller;

    int deler = ggd(new_teller, new_noemer);

    return Breuk(new_teller/deler,new_noemer/deler);
}

Breuk& Breuk::operator+=(Breuk& breuk)
{
    int new_teller = teller*breuk.noemer+breuk.teller*noemer;
    int new_noemer = noemer*breuk.noemer;

    int deler = ggd(new_teller,new_noemer);

    teller = new_teller/deler;
    noemer = new_noemer/deler;

    return *this;
}

Breuk& Breuk::operator-=(Breuk& breuk)
{
    int new_teller = teller*breuk.noemer-breuk.teller*noemer;
    int new_noemer = noemer*breuk.noemer;

    int deler = ggd(new_teller,new_noemer);

    teller = new_teller/deler;
    noemer = new_noemer/deler;

    return *this;
}

Breuk& Breuk::operator*=(Breuk& breuk)
{
    teller = teller*breuk.teller;
    noemer = noemer*breuk.noemer;

    int deler = ggd(teller,noemer);

    teller = teller/deler;
    noemer = noemer/deler;

    return *this;
}

Breuk& Breuk::operator/=(Breuk& breuk)
{
    teller = teller*breuk.noemer;
    noemer = noemer*breuk.teller;

    int deler = ggd(teller,noemer);

    teller = teller/deler;
    noemer = noemer/deler;

    return *this;
}

int Breuk::getTeller() const
{
    return teller;
}

int Breuk::getNoemer() const
{
    return noemer;
}

std::ostream& operator<<(std::ostream &out, const Breuk& breuk)
{
    out << breuk.getTeller();
    if(breuk.getNoemer()!=1)
        out << "/" << breuk.getNoemer();

    return out;
}

std::istream& operator>>(std::istream &in, Breuk& breuk)
{
    char c;
    in>>breuk.teller>>c>>breuk.noemer;

    return in;    
}

bool Breuk::operator==(const Breuk& breuk)
{
    int deler = ggd(noemer, breuk.noemer);

    if(teller*deler==breuk.teller*deler && noemer*deler==breuk.noemer*deler)
    {
        return true;
    }
    return false;
}

Breuk& Breuk::vermenigvuldigd_met(const Breuk& breuk) 
{
    int new_teller = teller*breuk.getTeller();
    int new_noemer = noemer*breuk.getNoemer();

    int deler = ggd(new_teller,new_noemer);

    teller=new_teller/deler;
    noemer=new_noemer/deler;

    return *this;
}
