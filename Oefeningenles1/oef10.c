#include <stdio.h>
int getindex(int * row,int size, int number)
{
  int i;
  for(i=0;i<size;i++){
    if(row[i]==number)
      return i+1;
  }
  return -1;
}

int main(){
          int  rij []= {8,4,2,6,0,10};
          int x;
          int idex;

          printf("Geef een geheel getal op  ");
          scanf("%i",&x);
          idex = getindex(rij,sizeof(rij),x);
        if(idex==-1)
              printf("\nHet getal %i werd niet gevonden",idex);
	else
              printf("\nHet getal %i werd gevonden op plaats %i.",x,idex);
        printf("\n");
}
