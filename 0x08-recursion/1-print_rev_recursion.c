#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse using recursion.
 * @s: The input string to be printed in reverse.
 */
void _print_rev_recursion(char *s)
{
    if (*s)
    {
        _print_rev_recursion(s + 1); // Call the function recursively with the next character in the string.
        _putchar(*s); // Print the current character.
    }
}

