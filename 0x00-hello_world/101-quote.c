#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 1
 */
int main(void)
{
	const char message[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	size_t message_len = sizeof(message) - 1;

	write(2, message, message_len);

	return (1);
}
