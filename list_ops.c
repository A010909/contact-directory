#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_ops.h"

// Phone digits
#define DIGITS 12

// Creating contact function
card *create(card *root, char name[30], char phone[DIGITS])
{
    // Card-Memory Allocation and data copying
    card *temp = (card *)malloc(sizeof(card));
    strcpy(temp->name, name);
    strcpy(temp->phone, phone);
    temp->next = NULL;

    if (root == NULL)
        root = temp;
    else
    {
        card *ptr = root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }

    return root;
}

// Display directory contacts
void display(card *root)
{
    if (root == NULL)
        printf("\n\n---Contacts not found---\n\n");
    else
    {
        card *ptr = root;
        printf("###### Contact Directory ######\n\n");
        for (int i = 1; ptr != NULL; i++)
        {
            printf("Index : %d\nName : %s\nPhone : %s\n\n", i, ptr->name, ptr->phone);
            ptr = ptr->next;
        }
    }
}

// Load contacts if exist, create if not
card *load(card *root)
{
    char name[30];
    char phone[DIGITS];
    FILE *file = fopen("contacts.txt", "r");

    if (file == NULL) // If file does not exist
        return root;  // Continue with the list
    else
    {
        // If exists, load it into linked list
        while (fscanf(file, "%[^|]|%[^\n]\n", name, phone) == 2)
            root = create(root, name, phone);

        // Close the file to free meemory
        fclose(file);
        return root;
    }
}