#include <stio.h>

typedef struct{
    double x,y;
} punt;

typedef struct{
  punt mp;
  double straal;
} cirkel;

punt lees_punt()
{
   punt p;
   scanf("%lf %lf",&p.x,&p.y);

   return p;
}

cirkel lees_cirkel()
{
    cirkel c;
    c.mp = lees_punt();
    scanf("%lf",&c.straal);

    return c;
}

int op_cirkel(punt p, cirkel c)
{
    //Afstandsformule gebruiken...
}

int main()
{

}
