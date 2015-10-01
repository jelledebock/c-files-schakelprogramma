#include <stdio.h>

void pivoteer(char *begin, char *na_einde, char *pivot)
{
    char *l = pivot;
    char *r = pivot;
    char tmp;

    while(l!=begin && r!=na_einde-1)
    {
        l--;
        r++;

        tmp=l[0];
        *l = r[0];
        *r = tmp;
    }
}

void schrijf(char *begin, char *einde)
{
    char *i=begin;
    printf("----------------\n");
    while(i != einde)
    {
        printf("%c",*i++);
    }
    printf("\n----------------\n");
}

int main()
{
    char tekst[] = {'b','d','?','z','g','o','e','z','e','b',
        ' ','d','i','g','!','h','o','s','v'};
    pivoteer(tekst+7,tekst+12,tekst+9);
    schrijf(tekst+4,tekst+15);
}
