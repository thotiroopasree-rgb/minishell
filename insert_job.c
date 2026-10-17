#include "minishell.h"

void insert_job(char *process_name, int child_pid)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new->process_name, process_name);
    new->child_pid = child_pid;
    new->link = NULL;

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        struct node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
}