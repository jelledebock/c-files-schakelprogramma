#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTE 5 

char * lees_woord()
{
	 char * woord=malloc(sizeof(char)*MAX_LENGTE);

	 printf("%s\n","Voer een woord in:");
	 scanf("%s",woord);

	 return woord;
}

int main()
{
	int i = 1;
	char * woord = lees_woord();
	while(i<5 && strcmp(woord,"STOP")!=0){
		printf("Woord ingevoerd: %s\n",woord);
		free(woord);
		woord = lees_woord();
		i++;
	}
	free(woord);
}
