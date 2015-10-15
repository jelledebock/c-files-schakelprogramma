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
	int i=0 ;
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

void vul_aan(struct Deeltal *g)
{
	g->aantal_delers=aantal_delers_van(g->waarde);
	g->delers = delers_van(g->waarde,g->aantal_delers);

}

struct Deeltal * lees_deeltal(struct Deeltal *g)
{
	int getal;
	printf("Geef een geheel getal in: ");
	scanf("%d",&getal);

	g->waarde=getal;
	vul_aan(g);

	return g;
}

struct Deeltal *lees_deeltallen(int aantal)
{
    int i = 0;
    struct Deeltal * deeltallen=malloc(sizeof(struct Deeltal)*aantal);
    for(i=0;i<aantal;i++)
    {
       lees_deeltal(deeltallen+i);                       
    }
    return deeltallen;
}

void schrijf_deeltallen_a(const struct Deeltal * deeltallen,int n)
{
    int i=0;

    for(int i=0; i<n; i++)
    {
        schrijf_deeltal(deeltallen+i);
    }   
}

void schrijf_deeltallen_b(const struct Deeltal * deeltallen,int n)
{
    int i=0;
    int j=0;

    for(int i=0; i<n; i++)
    {
        printf("%d\t%d",(deeltallen+i)->waarde,(deeltallen+i)->delers[0]);
        for(j=1;j<(deeltallen+i)->aantal_delers;j++)
        {
            printf("-%d",(deeltallen+i)->delers[j]);
        }
        printf("\n");                 
    }
}

void schrijf_deeltallen_c(const struct Deeltal * deeltallen, int n)
{
    int i = 0;
    
    for(i=0;i<n;i++)
    {
        schrijf_deeltal(&deeltallen[i]);
    }
}

const struct Deeltal * zoek(int waarde, struct Deeltal const * const * ptr, int aantal)
{
    int i=0;
    for(int i=0; i<aantal; i++)
    {
        if(waarde==(*(ptr)+i)->waarde)
            return *(ptr)+i;
    }
    return 0;
}

void release_memory(struct Deeltal * deeltallen, int n)
{
    int i=0;
    
    for(i=0;i<n;i++)
    {
        free(deeltallen[i].delers);
    }
}

#endif
