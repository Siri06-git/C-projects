#include <stdio.h>
#include <string.h>

#define MAX 50

struct Order {
    int orderId;
    char customerName[50];
    char foodItem[50];
    float price;
};

struct Order queue[MAX];
int front = -1, rear = -1;
int nextOrderId = 1001;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void placeOrder() {
    if (isFull()) {
        printf("\nOrder queue is full!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;

    queue[rear].orderId = nextOrderId++;

    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", queue[rear].customerName);

    printf("Enter Food Item: ");
    scanf(" %[^\n]", queue[rear].foodItem);

    printf("Enter Price: ");
    scanf("%f", &queue[rear].price);

    printf("\nOrder placed successfully!");
    printf("\nOrder ID: %d\n", queue[rear].orderId);
}

void serveOrder() {
    if (isEmpty()) {
        printf("\nNo pending orders.\n");
        return;
    }

    printf("\nServing Order:");
    printf("\nOrder ID: %d", queue[front].orderId);
    printf("\nCustomer: %s", queue[front].customerName);
    printf("\nFood Item: %s\n", queue[front].foodItem);

    front++;
}

void displayOrders() {
    if (isEmpty()) {
        printf("\nNo pending orders.\n");
        return;
    }

    printf("\n--- Pending Orders ---\n");

    for (int i = front; i <= rear; i++) {
        printf("\nOrder ID: %d", queue[i].orderId);
        printf("\nCustomer: %s", queue[i].customerName);
        printf("\nFood Item: %s", queue[i].foodItem);
        printf("\nPrice: %.2f\n", queue[i].price);
    }
}

void searchOrder() {
    int id;

    printf("\nEnter Order ID to search: ");
    scanf("%d", &id);

    for (int i = front; i <= rear; i++) {
        if (queue[i].orderId == id) {
            printf("\nOrder Found!");
            printf("\nCustomer: %s", queue[i].customerName);
            printf("\nFood Item: %s", queue[i].foodItem);
            printf("\nPrice: %.2f\n", queue[i].price);
            return;
        }
    }

    printf("\nOrder not found!\n");
}

void sortOrdersByPrice() {
    struct Order temp;

    if (isEmpty()) {
        printf("\nNo orders to sort.\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (queue[i].price > queue[j].price) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    printf("\nOrders sorted by price successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n--- Online Food Order Management System ---");
        printf("\n1. Place Order");
        printf("\n2. Serve Order");
        printf("\n3. Display Pending Orders");
        printf("\n4. Search Order");
        printf("\n5. Sort Orders by Price");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: placeOrder(); break;
            case 2: serveOrder(); break;
            case 3: displayOrders(); break;
            case 4: searchOrder(); break;
            case 5: sortOrdersByPrice(); break;
            case 6: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }
}