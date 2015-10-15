#include <stdio.h>
#include <stdlib.h>
#include "deeltal.h"

int main()
{
 	struct Deeltal zes;
	zes.waarde = 6;
	zes.aantal_delers = 3;
	zes.delers = malloc(sizeof(int)*zes.aantal_delers);
	zes.delers[0]=1;
	zes.delers[1]=2;
	zes.delers[2]=3;
	/* Oefening b */
	schrijf(zes.delers,zes.aantal_delers);
	/* Oefening c */
	schrijf_deeltal(&zes);
	free(zes.delers);
}

