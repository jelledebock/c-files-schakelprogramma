#include <stdio.h>
#define N 64

void printexercise(int n)
{
	printf("\n\n------------\nExercise %d\n------------\n\n",n);
}

void oef2(int n)
{
	int i;
	
	printexercise(2);
	printf("Printing decimal octal and decimal representation up to number %d\n\n",N);
	printf("%-20s%-20s%-20s\n","Decimal","Octal","Hexadecimal");
	
	for(i=0;i<=n;i++)
	{
		printf("%20d%20o%20x\n",i,i,i);
	}
}

int main(int argc, char **argv)
{
	oef2(64);
	return 0;
}