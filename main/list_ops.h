#ifndef LIST_OPS_H
#define LIST_OPS_H

// Phone digits
#define DIGITS 12

// Contact-card structure
typedef struct card
{
    char name[30];
    char phone[DIGITS];
    struct card *next;
} card;

// Add contacts prototype
card *create(card *root, char name[30], char phone[DIGITS]);

// Display Contacts prototype
void display(card *root);

// Load contacts if exist, create if not
card *load(card *root);

// Saves new contacts from the linked list
card *save(card *root);

// Fress Allocated memory from malloc
void free_memory(card *root);

#endif