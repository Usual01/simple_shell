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
	size_t size;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	size = 0;
	looped = 0;
	buffer = NULL;
	while (1)
	{
		inchild = 0;
		_puts("$ ");
		if (getline(&buffer, &size, stdin) != -1)
		{
			if (buffer[0] != '\n' && buffer[0] != '#')
			{
				argv = _strtok(buffer);
				command = argv[0];
				if (check_builtins(argv, buffer) == -1)
				{
					inchild = 1;
					output(argv);
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

/**
 * sighandler - Print out the prompt if ctrl-C is hit
 * @sig_num: Unused variable necessary for sighandler function types
 */
void sighandler(int sig_num)
{
	(void)sig_num;
	if (inchild == 0)
		_puts("\n$ ");
	signal(SIGINT, sighandler);
}
