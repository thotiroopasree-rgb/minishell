#include"minishell.h"
char *get_command(char *input_string)
{
    char *command;
    int i = 0;

    command = malloc(30 * sizeof(char));

    while (input_string[i] != ' ' &&
           input_string[i] != '\0' &&
           input_string[i] != '\n')
    {
        command[i] = input_string[i];
        i++;
    }

    command[i] = '\0';

    return command;
}