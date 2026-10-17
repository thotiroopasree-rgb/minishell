#include "minishell.h"

void extract_external_commands(char **external_commands)
{
    FILE *fptr;
    char command[20];
    int i = 0;

    fptr = fopen("external_cmds.txt", "r");

    if (fptr == NULL)
    {
        printf("File not found\n");
        return;
    }

    while (fscanf(fptr, "%s", command) != EOF)
    {
        external_commands[i] =
            malloc(strlen(command) + 1);

        strcpy(external_commands[i], command);

        i++;
    }

    external_commands[i] = NULL;

    fclose(fptr);
}