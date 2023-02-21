#include "main.h"

/**
 * check_built_in - Check to see if given command is a builtin
 * @args: Array holding command and all its arguments
 * @input: The user input received from getline
 *
 * Return: the return value of the builtin called on success,
 * or -1 if it failed
 */
int check_built_in(char **args, char *input)
{
	builtins_t builtins[] = {
		{"exit", my_exit},
		{"env", _printenv},
		{"unsetenv", _unsetenv},
		{"setenv", _setenv},
		{"help", _help},
		{NULL, NULL}
	};
	int i, len;

	len = _strlen(args[0]);
	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strncmp(args[0], "exit", 4) == 0)
			return (builtins[0].func(args, input));
		if (_strncmp(args[0], builtins[i].name, len) == 0)
			return (builtins[i].func(args));
	}
	return (-1);
}
