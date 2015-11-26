#include <cmath>
#include <ostream>
#include "breuk.h"

using namespace Breuk_namespace;

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


Breuk::Breuk(int teller, int noemer): teller(teller), noemer(noemer){}

Breuk::Breuk(int teller)
{
    this->teller = teller;
    noemer = 1;
}
Breuk Breuk::operator+(Breuk& breuk)
{
    int deler = ggd(this->noemer, breuk.noemer);

    return Breuk((teller+breuk.teller)*deler,deler);
}

Breuk Breuk::operator-(Breuk& breuk)
{
    int deler = ggd(this->noemer, breuk.noemer);

    return Breuk((teller-breuk.teller)*deler,deler);
}

Breuk Breuk::operator*(Breuk& breuk)
{
    return Breuk(teller*breuk.teller,noemer*breuk.noemer);
}

Breuk Breuk::operator/(Breuk& breuk)
{
    return Breuk(teller*breuk.noemer,noemer*breuk.teller);
}

Breuk& Breuk::operator+=(Breuk& breuk)
{
    int deler = ggd(noemer, breuk.noemer);

    teller = (teller + breuk.teller)*deler;
    noemer = deler;

    return *this;
}

Breuk& Breuk::operator-=(Breuk& breuk)
{
    int deler = ggd(noemer, breuk.noemer);

    teller = (teller - breuk.teller)*deler;
    noemer = deler;

    return *this;
}

Breuk& Breuk::operator*=(Breuk& breuk)
{
    teller = teller*breuk.teller;
    noemer = noemer*breuk.noemer;

    return *this;
}

Breuk& Breuk::operator/=(Breuk& breuk)
{
    teller = teller*breuk.noemer;
    noemer = noemer*breuk.teller;

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

std::ostream& Breuk_namespace::operator<<(std::ostream& os, const Breuk& breuk)
{
    os << breuk.getTeller() << "/" << breuk.getNoemer();

    return os;
}
