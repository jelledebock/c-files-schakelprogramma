#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* WARNING!
 * Bad code: This code will cause a memory leak. If you do not want to ruin
 * you current pc session please do not run this program ;-)
 */
char * memory_leak(int n)
{
	char num[2];
	sprintf(num,"%d",n);
	char * leak = malloc(sizeof(char)*1000000);
	strcpy(leak,num);
	return leak;
}

int main()
{
	int i=0;
	int n=1500000;

	for(i=0;i<n;i++)
	{
		char * leak = memory_leak(i);
		printf("%s\t",leak);
	}
}
