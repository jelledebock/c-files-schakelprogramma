#include <stdio.h>

void my_toupper(char * s)
{
  int offset = 'A'-'a';
  if(*s>='a' &&  *s<='z')
    *s = *s + offset;
  s++;
  while(*s)
  {
    if(*s>='A' && *s<='Z')
      *s = *s - offset; 
    s++;
  }
}
int main()
{
   char woord[] = "wooRdje";
   char input[100]; 
   my_toupper(woord);
   printf("After to upper: %s\n",woord);
   printf("Please enter a string you want to convert to uppercase: ");
   scanf("%100s",input);
   my_toupper(input);
   printf("\nThe word you entered to upper: %s\n",input);
}
