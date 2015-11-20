#include <stdio.h>
#include <string.h>

void sorteer(void *, int, int,int (*comparator)( void *, void *));
int vergelijk_int(int *, int *);

int main(int argc, char *argv[])
{
    int test_array[] = {5,15,6,8,9,1};
    printf("Voor sortering: \n");
    print_array_int(test_array,sizeof(test_array)/sizeof(int));
    sorteer(&test_array, sizeof(test_array)/sizeof(int), sizeof(int), vergelijk_int);
    printf("Na sortering: \n");
    print_array_int(test_array,sizeof(test_array)/sizeof(int));

}

void sorteer(void *array, int aantal, int grootte, int (*comparator)(void *, void *))
{
    /*Insertion sort*/

    int i=0,j=0;
    void *tmp=malloc(grootte);

    for(i=1;i<aantal;i++)
    {
        j=i-1;
        memcpy(tmp,array+(i*grootte),grootte);
        while(j >= 0 && comparator(array+(j*grootte),tmp)>0)
        {
            /*Schuif alles wat kleiner is 1'tje op */
            /*j komt op de plaats van j+1*/
            memcpy(array+(j+1)*grootte,array+j*grootte,grootte);
            j--; 
        }
        memcpy(array+(j+1)*grootte,tmp,grootte);
    }
    free(tmp); 
}

int vergelijk_int(int *a, int *b)
{
    return (int)*a-(int)*b;
}

void print_array_int(void * array, int size)
{
    int * hulp = (int *)array;
    int i = 0;

    for(i=0;i<size;i++)
    {
        printf("Index %d: %d\n",i,hulp[i]);
    }
}
