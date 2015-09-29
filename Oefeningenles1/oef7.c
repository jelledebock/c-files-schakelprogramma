#include <stdio.h>
#include<math.h>

#define PI 3.1415
#define ACCURACY 0.00001

/*
Zoek op hoe een computer of zakrekenmachine de sinus uitrekent van een gegeven getal. (Zeker weten dat-ie dat niet doet door een goniometrische cirkel te tekenen, en de ordinaat van het snijpunt van het ene been van de hoek met de cirkel af te passen!) Maak nu je eigen mijn_sinus- functie die van een gegeven kommagetal de sinus berekent. (Staat de gevraagde parameter in graden of radialen, denk je?) Opgelet: we kijken naar effici ̈entie van je berekeningen! Vergelijk ook met het resultaat van de ingebouwde sinusfunctie uit de bibliotheek math.h.
*/
double calculate_sin(double x)
{
   double result=x;
   double noemer=1;
   double teller=x;
   int n = 1;
   double teken = -1;

   while(teller/noemer>ACCURACY)
   {
     /*printf("Step %d: accuracy = %f",n,teller/noemer);*/
     teller=teller*x*x;
     noemer=noemer*n*2*(n*2+1);
     
     result += (teken*(teller/noemer));
     teken = -teken;

     n++;
   }

   return result; 
}

int main()
{
  double value = 1.235; 
  printf("My own sin(%.5f)=%.5f\n",value,calculate_sin(value));
  printf("Math sin(%.5f)=%.5f\n",value,sin(value));
  return 0;
}
