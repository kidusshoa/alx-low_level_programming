#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
    size_t len = 0;
    listint_t *temp, *current;

    if (!h || !*h)
        return (0);

    current = *h;

    while (current)
    {
        temp = current->next;

        if (temp < current)
        {
            free(current);
            break;  // exit loop to avoid infinite loop (detecting a loop in the list)
        }

        free(current);
        current = temp;
        len++;
    }

    *h = NULL;

    return (len);
}

