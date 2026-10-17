#include "minishell.h"

void print_jobs(void)
{
    struct node *temp = head;
    struct node *prev = NULL;
    int status;
    pid_t result;

    while (temp != NULL)
    {
        result = waitpid(temp->child_pid, &status, WNOHANG);

        if (result == temp->child_pid)
        {
            if (prev == NULL)
                head = temp->link;
            else
                prev->link = temp->link;

            free(temp);

            if (prev == NULL)
                temp = head;
            else
                temp = prev->link;
        }
        else
        {
            printf("[%d] %s\n", temp->child_pid, temp->process_name);

            prev = temp;
            temp = temp->link;
        }
    }
}