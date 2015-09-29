#include <stdio.h>

void printexercise(int n)
{
	printf("\n\n------------\nExercise %d\n------------\n\n",n);
}

void oef1(int n)
{
	int i;
	
	printexercise(1);
	printf("Hello world!\n");
	for(i=n;i>=1;i--)
	{
		printf("%d ",i);
	}
	printf("\nSTART");
}

int main(int argc, char **argv)
{
	oef1(10);
}