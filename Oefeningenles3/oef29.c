#include <stdio.h>
#include <string.h>

int my_atoi(char * word);

int main(int argc, char *argv[])
{
   int i;
   int sum=0;
   for(i=1;i<argc;i++)
   {
       sum+=my_atoi(argv[i]);
   }
   printf("The sum of the numbers is %d.\n",sum);
}

int my_atoi(char * word)
{
   int buffer=0;
   while(*word)
   {
     buffer = buffer*10+(*word-'0');
     word++;
   }
   return buffer;
}
