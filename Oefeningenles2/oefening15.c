#include <stdio.h>

void write(int array[],int n);

int main()
{
    printf("Function in main\n");
    //Subopdracht 1
    int gehele_getallen[8]={0};
    int array_size =sizeof(gehele_getallen)/sizeof(int); 
    int i;
    //Subopdracht 2
    printf("Lengte array: %d\n",array_size);
    //Subopdracht 3
    for(i=0;i<array_size;i++)
    {
        printf("Array element at index %d : %d\n",i,gehele_getallen[i]);
    }
    printf("Using the write function\n");
    write(gehele_getallen,array_size);
}

void write(int array[],int n){
    int i;

    for(i=0;i<n;i++)
    {
        printf("Array element at index %d : %d\n",i,array[i]);
    }
    
}
