#include <stdio.h>

/*
Schrijf een procedure zoek_extremen(...) die op zoek gaat naar het minimum en maximum
in een array van gehele getallen. Het type en de aard van de parameters bepaal je zelf. In het
hoofdprogramma zorg je voor een hardgecodeerde array, en je schrijft het minimum en maximum
uit. Test kritisch!
Implementeer beide versies: met indexering en met schuivende pointers*/

void search_extrema(int haystack[], int n, int *min, int *max);
void search_extremap(int haystack[], int n, int *min, int *max);

int main(){
    int array[] = {1,500,2,700,300,800,4,5,3};
    int min=array[0];
    int max=array[0];
    int minsp=9999;
    int maxsp=0;
    int size = sizeof(array)/sizeof(int);

    search_extrema(array, size, &min, &max);
    search_extremap(array, size, &minsp, &maxsp);

    printf("\n[WITH INDEXES]\nMaximum of array: %d, \nMinimum of array: %d\n\n",max,min);
    printf("\n[WITH SHIFTING POINTERS]\nMaximum of array: %d, \nMinimum of array: %d\n\n",maxsp,minsp);
}

void search_extrema(int haystack[], int n, int *min, int *max)
{
    int i;
  
    for(i=1;i<n;i++)
    {
        if(haystack[i]>*max)
            *max = haystack[i];
        if(haystack[i]<*min)
            *min = haystack[i];
    }
}

void search_extremap(int haystack[], int n, int *min, int *max)
{
   int *pint=haystack;
   int value;

   while(pint!=haystack+n)
   {
       value = *(pint++);
       if(value<*min)
            *min = value;
       else if(value>*max)
            *max = value;       
   }

}
