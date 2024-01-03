#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Engineer
{
    char name[50];
    struct Engineer *next;
} Engineer;

Engineer *Create(char *name)
{
    Engineer *New_Engineer = (Engineer *)malloc(sizeof(Engineer));
    strcpy(New_Engineer->name, name);
    New_Engineer->next = NULL;
    return New_Engineer;
}

void Print(Engineer *head)
{
    Engineer *current = head;
    while (current != NULL)
    {
        printf("%s ", current->name);
        current = current->next;
    }
}

void Add(Engineer **head, char *name, int index)
{
    Engineer *New_Engineer = Create(name);
    if (index == 0)
    {
        New_Engineer->next = *head;
        *head = New_Engineer;
    }
    else
    {
        Engineer *current = *head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        New_Engineer->next = current->next;
        current->next = New_Engineer;
    }
}

void Delete(Engineer **head, char *name)
{
    if (*head == NULL)
    {
        return;
    }
    if (strcmp((*head)->name, name) == 0)
    {
        Engineer *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Engineer *current = *head;
    while ((current->next != NULL) && (strcmp(current->next->name, name) != 0))
    {
        current = current->next;
    }
    if (current->next != NULL)
    {
        Engineer *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void Swap(Engineer **head, char *name1, char *name2)
{
    if ((*head == NULL) || (strcmp(name1, name2) == 0))
    {
        return;
    }
    Engineer *prev1 = NULL;
    Engineer *prev2 = NULL;
    Engineer *current = *head;
    while ((current != NULL) && (prev1 == NULL || prev2 == NULL))
    {
        if ((current->next != NULL) && (strcmp(current->next->name, name1) == 0))
        {
            prev1 = current;
        }
        if ((current->next != NULL) && (strcmp(current->next->name, name2) == 0))
        {
            prev2 = current;
        }
        current = current->next;
    }
    if (prev1 == NULL || prev2 == NULL)
    {
        return;
    }
    Engineer *temp = prev1->next;
    prev1->next = prev2->next;
    prev2->next = temp;
    temp = prev1->next->next;
    prev1->next->next = prev2->next->next;
    prev2->next->next = temp;
}

int main()
{
    int n;
    int Number_changes;
    scanf("%d", &n);

    Engineer *head = NULL;
    for (int i = 0; i < n; i++)
    {
        char name[50];
        scanf("%s", name);
        Add(&head, name, i);
    }

    scanf("%d", &Number_changes);
    for (int i = 0; i < Number_changes; i++)
    {
        char Cases[10];
        scanf("%s", Cases);
        if (strcmp(Cases, "add") == 0)
        {
            char name[50];
            int index;
            scanf("%s %d", name, &index);
            Add(&head, name, index);
        }
        else if (strcmp(Cases, "delete") == 0)
        {
            char name[50];
            scanf("%s", name);
            Delete(&head, name);
        }
        else if (strcmp(Cases, "swap") == 0)
        {
            char name1[50], name2[50];
            scanf("%s %s", name1, name2);
            Swap(&head, name1, name2);
        }
    }

    Print(head);

    
}