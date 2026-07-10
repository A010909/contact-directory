#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contact-card structure
typedef struct card
{
    char name[30];
    char phone[11];
    struct card *next;
} card;

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

int main()
{
    char name[30];
    char phone[11];
    card *root = NULL;
    int choice;

    // Creating a new card
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

    // Displaying all contacts
    display(root);

    return 0;
}