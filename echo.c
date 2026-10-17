#include"minishell.h"
void echo(char *input_string, int status)
{
    if (strcmp(input_string, "echo $$") == 0)
    {
        printf("%d\n", getpid());
    }

    else if (strcmp(input_string, "echo $?") == 0)
    {
        printf("%d\n", status);
    }

    else if (strcmp(input_string, "echo $SHELL") == 0)
    {
        printf("%s\n", getenv("SHELL"));
    }
}