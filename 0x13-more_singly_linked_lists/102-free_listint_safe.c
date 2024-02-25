#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
 
typedef struct listint_t {
    int data;
    struct listint_t *next;
} listint_t;

size_t free_listint_safe(listint_t **h) {
    size_t size = 0;
    listint_t *current = *h;
    listint_t *temp;

    while (current != NULL) {
        size++;
        temp = current;
        current = current->next;

        // Check if the current node has been visited before
        if (temp == *h) {
            *h = NULL;  // Set the head to NULL to avoid potential dangling pointers
            break;      // Exit loop to avoid infinite loop (detecting a loop in the list)
        }

        free(temp);  // Free the current node
    }

    return size;
}

// Example usage:
int main(void) {
    listint_t *head = malloc(sizeof(listint_t));
    head->data = 1;
    head->next = malloc(sizeof(listint_t));
    head->next->data = 2;
    head->next->next = malloc(sizeof(listint_t));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Creating a loop for testing
    head->next->next->next = head->next;

    size_t size_freed = free_listint_safe(&head);

    printf("Size of the list freed: %zu\n", size_freed);
    printf("Head after freeing: %p\n", (void *)head);

    return 0;
}

