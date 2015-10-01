#include <stdio.h>

void shiftleft(char rij[], int n);

int main()
{
    char rij[]={'s','a','p','a','p','p','e','l'};
    int size = sizeof(rij)/sizeof(char);
    int j;

    shiftleft(rij,size);
    shiftleft(rij,size);
    shiftleft(rij,size);

    for (j = 0; j < size; j++ )
    {
       printf("%c", rij[j] );
    }

    printf("\n");
}

void shiftleft(char rij[], int n)
{
    char first = rij[0];
    int i;

    for(i=1; i<n; i++){
       rij[i-1]=rij[i];
    }

    rij[n-1]=first;
}
