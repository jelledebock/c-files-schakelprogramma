#include <stdio.h>

int main()
{
  char array[]={'s','a','p','p','e','l','m','o','e'};
  char buffer = array[0];
  int arraysize = sizeof(array)/sizeof(char);
  int i;

  for(i=1;i<arraysize;i++)
  {
    array[i-1]=array[i];
  }
  
  array[arraysize-1]=buffer;
  printf("The cleaned up array is: %s\n",array);
  return 0;
}
