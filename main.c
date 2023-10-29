#include "factor.h"

/**
 * factored - factorize given buf
 * @buf: the num read
 * Return: 0
 */
int factored(char *buf)
{
	unsigned long long int x;
	unsigned long long int number;

	number = atoi(buf);
	x = 2;
	while (x < number)
	{
		if (number % x == 0)
		{
			printf("%llu=%llu*%llu\n", number, number / x, x);
			break;
		}
		x++;
	}
	return (0);
}
/**
 * main - main
 * @ac: args count
 * @av: args variables
 * Return: void
 */
int main(int ac, char *av[])
{
	FILE *read;
	ssize_t readline;
	size_t len;
	char *buf = NULL;

	if (ac != 2)
		fprintf(stderr, "Usage: factor <filename>\n"), exit(EXIT_FAILURE);
	read = fopen(av[1], "r");
	if (read == NULL)
		fprintf(stderr, "Error: can't open file %s\n", av[1]), exit(EXIT_FAILURE);
	while (1)
	{
		readline = getline(&buf, &len, read);
		if (readline == -1)
			break;
		factored(buf);
	}
	return (0);

}
