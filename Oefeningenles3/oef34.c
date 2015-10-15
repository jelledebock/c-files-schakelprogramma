#include <stdio.h>
#include "persoon.h"

persoon geef_oudste(persoon personen[], int n);

void schrijf_cstring(const void * person)
{
       const persoon *helper = person;
       printf("%s",helper->name);
}

void schrijf_int(const void * person)
{
   const persoon *helper = person;

   printf("%d",helper->age);
}

void schrijf_persoon(const void * person)
{
  const persoon *helper = person;

  printf("%s (%d)",helper->name, helper->age);
}

void schrijf_array(void * array, int aantal, int grootte, char tussenteken,
                            void (*schrijf)(const void*));

int main()
{
    persoon personen[3]={{"Jarno",21},{"Jos",68},{"Maria",91}};
    int i=0;

    for(i=0; i<sizeof(personen)/sizeof(persoon);i++)
    {
        printf("%s is %d jaren oud.\n",personen[i].name,personen[i].age);
    }

    persoon oudste = geef_oudste(personen, sizeof(personen)/sizeof(persoon));

    printf("De oudste is %s met een leeftijd van %d jaren\n\n",oudste.name, oudste.age);
    
    schrijf_array(personen, sizeof(personen)/sizeof(persoon),sizeof(persoon), '+', schrijf_int);
    schrijf_array(personen, sizeof(personen)/sizeof(persoon),sizeof(persoon), ';', schrijf_cstring);
    schrijf_array(personen, sizeof(personen)/sizeof(persoon),sizeof(persoon), '\n', schrijf_persoon);

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


void schrijf_array(void * array, int aantal, int grootte, char tussenteken,
                            void (*schrijf)(const void*))
{
    int i=0;
    while(i<aantal-1)
    {
       schrijf(&array[i*grootte]);
       printf("%c",tussenteken);   
       i++;       
    }
    schrijf(&array[i*grootte]);
    printf("\n");
}
