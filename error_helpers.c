#include "shell.h"

/**
 * command_error - prints error message when command is not found
 * @NAME: name of program
 * @command: command not found
 *
 */

void command_error(char *NAME, char *command)
{
	write(STDOUT_FILENO, NAME, _strlen(NAME));
	write(STDOUT_FILENO, ": ", 2);
	print_number(errorcount);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command, _strlen(command));
	write(STDOUT_FILENO, ": not found\n", 13);

	exitcode = 127;
}

/**
 * exec_error - prints error message when command fails to execute
 * @NAME: name of program
 * @command: name of command
 */

void exec_error(char *NAME, char *command)
{
	write(STDOUT_FILENO, NAME, _strlen(NAME));
	write(STDOUT_FILENO, ": ", 2);
	perror(command);
}

/**
 * access_error - prints error message if user does not have execute privileges
 * @NAME: name of program
 * @command: name of command
 */

void access_error(char *NAME, char *command)
{
	write(STDOUT_FILENO, NAME, _strlen(NAME));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command, _strlen(command));
	write(STDOUT_FILENO, ": Permission denied\n", 20);
}


/**
 * exit_error - prints message if user inputs an invalid exit status
 * @NAME: name of program
 * @user_input: user input read by program
 */

void exit_error(char *NAME, char *user_input)
{
	char *token;

	token = strtok(user_input, "\n ");
	token = strtok(NULL, "\n ");

	write(STDOUT_FILENO, NAME, _strlen(NAME));
	write(STDOUT_FILENO, ": ", 2);
	print_number(errorcount);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, token, _strlen(token));
	write(STDOUT_FILENO, "\n", 1);
}
