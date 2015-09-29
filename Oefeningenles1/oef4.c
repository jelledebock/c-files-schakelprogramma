#include <stdio.h>
#define MAX_FACULTEIT 40
/* Opgave
Schrijf een functie faculteit(x) die de faculteit van een gegeven geheel getal x berekent. Schrijf een procedure schrijf_faculteit(x) die de faculteit van een gegeven geheel getal x uitschrijft.
Roep deze procedure op voor het getal 5. Daarna doe je dit voor alle getallen van 0 (0!=1) tot en met 40. Wat merk je? (Probleem dat zich stelt hoef je niet op te lossen, enkel te constateren.)
*/

int fac(n)
{
  long long result=1;
  while(n>0)
  {
    result*=n;
    n--;
  }
  return result;
}

void schrijffaculteit(n)
{
  int i;
  printf("%d!=",n);
  for(i=n;i>1;i--)
  {
    printf("%d*",i);
  }
  printf("%d=",1);
}

void getfaculteiten()
{
  int i;
  printf("Bereken faculteiten van 0 tot en met %d\n\n",MAX_FACULTEIT);
  for(i=0;i<=MAX_FACULTEIT;i++)
  {
    schrijffaculteit(i);
    printf("%d\n",fac(i));
  }
}

int main()
{
 printf("%d",fac(5));
 getfaculteiten();
 return 0;
}
