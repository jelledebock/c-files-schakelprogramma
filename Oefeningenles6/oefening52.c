#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

void schrijf(uint x)
{
    uint i;

    for(i=x;i>0;i--)
    {
        printf("\t%u",i);
    }
}

void schrijf_step(uint x, uint stap)
{
    /*Opmerking:
     *het probleem is hier dat een unsigned int enkel positieve waardes kan aannemen.
     *hierdoor kan het dat door een step af te trekken van de vorige je "zogezegd onder
     *nul gaat". Wat er dan feitelijk gebeurt is dat je naar de maximale waarde dat een
     *uint kan aannemen gaat. Hierdoor begint de loop in feite opnieuw met aftellen.
     */

    printf("\t%u",x);
    while(x>stap)
    {
        x-=stap;
        printf("\t%u",x);
    }
}

int main()
{
    schrijf(5);
    printf("\n");
    schrijf_step(5,2); 
    printf("\n");
}
