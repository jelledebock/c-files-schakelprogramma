#include <stdio.h>
#include <stdlib.h>

int multiply(int,int);

int main(int argc, char *argv[])
{
	int num1 = 0;
	int num2 = 0;
	int result = 0;

	if(argc == 3)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
	}
	else 
	{
		printf("Usage: command num1 num2\n");
		return -1;
	}

	result = multiply(num1,num2);
	
	printf("%d x %d = %d\n",num1,num2,result);
	return 0;
}


int multiply(int num1, int num2)
{
	int i=0;
	int result=0;

	for(i=0;i<num2;i++)
	{
		result += num1;
	}	
	return result;
}

