#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int uint;

char* int2bits(uint x, uint lengte)
{
        char * c = (char*) malloc((lengte+1)*sizeof(char));
        uint i;
        for(i=0; i<lengte; i++){
            c[lengte-1-i] = '0'+(x%2);
            x/=2;
        }
        c[lengte] = 0;
        return c;
}

void schrijf(uint i, uint lengte)
{
        char * bits = int2bits(i,lengte);
        printf("%s %u",bits,i);  /* merk op: %u */
        free(bits);
}

void schrijf_lijstje(uint aantal)
{
     uint lengte = (uint)(log(aantal)/log(2))+1;
     uint i=0;
     for(i=0; i<aantal; i++){
         schrijf(i,lengte);
         printf("\n");
     }
     printf("\n");
}

int main(){
     schrijf_lijstje(25);
           
     printf("\n3     ");  schrijf(3,6);
     printf("\n5     ");  schrijf(5,6);
     printf("\n3^5   ");  schrijf(3^5,6);
     printf("\n3&5   ");  schrijf(3&5,6);
     printf("\n3|5   ");  schrijf(3|5,6);
     printf("\n~3    ");  schrijf(~3,6);
     printf("\n");
     printf("\n1<<1  ");  schrijf(1<<1,6);
     printf("\n1>>1  ");  schrijf(1>>1,6);
     printf("\n8<<1  ");  schrijf(8<<1,6);
     printf("\n8>>1  ");  schrijf(8>>1,6);
     printf("\n");
     printf("\n1     ");  schrijf(1,sizeof(uint)*8);
     printf("\n~1    ");  schrijf(~1,sizeof(uint)*8);
     printf("\n0     ");  schrijf(0,sizeof(uint)*8);
     printf("\n~0    ");  schrijf(~0,sizeof(uint)*8);
                                                      
     return 0;
}
