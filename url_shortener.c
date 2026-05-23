#include <stdio.h>
#include <string.h>

#define MAX 100

struct URL {
    char shortURL[20];
    char longURL[200];
};

struct URL table[MAX];
int count = 0;

char base62[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void generateShortURL(int num, char shortURL[]) {
    int i = 0;

    while (num > 0) {
        shortURL[i] = base62[num % 62];
        i++;
        num = num / 62;
    }

    shortURL[i] = '\0';
}

void shortenURL(char longURL[]) {
    char shortURL[20];

    if (count >= MAX) {
        printf("\nStorage full! Cannot shorten more URLs.\n");
        return;
    }

    generateShortURL(count + 1, shortURL);

    strcpy(table[count].shortURL, shortURL);
    strcpy(table[count].longURL, longURL);
    count++;

    printf("\nShort URL generated: %s\n", shortURL);
}

void retrieveURL(char shortURL[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(table[i].shortURL, shortURL) == 0) {
            printf("\nOriginal URL: %s\n", table[i].longURL);
            return;
        }
    }

    printf("\nShort URL not found!\n");
}

int main() {
    int choice;
    char longURL[200];
    char shortURL[20];

    while (1) {
        printf("\n\n--- URL Shortener Menu ---");
        printf("\n1. Shorten URL");
        printf("\n2. Retrieve URL");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Long URL: ");
                scanf("%199s", longURL);
                shortenURL(longURL);
                break;

            case 2:
                printf("\nEnter Short URL: ");
                scanf("%19s", shortURL);
                retrieveURL(shortURL);
                break;

            case 3:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
}