#include "minishell.h"


#include "minishell.h"

void scan_input(char *prompt, char *input_string)
{
    while (1)
    {
        printf("%s", prompt);

        memset(input_string, '\0', 100);

        if (fgets(input_string, 100, stdin) == NULL)
        {
            printf("\n");
            return;
        }

        copy_change(prompt, input_string);

        /* Ignore empty input */
        if (input_string[0] == '\0')
        {
            continue;
        }

        if (strncmp(input_string, "PS1=", 4) == 0)
        {
            strcpy(prompt, input_string + 4);
        }
        else
        {
            char *command;
            int type;

            command = get_command(input_string);

            type = check_command_type(command);

            if (type == BUILTIN)
            {
                execute_internal_commands(input_string);
            }
            else if (type == EXTERNAL)
            {
                pid = fork();

                if (pid == -1)
                {
                    printf("Fork failed\n");
                }
                else if (pid == 0)
                {
                    signal(SIGINT, SIG_DFL);
                    signal(SIGTSTP, SIG_DFL);

                    execute_external_cmd(input_string);

                    exit(0);
                }
                else
                {
                    int status;

                    if (waitpid(pid, &status, WUNTRACED) > 0)
                    {
                        if (WIFSTOPPED(status))
                        {
                            printf("\n[%d] stopped\n", pid);

                            insert_job(command, pid);
                        }
                    }
                }
            }
            else
            {
                printf("Command not found\n");
            }

            free(command);
        }
    }
}
