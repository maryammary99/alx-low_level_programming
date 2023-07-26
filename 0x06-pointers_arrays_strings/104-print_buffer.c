#include "main.h"

/**
 * print_buffer - Prints the content of a buffer
 *
 * @b: The buffer to be printed
 * @size: The number of bytes to print from the buffer
 */
void print_buffer(char *b, int size)
{
    int i, j;

    for (i = 0; i < size; i += 10)
    {
        _putchar('0' + ((i >> 24) & 0xFF));
        _putchar('0' + ((i >> 16) & 0xFF));
        _putchar('0' + ((i >> 8) & 0xFF));
        _putchar('0' + (i & 0xFF));
        _putchar(':');
        _putchar(' ');

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
            {
                _putchar('0' + ((unsigned char)b[i + j] >> 4));
                _putchar('0' + ((unsigned char)b[i + j] & 0xF));
            }
            else
            {
                _putchar(' ');
                _putchar(' ');
            }

            if (j % 2 != 0)
                _putchar(' ');
        }

        for (j = 0; j < 10; j++)
        {
            if (i + j >= size)
                break;

            if (b[i + j] >= 32 && b[i + j] <= 126)
                _putchar(b[i + j]);
            else
                _putchar('.');
        }

        _putchar('\n');
    }

    if (size <= 0)
        _putchar('\n');
}

