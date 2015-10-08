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
int main(int argc, char *argv[])
{
   int i=0;
   printf("Dag ");
   if(argc==1)
     printf("allemaal!\n");
   else
   {
      for(i=1;i<argc;i++)
      {
        my_toupper(argv[i]);
        if(i==1)
            printf("%s",argv[i]); 
        else if(i!=1 && i==argc-1)
            printf(" en %s",argv[i]);
        else
            printf(", %s",argv[i]);
      
      }
      printf("!\n");
   }
   return 0;

}

