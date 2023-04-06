include "main.h"

/**
 * flip_bits - calculates the number of bits needed to be flipped
 * to get from one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits needed to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int flip_count = 0;

	while (xor_result > 0)
	{
		if (xor_result & 1)
			flip_count++;

		xor_result >>= 1;
	}

	return (flip_count);
}
