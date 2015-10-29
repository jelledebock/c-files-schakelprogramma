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
	const int BITS_IN_UINT = sizeof(number)*8;
	int i=0;
	int counter = 0;

	for(i=0;i<BITS_IN_UINT;i++)
	{
		counter += (number & (1 << i))?1:0;	
	}	
	return counter;
}
uint set_bit_at_pos(uint number, int pos)
{
	return number | 1 << (pos-1);	
}

uint unset_bit_at_pos(uint number, int pos)
{
	return number & ~(1<<(pos-1)); 
}

uint toggle_bit_at_pos(uint number, int pos)
{
	return number ^ (1<<(pos-1));	
}

int equal(uint x1, uint x2)
{
	return x1&~x2;
}

int is_even(uint x1)
{
	return (x1 & 1)^1;
}

void swap_even_odd(uint * x)
{
	uint even_mask = 0xAAAAAAAA;
	uint odd_mask = 0x55555555;
	
	*x = (*x & even_mask)>>1 | (*x & odd_mask)<<1;
}

/*Exercise 53.11 checks if in a number only one bit is set*/

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
    printf("Number of bits on in 12: %d\n",num_of_bits_on(12));
    printf("Set bit 2 of 12 on: %d\n",set_bit_at_pos(12,2));
    printf("Unset bit 3 of 12 on: %d\n",unset_bit_at_pos(12,3));
    printf("Toggle bit 3 of 12 on (set to off): %d\n",toggle_bit_at_pos(12,3));
    printf("Toggle bit 2 of 12 on (set to on): %d\n",toggle_bit_at_pos(12,2));
    printf("Equal test (22==22): %d\n",equal(22,22));
    printf("Equal test (22==100): %d\n",equal(22,100));
    printf("Even test (23): %d\n",is_even(23));
    printf("Even test (22): %d\n",is_even(22));
    printf("Even test (10211): %d\n",is_even(10211));
    uint test_swapper = 356;
    printf("Swapping even and odd bits of: \t\t");
    write_bits(test_swapper);
    swap_even_odd(&test_swapper);
    printf("\nResult of swapping even an odd bits: \t");
    write_bits(test_swapper);
    printf("\n");
}
