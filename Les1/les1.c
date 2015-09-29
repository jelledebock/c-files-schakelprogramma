#include <stdio.h>
#include <stdlib.h>

void sizearray()
{
    int test[7];
    printf("Num of bytes of test: %d \n",sizeof(test));
    printf("Array size of test: %d. ",sizeof(test)/sizeof(int));
}

char* pointertest()
{
    char *pointer = "This is a pointer";
    return pointer;
}

/* Method to empty input buffer */
void empty_buffer()
{
    while(getchar()!='\n');
}

int do_pow(int i)
{
	/* Is veel beter dan de math functie pow te gebruiken omdat er
	 * intern recursie gebruikt wordt en de waarde bij benadering 
	 * berekend wordt. Is enkel handig voor reële machten.
	 */
	return i*i*i;

}

int main()
{
    sizearray();
    char * text = pointertest();
    printf("\nOutput of pointer: %s\n",text);
	printf("3x3x3=%d",do_pow(3)); 
    return 0;
}
