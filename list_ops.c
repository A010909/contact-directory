#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_ops.h"

// Creating contact function
card *create(card *root, char name[30], char phone[11])
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

    // Confirmation text
    printf("Contact Added Successfully\n");

    return root;
}

// Display directory contacts
void display(card *root)
{
    if (root == NULL)
        printf("No Contacts");
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