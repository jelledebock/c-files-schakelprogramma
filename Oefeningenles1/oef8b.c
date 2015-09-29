#include <stdio.h>

/*
Schrijf een functie cijfersom(x) die van een gegeven geheel getal x de som van de cijfers berekent. Zo is cijfersom(12345) gelijk aan 15. Doe dit zonder bewerkingen op karaktertekens, gebruik enkel het type int (en wat wiskunde uit de lagere graad).
*/

int cijfersom(int x)
{
  int sum = 0;

  while(x!=0)
  {
    sum+=x%10;
    x=x/10;     
  }
  return sum;
}

int cijfersom_herhaald(int x)
{
  x = cijfersom(x);
  
  while(x/10!=0)
  {
    x = cijfersom(x);
  }

  return x;
}

int cijfersom_recursive(int x)
{
  if(x/10==0)
   return x;
  return cijfersom_recursive(cijfersom(x));
}

int main()
{
  int number = 1234578992;
  printf("The sum of the numbers of %d is %d\n",number,cijfersom(number)); 
  printf("The repetitive sum of the numbers of %d is %d\n",number,cijfersom_herhaald(number));
  printf("The repetitive iterative sum of the numbers of %d is %d\n",number,cijfersom_recursive(number));
  
  return 0;
}
