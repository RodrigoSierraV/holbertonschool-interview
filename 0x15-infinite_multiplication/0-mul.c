#include "holberton.h"

/**
 * main - multiplies two positive numbers
 *@argc: Counts arguments in argv
 *@argv: Strings after exe
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, j, res, len_1, len_2, len_3, *int_1, *int_2, *ans, z1 = 0, z2 = 0;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
		error();
	len_1 = str_len(argv[1]);
	len_2 = str_len(argv[2]);
	len_3 = len_1 + len_2;
	ans = malloc(len_3 * sizeof(int));
	int_1 = check_digits(argv[1], len_1);
	int_2 = check_digits(argv[2], len_2);

	for (j = 0; j < len_1; j++)
		z1 += int_1[j];
	for (j = 0; j < len_2; j++)
		z2 += int_2[j];
	for (i = 0; i < len_2; i++)
		for (j = 0; j < len_1; j++)
			ans[i + j] = ans[i + j] + int_2[i] * int_1[j];
	for (i = 0; i < len_3; i++)
	{
		res = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + res;
	}
	if (z1 == 0 || z2 == 0)
		_putchar('0');
	else
	{
		for (i = len_3 - 1; i >= 0; i--)
			if (i != len_3 - 1 || ans[i] != 0)
				_putchar(ans[i] + '0');
	}
	_putchar('\n');
	free(int_1);
	free(int_2);
	free(ans);
	return (0);
}

/**
 * error - because we have only putchar and no printf
 * Return: Nothing
 */
void error(void)
{
	int e;
	char err[] = "Error";

	for (e = 0; e <= 4; e++)
		_putchar(err[e]);
	_putchar('\n');
	exit(98);
}

/**
 * str_len - value the longitud of string
 *
 * @s: Pointer to string
 * Return: longitud of string
 */

int str_len(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
		i++;
	return (i);
}

/**
 * check_digits - checks all digits in string
 * @s: Pointer to string
 * len: length of s
 * Return: pointer to int
 */
int *check_digits(char *s, int len)
{
	int *int_s, i, j;

	int_s = malloc(len * sizeof(int));
	for (i = len - 1, j = 0; i >= 0; i--, j++)
	{
		int_s[j] = s[i] - '0';
		if (int_s[j] < 0 || int_s[j] > 9)
			error();
	}
	return (int_s);
}
