#include <stdio.h>
#define MAX_FIB 50
/*
Schrijf een functie fibonacci(x) die het Fibonacci-getal met volgnummer x berekent. De Fi- bonaccigetallen, startend bij volgnummer 1, zijn 1 1 2 3 5 8 13 21 34 55 ... waarbij elk getal de som is van de twee vorige. (Behalve de twee eerste uiteraard, die zijn gewoon 1.) Gebruik geen recursie.
Schrijf een functie fibonacci_rec(x) die hetzelfde doet, maar recursie gebruikt.
Schrijf aan de hand van deze functies alle Fibonacci-getallen van volgnummer 1 tot volgnummer 50 uit. Wat merk je?
*/

int fibonacci(n)
{
  int i;
  int first = 1;
  int second = 1;
  int temp;

  for(i=2;i<n;i++)
  {    
    temp = first+second;
    first = second;
    second = temp;
  }

  return second;   
}

int fibonacci_rec(n)
{
  if(n==1 || n==2)
  {
    return 1;
  }
  return fibonacci_rec(n-2)+fibonacci_rec(n-1);
}

int main()
{
  int i;
  printf("Iterative:\n");
    
  for(i=1;i<MAX_FIB;i++)
  {
    printf("Fibonacci of %d = %d\n",i,fibonacci(i));    
  }
  printf("Recursive:\n");
  for(i=1;i<MAX_FIB;i++)
  {
    printf("Fibonacci of %d = %d\n",i,fibonacci_rec(i));    
  }
   

  return 0;
}
