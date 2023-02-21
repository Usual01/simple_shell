#include "main.h"

/**
 * make_args - make array of pointer arguments
 *
 * @input: User input to be turned into arguments
 *
 * Return: argument list
 */
char **_strtok(char *input)
{
	char **args, *arg, *pos, *delims;
	int i, wc;

	pos = NULL;
	delims = "\n\t \r\a";
	i = 0;
	wc = wordcount(input);
	args = smart_alloc(sizeof(char *) * (wc + 1));
	arg = tokenize(input, delims, &pos);
	while (arg != NULL)
	{
		args[i] = arg;
		if (args[i][0] == '#')
			break;
		arg = tokenize(NULL, delims, &pos);
		i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * wordcount - count the number of words in a string
 *
 * @str: string
 *
 * Return: number of words in @str
 */
int wordcount(char *str)
{
	int wc, state, i;

	i = wc = 0;
	state = OUT;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '\0':
		case ' ':
		case '\t':
		case '\n':
			if (state == IN)
			{
				state = OUT;
				wc++;
			}
			i++;
			break;
		default:
			state = IN;
			i++;
		}
	}
	return (wc);
}


/**
 * check_arg - Compare the original first argument to
 * a possible new first argument
 *
 * @firstarg: The original first argument
 * @arg0: The argument that may have changed
 *
 * Return: 0 if they're the same, 1 if they are different
 */
int check_arg(char *firstarg, char *arg0)
{
	int len;

	len = 0;
	while (firstarg[len] != '\0')
		len++;
	if (_strncmp(firstarg, arg0, len) == 0)
		return (0);
	return (1);
}
/**
 * tokenize - create a token from @input
 *
 * @input: string to tokenize
 * @delim: delimitor string
 * @saveptr: save pointer
 *
 * Return: the next token found in @input string
 */
char *tokenize(char *input, const char *delim, char **saveptr)
{
	char *token;
	int i;

	i = 0;
	if (input == NULL)
		input = *saveptr;
	input += _strspn(input, delim);
	if (*input == '\0')
	{
		*saveptr = input;
		return (NULL);
	}
	token = input;
	input = _strpbrk(input, delim);
	if (input == NULL)
	{
		while (token[i] != '\0')
			i++;
		*saveptr = token + i;
	}
	else
	{
		*input = '\0';
		*saveptr = input + 1;
	}
	return (token);
}
