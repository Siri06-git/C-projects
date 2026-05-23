#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLS 20

struct Contact {
    char name[50];
    char phone[15];
    struct Contact *next;
};

struct Contact *head = NULL;

char callStack[MAX_CALLS][50];
int top = -1;

void addContact() {
    struct Contact *newContact = (struct Contact *)malloc(sizeof(struct Contact));

    printf("\nEnter Contact Name: ");
    scanf(" %[^\n]", newContact->name);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]", newContact->phone);

    newContact->next = head;
    head = newContact;

    printf("\nContact added successfully!\n");
}

void displayContacts() {
    struct Contact *temp = head;

    if (temp == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\n--- Contact List ---\n");

    while (temp != NULL) {
        printf("\nName: %s", temp->name);
        printf("\nPhone: %s\n", temp->phone);
        temp = temp->next;
    }
}

void searchContact() {
    char name[50];
    struct Contact *temp = head;

    printf("\nEnter name to search: ");
    scanf(" %[^\n]", name);

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("\nContact Found!");
            printf("\nName: %s", temp->name);
            printf("\nPhone: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }

    printf("\nContact not found!\n");
}

void deleteContact() {
    char name[50];
    struct Contact *temp = head;
    struct Contact *prev = NULL;

    printf("\nEnter name to delete: ");
    scanf(" %[^\n]", name);

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            printf("\nContact deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nContact not found!\n");
}

void makeCall() {
    char name[50];
    struct Contact *temp = head;

    printf("\nEnter contact name to call: ");
    scanf(" %[^\n]", name);

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (top == MAX_CALLS - 1) {
                printf("\nCall history is full!\n");
                return;
            }

            top++;
            strcpy(callStack[top], name);

            printf("\nCalling %s...\n", name);
            return;
        }

        temp = temp->next;
    }

    printf("\nContact not found!\n");
}

void viewRecentCalls() {
    if (top == -1) {
        printf("\nNo recent calls.\n");
        return;
    }

    printf("\n--- Recent Calls ---\n");

    for (int i = top; i >= 0; i--) {
        printf("%s\n", callStack[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n\n--- Smart Contact and Call Management System ---");
        printf("\n1. Add Contact");
        printf("\n2. Display Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Delete Contact");
        printf("\n5. Make Call");
        printf("\n6. View Recent Calls");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: makeCall(); break;
            case 6: viewRecentCalls(); break;
            case 7: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }
}