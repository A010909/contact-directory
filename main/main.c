#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_ops.h"

// Phone digits
#define DIGITS 12

int main()
{
    char name[30];
    char phone[DIGITS];
    card *root = NULL;
    int choice;

    // Load all the contacts
    root = load(root);

    // Displaying all contacts
    display(root);

    // Menu
    do
    {
        printf("\n1.New contact\n2.Delete Contact\n3.Contacts list\n4.Search contact by name\n5.Save and Exit\nEnter your choice : ");
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

                // Confirmation text
                printf("Contact Added Successfully\n");

                printf("Do you want to enter more contacts?(1/0) : ");
                scanf("%d", &choice);
                getchar(); // Removes the \n character typed from choice entering
            } while (choice == 1);
            break;
        case 2:
            if (root == NULL)
                printf("No Contacts");
            else
            {
                char d_name[30];
                printf("Name : ");
                fgets(d_name, sizeof(d_name), stdin);
                d_name[strcspn(d_name, "\n")] = '\0'; // Replaces the newline with a null terminator
                root = delete(root, d_name);
            }
            break;
        case 3: // Display the cards
            display(root);
            break;
        case 4:
            if (root == NULL)
                printf("No Contacts");
            else
            {
                char s_name[30];
                printf("Name : ");
                fgets(s_name, sizeof(s_name), stdin);
                s_name[strcspn(s_name, "\n")] = '\0'; // Replaces the newline with a null terminator
                search_by_name(root, s_name);
            }
            break;
        case 5: // Save and Exit from programme
            save(root);
            printf("Contacts saved successfully. Exiting...\n");
            free_memory(root);
            exit(0);
            break;
        default: // Invalud Input
            printf("Invalid Input");
        }
    } while (1);

    return 0;
}