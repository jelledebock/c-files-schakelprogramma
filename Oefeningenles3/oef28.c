#include <stdio.h>
#include <string.h>

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
   char names[10][50];
   char buffer[50];
   int i=0;
   int j=0;
   printf("Please enter your names, stop with 'STOP': \n");
   scanf("%s",buffer);

   while(strcmp(buffer,"STOP")!=0)
   {
	strcpy(names[i],buffer);
   	scanf("%s",buffer);
	i++;
   }

   printf("Hallo ");
   if(i==0)
     printf("allemaal!\n");
   else
   {
      for(j=0;j<i;j++)
      {
        my_toupper(names[j]);
        if(j==0)
            printf("%s",names[j]); 
        else if(i>0 && j==i-1)
            printf(" en %s",names[j]);
        else
            printf(", %s",names[j]);
      
      }
      printf("!\n");
   }
   return 0;

}

