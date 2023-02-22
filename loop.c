#include "main.h"

/**
 * main - initialization of shell
 *
 * @ac: argument count
 * @av: array of arguments
 * @env: environment
 *
 * Return: 0 if success, -1 if failure
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	(void)av;
	loop();
	return (0);
}

/**
 * loop - shell prompt loop
 *
 * Return: void
 */
void loop(void)
{
	char *buffer, **argv, *command;
	int looped;

	looped = 0;
	buffer = NULL;
	while (1)
	{
		_puts("$ ");
		if (_getline(&buffer) != -1)
		{
			if (buffer[0] != '\n' && buffer[0] != '#')
			{
				argv = _strtok(buffer);
				command = argv[0];
				if (check_built_in(argv, buffer) == -1)
				{
					output_cmd(argv);
				}
				if (check_arg(command, argv[0]) == 0)
					free(argv);
				else
					free_array(argv);
				looped++;
			}
		}
		else
		{
			free(buffer);
			_putchar('\n');
			_exit(0);
		}
	}
}
