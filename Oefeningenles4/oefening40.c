#include <stdio.h>
#include <stdlib.h>
#include "deeltal.h"

int main()
{
 	struct Deeltal zes;
	zes.waarde = 153;
	zes.aantal_delers = aantal_delers_van(zes.waarde);
	zes.delers = malloc(sizeof(int)*zes.aantal_delers);
	zes.delers = delers_van(zes.waarde,zes.aantal_delers);
	
	/*Oefening a*/
	printf("6 heeft %d delers.\n",aantal_delers_van(6));

	/*Oefening b*/
	schrijf_deeltal(&zes);
	free(zes.delers);

	/*Oefening 4 test*/
	struct Deeltal een_deeltal;
	lees_deeltal(&een_deeltal);
	schrijf_deeltal(&een_deeltal);
	free(een_deeltal.delers);

    /*Delen 5 en 6 */
    struct Deeltal * deeltallen=lees_deeltallen(5);
    schrijf_deeltallen_a(deeltallen,5);
    schrijf_deeltallen_b(deeltallen,5);
    schrijf_deeltallen_c(deeltallen,5);
    const struct Deeltal * const ptr = zoek(5,&deeltallen,5);
    if(ptr!=0)
    {
        printf("Pointer gevonden\n");
        schrijf_deeltal(ptr);
    }
    else
    {
        printf("Pointer niet gevonden...\n");
    }
    release_memory(deeltallen,5);
    schrijf_deeltallen_a(deeltallen,5);
    
}

