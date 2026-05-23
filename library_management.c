#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int available;
};

struct Book books[MAX];
int count = 0;

void addBook() {
    if (count >= MAX) {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    books[count].available = 1;
    count++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    if (count == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nBook ID: %d", books[i].id);
        printf("\nTitle: %s", books[i].title);
        printf("\nAuthor: %s", books[i].author);
        printf("\nStatus: %s\n", books[i].available ? "Available" : "Issued");
    }
}

void searchBook() {
    int id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!");
            printf("\nTitle: %s", books[i].title);
            printf("\nAuthor: %s", books[i].author);
            printf("\nStatus: %s\n", books[i].available ? "Available" : "Issued");
            return;
        }
    }

    printf("\nBook not found!\n");
}

void issueBook() {
    int id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].available) {
                books[i].available = 0;
                printf("\nBook issued successfully!\n");
            } else {
                printf("\nBook is already issued.\n");
            }
            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook() {
    int id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (!books[i].available) {
                books[i].available = 1;
                printf("\nBook returned successfully!\n");
            } else {
                printf("\nBook was not issued.\n");
            }
            return;
        }
    }

    printf("\nBook not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n--- Library Management System ---");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }
}