#include <stdio.h>
#define AANTAL 4
main(){
    int i;
    int nummers [] = {0,10,20,30};
    double getallen [] = {0,1.1,2.2,3.3};
    char tekens [] = {'a','b','c','d'};
    int * ptrs_nr_int[AANTAL];
    double * ptrs_nr_double[AANTAL];
    char * ptrs_nr_char[AANTAL];
    for(i=0; i<AANTAL; i++){
        ptrs_nr_int[i] = nummers+i;
        ptrs_nr_double[i] = &getallen[i];
        ptrs_nr_char[i] = tekens+i;
    }
    printf("sizeof(int) is %d\n",sizeof(int));
    printf("sizeof(double) is %d\n",sizeof(double));
    printf("sizeof(char) is %d\n",sizeof(char));
    printf("sizeof(int*) is %d\n",sizeof(int*));
    printf("sizeof(double*) is %d\n",sizeof(double*));
    printf("sizeof(char*) is %d\n\n",sizeof(char*));
    for(i=0; i<AANTAL; i++){
        printf("%8d %10p %10p %10p \n",nummers[i], &nummers[i], ptrs_nr_int[i], &ptrs_nr_int[i]);
    }
    printf("\n");
    for(i=0; i<AANTAL; i++){
        printf("%8f %10p %10p %10p \n",getallen[i],&getallen[i],ptrs_nr_double[i],&ptrs_nr_double[i]);
    }
    printf("\n");
    for(i=0; i<AANTAL; i++){
        printf("%8c %10p %10p %10p \n",tekens[i], &tekens[i], ptrs_nr_char[i], &ptrs_nr_char[i]);
    }
}
