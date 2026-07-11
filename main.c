#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_ops.h"

int main()
{
    char name[30];
    char phone[11];
    card *root = NULL;
    int choice;

    // Displaying all contacts
    display(root);

    // Menu
    do
    {
        printf("\n1.New contact\n2.Contacts list\n3.Exit\nEnter your choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1: // Create New Contacts
            do
            {
                printf("Contact Name : ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Replaces the newline with a null terminator

                printf("Phone Number : ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0'; // Replaces the newline with a null terminator

                root = create(root, name, phone);

                printf("Do you want to enter more contacts?(1/0) : ");
                scanf("%d", &choice);
                getchar(); // Removes the \n character typed from choice entering
            } while (choice == 1);
            break;
        case 2: // Display the cards
            display(root);
            break;
        case 3: // Exit from programme
            exit(0);
            break;
        default: // Invalud Input
            printf("Invalid Input");
        }
    } while (1);

    return 0;
}