#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the unsigned long integer to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int i;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	/* from the most significant bit and iterate through each bit */
	for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--)
	{
		unsigned long int mask = 1UL << i;
		char bit = (n & mask) ? '1' : '0';

		_putchar(bit);
	}
}
