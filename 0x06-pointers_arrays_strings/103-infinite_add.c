#include "main.h"

/**
 * infinite_add - Adds two numbers represented as strings.
 *
 * @n1: The first number as a string
 * @n2: The second number as a string
 * @r: The buffer to store the result
 * @size_r: The size of the buffer
 *
 * Return: A pointer to the result (r) or 0 if result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1, len2, i, sum, carry;

    len1 = 0;
    while (n1[len1] != '\0')
        len1++;

    len2 = 0;
    while (n2[len2] != '\0')
        len2++;

    carry = 0;
    for (i = 0; i < size_r - 1; i++)
    {
        int digit1 = (len1 - 1 >= 0) ? (n1[len1 - 1] - '0') : 0;
        int digit2 = (len2 - 1 >= 0) ? (n2[len2 - 1] - '0') : 0;

        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        r[i] = (sum % 10) + '0';

        if (len1 > 0)
            len1--;

        if (len2 > 0)
            len2--;
    }

    r[i] = '\0';

    if (carry == 1 && i == size_r - 1)
        return (0);

    for (i = 0; i < size_r / 2; i++)
    {
        char tmp = r[i];
        r[i] = r[size_r - 1 - i];
        r[size_r - 1 - i] = tmp;
    }

    return (r);
}

