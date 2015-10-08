#include <stdio.h>
#include <string.h>
#define AANTAL_WOORDEN            10
#define GEMIDDELDE_LENGTE_WOORDEN  7
#define LENGTE_ARRAY_T  AANTAL_WOORDEN * GEMIDDELDE_LENGTE_WOORDEN

void lees(char *pt[]){
   int i=0;
   char *t = pt[0];
   scanf("%s",t);
   t=t+strlen(t)+1;

   for(i=1;i<AANTAL_WOORDEN;i++)
   {
      pt[i]=t;
      scanf("%s",t);
      t=t+strlen(t)+1;
   }
}

void schrijf(char *pt[]){
   int i=0;
   
    for(int i=0; i<AANTAL_WOORDEN; i++)
    {
       printf("%s\n",pt[i]);
    }
}
    
int main(){
    char* pt[AANTAL_WOORDEN];
    char t[LENGTE_ARRAY_T];
    pt[0] = t;
    printf("Geef %d woorden in:\n",AANTAL_WOORDEN);
    lees(pt);     /* leest alle woorden in                 */
    schrijf(pt);  /* schrijft alle woorden onder elkaar uit*/
return 0; 
    }

