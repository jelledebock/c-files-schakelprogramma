#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

int bit_i(uint x, int i)
{
    /*Gets the bit status of the bit at position i in uint x */
    return (1 << (i-1) & x?1:0);
}

void write_bits(uint number)
{
    /*A proc that outputs the bit notation of a number
     *using bit operators...
     */
    const int BITS_IN_UINT = sizeof(number)*8;
    int bit  = 1;

    for(bit = BITS_IN_UINT ; bit>=0 ; bit--)
    {
        printf("%d",number&(1 << bit)?1:0);
    }
}

uint uint_bit_on_at_pos(int i)
{
    /* Returns a uint with the only bit which is one at position i */
    return 1 << (i-1);
}

int num_of_bits_on(uint number)
{
    return 0;
}

int main()
{
    printf("Bit at position 2 of 2: %d\n",bit_i(2,2));
    printf("Bit at position 1 of 2: %d\n",bit_i(2,1));
    printf("Binary print of 128: ");
    write_bits(128);
    printf("\n");
    printf("Binary print of 12: ");
    write_bits(12);
    printf("\n");
    printf("Uint with bit 1 at position 13: %u\n",uint_bit_on_at_pos(13));
}
