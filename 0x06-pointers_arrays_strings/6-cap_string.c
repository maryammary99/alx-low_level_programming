#include "main.h"
#include <ctype.h>

/**
 * cap_string - Capitalizes all words of a string.
 *
 * @entry: The input string
 *
 * Return: Capitalized string
 */
char *cap_string(char *entry)
{
    int index, count;
    char separators[] = {' ', ',', ';', '.', '!', '?', '"', '(', ')', '{', '}', '\t', '\n', '\0'};

    for (index = 0; entry[index] != '\0'; index++)
    {
        if (entry[index] >= 'a' && entry[index] <= 'z')
        {
            if (index == 0 || entry[index - 1] == ' ' || entry[index - 1] == '\t' ||
                entry[index - 1] == '\n' || entry[index - 1] == ',' ||
                entry[index - 1] == ';' || entry[index - 1] == '.' ||
                entry[index - 1] == '!' || entry[index - 1] == '?' ||
                entry[index - 1] == '"' || entry[index - 1] == '(' ||
                entry[index - 1] == ')' || entry[index - 1] == '{' || entry[index - 1] == '}')
            {
                entry[index] = toupper(entry[index]);
            }
        }

        for (count = 0; separators[count] != '\0'; count++)
        {
            if (separators[count] == entry[index])
            {
                break;
            }
        }
    }

    return (entry);
}

