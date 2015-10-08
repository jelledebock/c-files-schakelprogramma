#include <stdio.h>
#include <string.h>

int my_atoi(char * word);

int main(int argc, char *argv[])
{
   int i;

   for(i=1;i<argc;i++)
   {
	   printf("Number %d \n",my_atoi(argv[i]));
   }
}

int my_atoi(char * word)
{
   int buffer=0;
   while(*word)
   {
     buffer = buffer*10+ (*word-'0');
     word++;
   }
   return buffer;
}
