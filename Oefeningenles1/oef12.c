#include <stdio.h>

int main()
{
  int parameters[]={1,0,5,-1,7};
  int i;
  double x,result,acc;
  int numparams = sizeof(parameters)/sizeof(int);

  printf("Please enter a value for x: \n");
  scanf("%lf",&x);
  acc=1;

  for(i=numparams-1;i>=0;i--)
  {
    result+=acc*parameters[i];
    acc=acc*x;   
  }
  
  printf("The function value of %f is %f\n",x,result);  
}
