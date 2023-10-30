#include "factor.h"
/**
 * factored - factorize given buf
 * @buf: the num read
 * Return: 0
 */
int factored(char *buf)
{
mpz_t x, number, divided;

mpz_init(number);
mpz_init(x);
mpz_init(divided);
mpz_set_str(number, buf, 10);
mpz_set_ui(x, 2);
while (mpz_cmp(x, number) < 0)
{
if (mpz_divisible_p(number, x))
{
mpz_div(divided, number, x);
gmp_printf("%Zd=%Zd*%Zd\n", number, divided, x);
break;
}
mpz_add_ui(x, x, 1);
}
mpz_clear(x);
mpz_clear(number);
mpz_clear(divided);
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
