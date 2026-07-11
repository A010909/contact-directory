#ifndef LIST_OPS_H
#define LIST_OPS_H

// Contact-card structure
typedef struct card
{
    char name[30];
    char phone[11];
    struct card *next;
} card;

// Add contacts prototype
card *create(card *root, char name[30], char phone[11]);
// Display Contacts prototype
void display(card *root);

#endif