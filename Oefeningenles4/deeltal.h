#ifndef deeltal
#define deeltal
#include <math.h>
#include <stdio.h>


struct Deeltal
{
	int waarde;
	int aantal_delers;
	int * delers;
};

void schrijf(int * array,int n)
{
	int i=0;
  	printf("%d",array[0]);
	for(i=1;i<n;i++)
	{
		printf("-%d",array[i]);
	}
	printf("\n");
}

void schrijf_deeltal(const struct Deeltal *getal)
{
	printf("%d\t",getal->waarde);
	schrijf(getal->delers,getal->aantal_delers);
}

int aantal_delers_van(int x)
{
	int i =-1 ;
	int getal = 1;

	while(getal<=(int)sqrt((double)x))
	{
		if(x%getal==0)
			i+=2;
		getal++;
	}
	return i;
}
int * delers_van(int x, int n)
{
	int i=1;
	int * delers = malloc(sizeof(int)*n);

	while(i<=(int)sqrt((double)x))
	{
		if(x%i==0)
		{
			*(delers++)=i;
			*(delers++)=x/i;
		}
		i++;
	}
	return delers-n;
}
#endif
