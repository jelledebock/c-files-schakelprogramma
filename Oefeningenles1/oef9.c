#include <stdio.h>

int main()
{
  char sentence[]="bfroauvto";
  int size = sizeof(sentence)/sizeof(char);
  int i;

  for(i=0;i<size;i++)
  {
    if(i%2==0)
    {
      printf("%c",sentence[i]);
    }
  }
  printf("\n");
}
