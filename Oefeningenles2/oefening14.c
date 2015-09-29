#include <stdio.h>

void wissel(int *a, int *b){
    int hulp;
    printf(" Bij start van de wisselprocedure hebben we a=%i en b=%i.\n",*a,*b);
    hulp = *a;
    *a = *b;
    *b = hulp;
    printf(" Op het einde van de wisselprocedure hebben we a=%i en b=%i.\n",*a,*b);
}

int main(){
    int x, y;
    x = 5;
    y = 10;
    printf("Eerst hebben we x=%i en y=%i.\n",x,y);
    wissel(&x,&y);
    printf("Na de wissel hebben we x=%i en y=%i.\n",x,y);
    return 0;
}
