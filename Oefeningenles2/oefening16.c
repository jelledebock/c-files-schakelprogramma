#include <stdio.h>
/*
Opgave
1. Schrijf een functie met naam index_van(...), die de index teruggeeft van de plaats waarop een gegeven re ̈eel getal in een gegeven array van re ̈ele getallen gevonden wordt. Indien het getal niet aanwezig is, wordt er -1 teruggegeven. Bepaal zelf aantal en aard van de parameters.
2. Schrijf een functie met naam plaats_van(...), die de plaats (pointer) teruggeeft waarop een gegeven re ̈eel getal in een gegeven array van re ̈ele getallen gevonden wordt. Indien het getal niet aanwezig is, wordt de nullpointer teruggegeven.
3. Gebruik beide functies in een kort hoofdprogramma, om je code te testen.
*/
int index_of(int *haystack, int n,int needle);
int * location_of(int *haystack, int n, int needle);

int main(){
    int array[4]={1,3,6,2};   
    printf("Array: {1,3,6,2}\n");
    printf("\nUsing function index_of to get index of 3: %d\n",index_of(array,4,3));
    printf("Using function location_of to get index of 3: %p\n",location_of(array,4,3)); 
    printf("Using pointer dereference to get value of pointer: %d\n",*location_of(array,4,3));
}    

int index_of(int *haystack, int n, int needle)
{
    int i = 0;
    
    while(i<n && haystack[i]!=needle)
    {
      i++;
    }
    return i>n?-1:i;
}

int * location_of(int *haystack, int n, int needle)
{
    int i = 0;
    
    while(i<n && haystack[i]!=needle)
        i++;
  
    return i>n?NULL:&haystack[i];       /* Ook mogelijk is: haystack+i */
}
