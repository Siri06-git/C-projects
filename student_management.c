#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("\nStudent list is full!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d", students[i].id);
        printf("\nName: %s", students[i].name);
        printf("\nMarks: %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int id;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!");
            printf("\nID: %d", students[i].id);
            printf("\nName: %s", students[i].name);
            printf("\nMarks: %.2f\n", students[i].marks);
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void updateMarks() {
    int id;
    printf("\nEnter Student ID to update marks: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("\nMarks updated successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void deleteStudent() {
    int id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("\nStudent deleted successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n--- Student Management System ---");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Marks");
        printf("\n5. Delete Student");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateMarks(); break;
            case 5: deleteStudent(); break;
            case 6: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }
}
