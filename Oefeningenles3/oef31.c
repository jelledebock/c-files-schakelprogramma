#include <stdio.h>
#include "persoon.h"

persoon geef_oudste(persoon personen[], int n);

int main()
{
    persoon personen[3]={{"Jarno",21},{"Jos",68},{"Maria",91}};
    int i=0;

    for(i=0; i<sizeof(personen)/sizeof(persoon);i++)
    {
        printf("%s is %d jaren oud.\n",personen[i].name,personen[i].age);
    }

    persoon oudste = geef_oudste(personen, sizeof(personen)/sizeof(persoon));

    printf("De oudste is %s met een leeftijd van %d jaren",oudste.name, oudste.age);
}

persoon geef_oudste(persoon personen[], int n)
{
    int i=1;
    persoon oudste=personen[0];
    while(i<n)
    {
        if(oudste.age<personen[i].age)
            oudste = personen[i];
        i++;
    }           
    return oudste;
}
